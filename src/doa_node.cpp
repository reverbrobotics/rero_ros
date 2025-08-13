#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include "std_msgs/msg/int32.hpp"
#include <vector>
#include <deque>
#include <chrono>
#include <cstring>
#include <complex>
#include <cmath>
#include <algorithm>
#include "std_msgs/msg/bool.hpp"

bool voice_active_ = false;


class DOAProcessorNode : public rclcpp::Node
{
public:
    DOAProcessorNode() : Node("doa_processor")
    {
        this->declare_parameter("audio_topic", "/rero_ros/audio_stream");
        this->declare_parameter("doa_topic", "/doa/angle");
        this->declare_parameter("sample_rate", 16000);
        this->declare_parameter("num_channels", 4);
        this->declare_parameter("bytes_per_sample", 2);
        this->declare_parameter("frame_duration", 0.05);
        this->declare_parameter("mean_interval", 1.0);
        this->declare_parameter("energy_threshold", 1e-5);
        this->declare_parameter("speed_of_sound", 343.0);
        this->declare_parameter("mic_distance", 0.1);

        audio_topic_ = this->get_parameter("audio_topic").as_string();
        doa_topic_ = this->get_parameter("doa_topic").as_string();
        sample_rate_ = this->get_parameter("sample_rate").as_int();
        num_channels_ = this->get_parameter("num_channels").as_int();
        bytes_per_sample_ = this->get_parameter("bytes_per_sample").as_int();
        frame_duration_ = this->get_parameter("frame_duration").as_double();
        mean_interval_ = this->get_parameter("mean_interval").as_double();
        energy_threshold_ = this->get_parameter("energy_threshold").as_double();
        speed_of_sound_ = this->get_parameter("speed_of_sound").as_double();
        mic_distance_ = this->get_parameter("mic_distance").as_double();

        frame_size_ = static_cast<int>(sample_rate_ * frame_duration_);

        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
        subscriber_ = this->create_subscription<std_msgs::msg::ByteMultiArray>(
            audio_topic_, qos,
            std::bind(&DOAProcessorNode::audioCallback, this, std::placeholders::_1));

        publisher_ = this->create_publisher<std_msgs::msg::Int32>(doa_topic_, qos);
        vad_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
    "/vad_voice_detected", 10,
    [this](const std_msgs::msg::Bool::SharedPtr msg) {
        voice_active_ = msg->data;
    });

        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(static_cast<int>(mean_interval_ * 1000)),
            std::bind(&DOAProcessorNode::computeMeanDOA, this));
    }

private:

    void highPassFilter(std::vector<double>& signal, double cutoff, double fs)
        {
            if (signal.empty()) return;

            double rc = 1.0 / (2.0 * M_PI * cutoff);
            double dt = 1.0 / fs;
            double alpha = rc / (rc + dt);

            double prev_x = signal[0];
            double prev_y = signal[0];

            for (size_t i = 1; i < signal.size(); i++) {
                double x = signal[i];
                double y = alpha * (prev_y + x - prev_x);
                signal[i] = y;
                prev_x = x;
                prev_y = y;
            }
        }
    void fft(std::vector<std::complex<double>>& x, bool invert = false)
    {
        size_t n = x.size();
        if (n <= 1) return;

        for (size_t i = 1, j = 0; i < n; i++) {
            size_t bit = n >> 1;
            for (; j & bit; bit >>= 1) {
                j ^= bit;
            }
            j ^= bit;
            if (i < j) std::swap(x[i], x[j]);
        }

        for (size_t len = 2; len <= n; len <<= 1) {
            double ang = 2 * M_PI / len * (invert ? -1 : 1);
            std::complex<double> wlen(std::cos(ang), std::sin(ang));
            for (size_t i = 0; i < n; i += len) {
                std::complex<double> w(1);
                for (size_t j = 0; j < len / 2; j++) {
                    std::complex<double> u = x[i + j];
                    std::complex<double> v = x[i + j + len / 2] * w;
                    x[i + j] = u + v;
                    x[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (auto& xi : x) {
                xi /= n;
            }
        }
    }

    std::vector<std::complex<double>> rfft(const std::vector<double>& signal, size_t n = 0)
    {
        if (n == 0) n = signal.size();
        
        std::vector<std::complex<double>> x(n);
        for (size_t i = 0; i < signal.size() && i < n; i++) {
            x[i] = std::complex<double>(signal[i], 0.0);
        }
        
        fft(x);
        
        size_t half_n = n / 2 + 1;
        return std::vector<std::complex<double>>(x.begin(), x.begin() + half_n);
    }

    std::vector<double> irfft(const std::vector<std::complex<double>>& spectrum, size_t n)
    {
        std::vector<std::complex<double>> x(n);
        
        for (size_t i = 0; i < spectrum.size() && i < n/2 + 1; i++) {
            x[i] = spectrum[i];
        }
        
        for (size_t i = 1; i < n/2; i++) {
            x[n - i] = std::conj(spectrum[i]);
        }
        
        fft(x, true);
        
        std::vector<double> result(n);
        for (size_t i = 0; i < n; i++) {
            result[i] = x[i].real();
        }
        
        return result;
    }

    double gccPhat(const std::vector<double>& sig1, const std::vector<double>& sig2, double fs)
    {
        size_t n = sig1.size() + sig2.size();
        
        size_t fft_size = 1;
        while (fft_size < n) fft_size <<= 1;
        
        auto SIG1 = rfft(sig1, fft_size);
        auto SIG2 = rfft(sig2, fft_size);
        
        std::vector<std::complex<double>> R(SIG1.size());
        for (size_t i = 0; i < SIG1.size(); i++) {
            R[i] = SIG1[i] * std::conj(SIG2[i]);
            double magnitude = std::abs(R[i]);
            if (magnitude > 1e-15) {
                R[i] /= magnitude;
            }
        }
        
        auto cross_correlation = irfft(R, fft_size);
        
        size_t max_shift = fft_size / 2;
        
        std::vector<double> cc_rearranged(fft_size);
        for (size_t i = 0; i < max_shift; i++) {
            cc_rearranged[i] = cross_correlation[max_shift + i];
        }
        for (size_t i = max_shift; i < fft_size; i++) {
            cc_rearranged[i] = cross_correlation[i - max_shift];
        }
        
        auto max_it = std::max_element(cc_rearranged.begin(), cc_rearranged.end(),
            [](double a, double b) { return std::abs(a) < std::abs(b); });
        
        int shift = static_cast<int>(max_it - cc_rearranged.begin()) - static_cast<int>(max_shift);
        double tdoa = static_cast<double>(shift) / fs;
        
        return tdoa;
    }

    double estimateDOA(const std::vector<std::vector<double>>& mic_signals, double fs)
    {
        if (mic_signals.size() < 4) {
            return std::numeric_limits<double>::quiet_NaN();
        }

        const auto& s1 = mic_signals[0];
        const auto& s2 = mic_signals[1];
        const auto& s3 = mic_signals[2];
        const auto& s4 = mic_signals[3];

        double tau_ns = gccPhat(s1, s3, fs);
        double tau_ew = gccPhat(s2, s4, fs);

        double x = speed_of_sound_ * tau_ew / (2.0 * mic_distance_);
        double y = speed_of_sound_ * tau_ns / (2.0 * mic_distance_);

        double angle_rad = std::atan2(y, x);
        double angle_deg = (angle_rad * 180.0 / M_PI - 90.0);
        
        while (angle_deg < 0) angle_deg += 360.0;
        while (angle_deg >= 360) angle_deg -= 360.0;
        
        return angle_deg;
    }

    double circularMean(const std::vector<double>& angles_deg)
    {
        if (angles_deg.empty()) {
            return std::numeric_limits<double>::quiet_NaN();
        }

        double sum_sin = 0.0;
        double sum_cos = 0.0;

        for (double angle : angles_deg) {
            double angle_rad = angle * M_PI / 180.0;
            sum_sin += std::sin(angle_rad);
            sum_cos += std::cos(angle_rad);
        }

        double mean_sin = sum_sin / angles_deg.size();
        double mean_cos = sum_cos / angles_deg.size();
        
        double mean_angle_rad = std::atan2(mean_sin, mean_cos);
        double mean_angle_deg = mean_angle_rad * 180.0 / M_PI;
        
        while (mean_angle_deg < 0) mean_angle_deg += 360.0;
        while (mean_angle_deg >= 360) mean_angle_deg -= 360.0;
        
        return mean_angle_deg;
    }

    void audioCallback(const std_msgs::msg::ByteMultiArray::SharedPtr msg)
    {
        try {


            size_t num_samples = msg->data.size() / bytes_per_sample_;
            if (num_samples % num_channels_ != 0) {
                return;
            }

            size_t samples_per_channel = num_samples / num_channels_;
            
            if (samples_per_channel < 64) {
                return;
            }

            std::vector<std::vector<double>> channels(num_channels_);
            for (int ch = 0; ch < num_channels_; ch++) {
                channels[ch].resize(samples_per_channel);
            }

            const int16_t* samples = reinterpret_cast<const int16_t*>(msg->data.data());
            for (size_t i = 0; i < samples_per_channel; i++) {
                for (int ch = 0; ch < num_channels_; ch++) {
                    channels[ch][i] = static_cast<double>(samples[i * num_channels_ + ch]) / 32768.0;
                }
            }

            double max_energy = 0.0;
            for (int ch = 0; ch < num_channels_; ch++) {
                double energy = 0.0;
                for (double sample : channels[ch]) {
                    energy += sample * sample;
                }
                energy /= channels[ch].size();
                max_energy = std::max(max_energy, energy);
            }

            if (max_energy < energy_threshold_) {
                return;
            }
            if (!voice_active_) {
                return; 
            }
            for (auto &channel : channels) {
                highPassFilter(channel, 150.0, sample_rate_);
            }

            double doa = estimateDOA(channels, static_cast<double>(sample_rate_));
            
            if (!std::isnan(doa)) {
                doa_buffer_.push_back(doa);
            }

        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Error processing audio: %s", e.what());
        }
    }

    void computeMeanDOA()
    {
        if (doa_buffer_.empty()) {
            return;
        }

        try {
            double mean_doa = circularMean(std::vector<double>(doa_buffer_.begin(), doa_buffer_.end()));
            
            if (!std::isnan(mean_doa)) {
                auto msg = std_msgs::msg::Int32();
                msg.data = static_cast<int32_t>(std::round(mean_doa));
                publisher_->publish(msg);
            }
            
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Error computing mean DOA: %s", e.what());
        }

        doa_buffer_.clear();
    }
    rclcpp::Subscription<std_msgs::msg::ByteMultiArray>::SharedPtr subscriber_;
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr vad_subscriber_;

    rclcpp::TimerBase::SharedPtr timer_;
    std::string audio_topic_;
    std::string doa_topic_;
    int sample_rate_;
    int num_channels_;
    int bytes_per_sample_;
    double frame_duration_;
    double mean_interval_;
    double energy_threshold_;
    double speed_of_sound_;
    double mic_distance_;
    int frame_size_;
    std::deque<double> doa_buffer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<DOAProcessorNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}