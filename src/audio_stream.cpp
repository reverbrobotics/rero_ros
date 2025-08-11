#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/byte_multi_array.hpp"
#include <grpcpp/grpcpp.h>
#include <AudioClient.h>
#include <chrono>
#include <thread>
#include <memory>

class AudioClientStreamNode : public rclcpp::Node
{
public:
    AudioClientStreamNode() : Node("audio_client_stream")
    {
        this->declare_parameter("grpc_host", "localhost");
        this->declare_parameter("grpc_port", "50052");
        this->declare_parameter("topic_name", "/rero_ros/audio_stream");
        this->declare_parameter("sample_rate", 16000);
        this->declare_parameter("num_channels", 1);
        this->declare_parameter("format", "paInt16");
        this->declare_parameter("frames_per_buffer", 1024);
        this->declare_parameter("bytes_per_sample", 2);
        this->declare_parameter("ringbuffer_size", 10);

        grpc_host_ = this->get_parameter("grpc_host").as_string();
        grpc_port_ = this->get_parameter("grpc_port").as_string();
        topic_name_ = this->get_parameter("topic_name").as_string();
        sample_rate_ = this->get_parameter("sample_rate").as_int();
        num_channels_ = this->get_parameter("num_channels").as_int();
        format_ = this->get_parameter("format").as_string();
        frames_per_buffer_ = this->get_parameter("frames_per_buffer").as_int();
        bytes_per_sample_ = this->get_parameter("bytes_per_sample").as_int();
        ringbuffer_size_ = this->get_parameter("ringbuffer_size").as_int();


        if (grpc_host_.empty() || grpc_port_.empty() || topic_name_.empty()) {
            RCLCPP_ERROR(this->get_logger(), "One or more required parameters are empty. Shutting down.");
            rclcpp::shutdown();
            return;
        }
        if (sample_rate_ <= 0 || num_channels_ <= 0 || 
            frames_per_buffer_ <= 0 || bytes_per_sample_ <= 0 || ringbuffer_size_ <= 0) {
            RCLCPP_ERROR(this->get_logger(), "Invalid audio parameters. Shutting down.");
            rclcpp::shutdown();
            return;
        }


        std::string address = grpc_host_ + ":" + grpc_port_;
        RCLCPP_INFO(this->get_logger(), "Connecting to gRPC server at %s", address.c_str());
        audio_channel_ = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());

        client_ = std::make_unique<AudioClient>(
            audio_channel_, sample_rate_, num_channels_, format_,
            frames_per_buffer_, bytes_per_sample_, ringbuffer_size_);

   
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
        rclcpp::PublisherOptions options;
        options.use_intra_process_comm = rclcpp::IntraProcessSetting::Disable;
        publisher_ = this->create_publisher<std_msgs::msg::ByteMultiArray>(topic_name_, qos, options);

  
        client_->StreamAudioAsync();
        RCLCPP_INFO(this->get_logger(), "Started streaming audio from server to topic %s", topic_name_.c_str());


        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000 * frames_per_buffer_ / sample_rate_),
            std::bind(&AudioClientStreamNode::publishAudio, this));
    }

    ~AudioClientStreamNode()
    {
        if (client_) {
            client_->StopStream();
        }
    }

private:
    void publishAudio()
    {

        if (audio_channel_->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
            RCLCPP_WARN(this->get_logger(), "Cannot connect to gRPC server. Retrying...");
            return;
        }

        try {
            if (!client_->isStreaming()) {
                RCLCPP_WARN(this->get_logger(), "Streaming stopped. Shutting down.");
                rclcpp::shutdown();
                return;
            }

            char* buffer = client_->GetBuffer();
            uint32_t num_bytes = client_->getNumBytes();


            if (!buffer || num_bytes == 0) {
                RCLCPP_WARN(this->get_logger(), "Invalid buffer or zero bytes received.");
                return;
            }

  
            auto msg = std::make_shared<std_msgs::msg::ByteMultiArray>();
            msg->data.resize(num_bytes);
            std::memcpy(msg->data.data(), buffer, num_bytes);

            publisher_->publish(*msg);
            RCLCPP_DEBUG(this->get_logger(), "Published %u bytes of audio data to %s", num_bytes, topic_name_.c_str());

        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to publish audio: %s", e.what());
            client_->StopStream();
            rclcpp::shutdown();
        }
    }

    std::unique_ptr<AudioClient> client_;
    std::shared_ptr<grpc::Channel> audio_channel_;
    rclcpp::Publisher<std_msgs::msg::ByteMultiArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string grpc_host_;
    std::string grpc_port_;
    std::string topic_name_;
    int sample_rate_;
    int num_channels_;
    std::string format_;
    int frames_per_buffer_;
    int bytes_per_sample_;
    int ringbuffer_size_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AudioClientStreamNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}