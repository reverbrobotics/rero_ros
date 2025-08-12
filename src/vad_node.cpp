#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/bool.hpp"
#include <onnxruntime_cxx_api.h>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <cmath>

enum class VadStateType {
    SILENCE,
    VOICE,
    SILENCE_PENDING
};

class Vad {
    static constexpr size_t SIZE_HC = 128;
    static constexpr size_t SupportedChannelCount = 1;
    static constexpr size_t SupportedSamplingFrequency = 16000;
    static constexpr size_t SupportedFrameSampleCount = 512;

    float m_silenceToVoiceThreshold;
    float m_voiceToSilenceThreshold;
    size_t m_minSilenceFrameCount;

    std::vector<float> m_packedAudioFrame;
    Ort::Env m_env;
    Ort::SessionOptions m_sessionOptions;
    std::unique_ptr<Ort::Session> m_session;
    Ort::MemoryInfo m_cpuMemoryInfo;

    std::vector<const char*> m_ortInputsNames;
    std::vector<Ort::Value> m_ortInputs;
    std::vector<int64_t> m_inputShape;
    std::vector<int64_t> m_sr;
    std::vector<int64_t> m_srShape;
    std::vector<float> m_h;
    std::vector<float> m_c;
    std::vector<int64_t> m_hcShape;
    std::vector<const char*> m_ortOutputsNames;

    VadStateType m_stateType;
    size_t m_frameIndex;
    size_t m_silenceFrameIndex;

public:
    Vad(const std::string& modelPath, float silenceToVoiceThreshold, float voiceToSilenceThreshold, size_t minSilenceFrameCount)
        : m_silenceToVoiceThreshold(silenceToVoiceThreshold),
          m_voiceToSilenceThreshold(voiceToSilenceThreshold),
          m_minSilenceFrameCount(minSilenceFrameCount),
          m_packedAudioFrame(SupportedFrameSampleCount),
          m_cpuMemoryInfo(nullptr),
          m_ortInputsNames({"input", "sr", "h", "c"}),
          m_inputShape({1, SupportedFrameSampleCount}),
          m_sr({SupportedSamplingFrequency}),
          m_srShape({1}),
          m_h(SIZE_HC),
          m_c(SIZE_HC),
          m_hcShape({2, 1, 64}),
          m_ortOutputsNames({"output", "hn", "cn"}) {
        
        m_sessionOptions.SetInterOpNumThreads(1);
        m_sessionOptions.SetIntraOpNumThreads(1);
        m_sessionOptions.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
        m_sessionOptions.SetExecutionMode(ExecutionMode::ORT_SEQUENTIAL);
        m_sessionOptions.SetLogSeverityLevel(ORT_LOGGING_LEVEL_WARNING);

        try {
            m_session = std::make_unique<Ort::Session>(m_env, modelPath.c_str(), m_sessionOptions);
            std::cout << "Successfully loaded ONNX model from: " << modelPath << std::endl;
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to load ONNX model from '" + modelPath + "': " + e.what());
        }
        
        m_cpuMemoryInfo = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
        reset();
    }

    void reset() {
        std::memset(m_h.data(), 0, m_h.size() * sizeof(float));
        std::memset(m_c.data(), 0, m_c.size() * sizeof(float));
        m_stateType = VadStateType::SILENCE;
        m_frameIndex = 0;
        m_silenceFrameIndex = 0;
    }

    std::tuple<bool, float, float> detect(const std::vector<float>& audioFrame) {
        if (audioFrame.size() != SupportedFrameSampleCount) {
            throw std::runtime_error("Invalid frame size: expected " + std::to_string(SupportedFrameSampleCount) +
                                     ", got " + std::to_string(audioFrame.size()));
        }

        // Calculate RMS to see if we have actual audio signal
        float rms = 0.0f;
        for (float sample : audioFrame) {
            rms += sample * sample;
        }
        rms = std::sqrt(rms / audioFrame.size());

        m_packedAudioFrame = audioFrame;
        m_ortInputs.clear();
        m_ortInputs.emplace_back(Ort::Value::CreateTensor<float>(
            m_cpuMemoryInfo, m_packedAudioFrame.data(), m_packedAudioFrame.size(),
            m_inputShape.data(), m_inputShape.size()));
        m_ortInputs.emplace_back(Ort::Value::CreateTensor<int64_t>(
            m_cpuMemoryInfo, m_sr.data(), m_sr.size(), m_srShape.data(), m_srShape.size()));
        m_ortInputs.emplace_back(Ort::Value::CreateTensor<float>(
            m_cpuMemoryInfo, m_h.data(), m_h.size(), m_hcShape.data(), m_hcShape.size()));
        m_ortInputs.emplace_back(Ort::Value::CreateTensor<float>(
            m_cpuMemoryInfo, m_c.data(), m_c.size(), m_hcShape.data(), m_hcShape.size()));

        std::vector<Ort::Value> ortOutputs = m_session->Run(
            Ort::RunOptions{nullptr}, m_ortInputsNames.data(), m_ortInputs.data(),
            m_ortInputs.size(), m_ortOutputsNames.data(), m_ortOutputsNames.size());
        
        float voiceProbability = ortOutputs[0].GetTensorMutableData<float>()[0];
        float* hn = ortOutputs[1].GetTensorMutableData<float>();
        std::memcpy(m_h.data(), hn, m_h.size() * sizeof(float));
        float* cn = ortOutputs[2].GetTensorMutableData<float>();
        std::memcpy(m_c.data(), cn, m_c.size() * sizeof(float));

        bool voiceDetected = updateState(voiceProbability);
        return {voiceDetected, voiceProbability, rms};
    }

    const char* getStateString() const {
        switch (m_stateType) {
            case VadStateType::SILENCE: return "SILENCE";
            case VadStateType::VOICE: return "VOICE";
            case VadStateType::SILENCE_PENDING: return "SILENCE_PENDING";
            default: return "UNKNOWN";
        }
    }

    float getSilenceToVoiceThreshold() const { return m_silenceToVoiceThreshold; }
    float getVoiceToSilenceThreshold() const { return m_voiceToSilenceThreshold; }
    size_t getMinSilenceFrameCount() const { return m_minSilenceFrameCount; }

private:
    bool updateState(float voiceProbability) {
        m_frameIndex++;

        if (m_stateType == VadStateType::SILENCE && voiceProbability > m_silenceToVoiceThreshold) {
            m_stateType = VadStateType::VOICE;
        }
        else if (m_stateType == VadStateType::VOICE && voiceProbability < m_voiceToSilenceThreshold) {
            m_stateType = VadStateType::SILENCE_PENDING;
            m_silenceFrameIndex = m_frameIndex;
        }
        else if (m_stateType == VadStateType::SILENCE_PENDING && voiceProbability > m_voiceToSilenceThreshold) {
            m_stateType = VadStateType::VOICE;
        }
        else if (m_stateType == VadStateType::SILENCE_PENDING &&
                 (m_frameIndex - m_silenceFrameIndex) > m_minSilenceFrameCount) {
            m_stateType = VadStateType::SILENCE;
        }

        switch (m_stateType) {
            case VadStateType::SILENCE:
                return false;
            case VadStateType::VOICE:
            case VadStateType::SILENCE_PENDING:
                return true;
            default:
                return false;
        }
    }
};

class VadNode : public rclcpp::Node {
public:
    VadNode() : Node("vad_node") {
        declare_parameter("audio_topic", "/rero_ros/audio_stream");
        declare_parameter("voice_detected_topic", "/vad_voice_detected");
        declare_parameter("model_path", "/home/turtle/ws/rero_ros/models/vad/silero_vad.onnx");
        declare_parameter("silence_to_voice_threshold", 0.35);  // Lower threshold
        declare_parameter("voice_to_silence_threshold", 0.25);  // Lower threshold
        declare_parameter("min_silence_duration_ms", 200);      // Shorter duration
        declare_parameter("debug_every_n_frames", 10);          // More frequent debug
        declare_parameter("num_channels", 4);
        declare_parameter("audio_gain", 3.0);                   // Audio gain multiplier
        declare_parameter("enable_audio_stats", true);          // Enable volume analysis
        declare_parameter("volume_analysis_frames", 100);       // Analyze volume every N frames

        audio_topic_ = get_parameter("audio_topic").as_string();
        voice_detected_topic_ = get_parameter("voice_detected_topic").as_string();
        model_path_ = get_parameter("model_path").as_string();
        silence_to_voice_threshold_ = static_cast<float>(get_parameter("silence_to_voice_threshold").as_double());
        voice_to_silence_threshold_ = static_cast<float>(get_parameter("voice_to_silence_threshold").as_double());
        min_silence_duration_ms_ = get_parameter("min_silence_duration_ms").as_int();
        debug_every_n_frames_ = get_parameter("debug_every_n_frames").as_int();
        num_channels_ = get_parameter("num_channels").as_int();
        audio_gain_ = static_cast<float>(get_parameter("audio_gain").as_double());
        enable_audio_stats_ = get_parameter("enable_audio_stats").as_bool();
        volume_analysis_frames_ = get_parameter("volume_analysis_frames").as_int();

        size_t min_silence_frames = static_cast<size_t>(min_silence_duration_ms_ * 16000 / 1000 / 512);

        try {
            vad_ = std::make_unique<Vad>(
                model_path_,
                silence_to_voice_threshold_, 
                voice_to_silence_threshold_,
                min_silence_frames);
                
            RCLCPP_INFO(get_logger(), "VAD initialized successfully:");
            RCLCPP_INFO(get_logger(), "  Model: %s", model_path_.c_str());
            RCLCPP_INFO(get_logger(), "  Audio channels: %d", num_channels_);
            RCLCPP_INFO(get_logger(), "  Audio gain: %.1fx", audio_gain_);
            RCLCPP_INFO(get_logger(), "  Silence->Voice threshold: %.3f", silence_to_voice_threshold_);
            RCLCPP_INFO(get_logger(), "  Voice->Silence threshold: %.3f", voice_to_silence_threshold_);
            RCLCPP_INFO(get_logger(), "  Min silence frames: %zu", min_silence_frames);
            
        } catch (const std::exception& e) {
            RCLCPP_ERROR(get_logger(), "Failed to initialize VAD: %s", e.what());
            rclcpp::shutdown();
            return;
        }

        auto qos = rclcpp::QoS(rclcpp::KeepLast(100)).reliable();
        subscription_ = create_subscription<std_msgs::msg::ByteMultiArray>(
            audio_topic_, qos,
            std::bind(&VadNode::audioCallback, this, std::placeholders::_1));
        publisher_ = create_publisher<std_msgs::msg::Bool>(voice_detected_topic_, qos);
        
        RCLCPP_INFO(get_logger(), "VAD Node ready - listening on %s", audio_topic_.c_str());
    }

private:
    void audioCallback(const std_msgs::msg::ByteMultiArray::SharedPtr msg) {
        if (msg->data.empty()) {
            RCLCPP_WARN(get_logger(), "Received empty audio message.");
            return;
        }

        // Convert byte array to float samples (16-bit PCM)
        std::vector<float> audio_frame_multi;
        size_t num_samples_total = msg->data.size() / 2;
        audio_frame_multi.reserve(num_samples_total);
        
        for (size_t i = 0; i < msg->data.size(); i += 2) {
            if (i + 1 >= msg->data.size()) break;
            int16_t sample = static_cast<int16_t>(msg->data[i]) | 
                           (static_cast<int16_t>(msg->data[i + 1]) << 8);
            audio_frame_multi.push_back(static_cast<float>(sample) / 32768.0f);
        }

        // Convert multi-channel to mono and apply gain
        std::vector<float> audio_frame_mono;
        if (num_channels_ == 1) {
            audio_frame_mono = std::move(audio_frame_multi);
        } else {
            size_t num_mono_samples = audio_frame_multi.size() / num_channels_;
            audio_frame_mono.reserve(num_mono_samples);
            
            for (size_t i = 0; i < num_mono_samples; i++) {
                float sum = 0.0f;
                for (int ch = 0; ch < num_channels_; ch++) {
                    sum += audio_frame_multi[i * num_channels_ + ch];
                }
                audio_frame_mono.push_back(sum / num_channels_);
            }
        }

        // Apply gain and clamp to prevent clipping
        for (float& sample : audio_frame_mono) {
            sample *= audio_gain_;
            sample = std::clamp(sample, -1.0f, 1.0f);  // Prevent clipping
        }

        // Audio statistics
        if (enable_audio_stats_) {
            updateAudioStats(audio_frame_mono);
        }

        // Log first message details
        static bool first_msg = true;
        if (first_msg) {
            first_msg = false;
            RCLCPP_INFO(get_logger(), "First audio message:");
            RCLCPP_INFO(get_logger(), "  Raw bytes: %zu", msg->data.size());
            RCLCPP_INFO(get_logger(), "  Multi-channel samples: %zu", audio_frame_multi.size());
            RCLCPP_INFO(get_logger(), "  Mono samples: %zu", audio_frame_mono.size());
            RCLCPP_INFO(get_logger(), "  Channels: %d", num_channels_);
            if (!audio_frame_mono.empty()) {
                float min_val = *std::min_element(audio_frame_mono.begin(), audio_frame_mono.end());
                float max_val = *std::max_element(audio_frame_mono.begin(), audio_frame_mono.end());
                float rms = 0.0f;
                for (float sample : audio_frame_mono) {
                    rms += sample * sample;
                }
                rms = std::sqrt(rms / audio_frame_mono.size());
                RCLCPP_INFO(get_logger(), "  After gain: range=[%.6f, %.6f], RMS=%.6f", min_val, max_val, rms);
            }
        }

        // Buffer audio and process in 512-sample chunks
        audio_buffer_.insert(audio_buffer_.end(), audio_frame_mono.begin(), audio_frame_mono.end());
        
        while (audio_buffer_.size() >= 512) {
            std::vector<float> chunk(audio_buffer_.begin(), audio_buffer_.begin() + 512);
            audio_buffer_.erase(audio_buffer_.begin(), audio_buffer_.begin() + 512);
            
            try {
                auto [voice_detected, confidence, rms] = vad_->detect(chunk);
                
                // Debug logging
                frame_count_++;
                if (debug_every_n_frames_ > 0 && frame_count_ % debug_every_n_frames_ == 0) {
                    RCLCPP_INFO(get_logger(), 
                               "Frame %d: RMS=%.5f, Conf=%.4f (thresh: %.3f/%.3f), State=%s, Voice=%s", 
                               frame_count_, rms, confidence, 
                               vad_->getSilenceToVoiceThreshold(), 
                               vad_->getVoiceToSilenceThreshold(),
                               vad_->getStateString(), 
                               voice_detected ? "YES" : "NO");
                }
                
                // Publish result for each processed chunk
                std_msgs::msg::Bool voice_msg;
                voice_msg.data = voice_detected;
                publisher_->publish(voice_msg);
                
            } catch (const std::exception& e) {
                RCLCPP_ERROR(get_logger(), "VAD processing failed: %s", e.what());
                return;
            }
        }
    }

    void updateAudioStats(const std::vector<float>& audio_samples) {
        for (float sample : audio_samples) {
            rms_accumulator_ += sample * sample;
            max_amplitude_ = std::max(max_amplitude_, std::abs(sample));
        }
        sample_count_ += audio_samples.size();
        
        if (frame_count_ % volume_analysis_frames_ == 0 && sample_count_ > 0) {
            float avg_rms = std::sqrt(rms_accumulator_ / sample_count_);
            RCLCPP_INFO(get_logger(), 
                       "Audio Stats (last %d frames): Avg RMS=%.6f, Max Amplitude=%.6f", 
                       volume_analysis_frames_, avg_rms, max_amplitude_);
            
            // Suggest gain adjustments
            if (avg_rms < 0.001f) {
                RCLCPP_WARN(get_logger(), "Very low audio levels detected! Consider increasing audio_gain parameter.");
            } else if (avg_rms < 0.01f) {
                RCLCPP_WARN(get_logger(), "Low audio levels detected. Current gain: %.1fx", audio_gain_);
            }
            
            // Reset stats
            rms_accumulator_ = 0.0f;
            max_amplitude_ = 0.0f;
            sample_count_ = 0;
        }
    }

    std::unique_ptr<Vad> vad_;
    rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr subscription_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr publisher_;
    std::string audio_topic_;
    std::string voice_detected_topic_;
    std::string model_path_;
    float silence_to_voice_threshold_;
    float voice_to_silence_threshold_;
    int min_silence_duration_ms_;
    int debug_every_n_frames_;
    int num_channels_;
    float audio_gain_;
    bool enable_audio_stats_;
    int volume_analysis_frames_;
    int frame_count_ = 0;
    std::vector<float> audio_buffer_;
    
    // Audio statistics
    float rms_accumulator_ = 0.0f;
    float max_amplitude_ = 0.0f;
    size_t sample_count_ = 0;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    try {
        auto node = std::make_shared<VadNode>();
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("vad_node"), "Exception: %s", e.what());
        rclcpp::shutdown();
        return -1;
    }
    rclcpp::shutdown();
    return 0;
}