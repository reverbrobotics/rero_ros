#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <grpcpp/grpcpp.h>
#include <AudioClient.h>
#include <SpeechRecognitionClient.h>
#include "json.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;

using rero::StreamRequest;
using rero::AudioStreamer;
using rero::Audio;

#include <memory>
#include <sstream>

/**
 * ROS2 node for streaming audio to a gRPC speech recognition service and publishing results.
 */
class ReroSpeechRecognitionNode : public rclcpp::Node
{
public:
    ReroSpeechRecognitionNode() : Node("rero_speech_recognition")
    {
        this->declare_parameter("core_host", "localhost");
        this->declare_parameter("core_port", "50051");
        this->declare_parameter("topic_name", "speech_recognition");

        // Assign to member variables, not new local variables
        grpc_host = this->get_parameter("core_host").as_string();
        grpc_port = this->get_parameter("core_port").as_string();
        topic_name = this->get_parameter("topic_name").as_string();

        // Validate parameters
        if (grpc_host.empty() || grpc_port.empty() || topic_name.empty()) {
            RCLCPP_ERROR(this->get_logger(), "One or more parameters are empty. Shutting down.");
            rclcpp::shutdown();
            return;
        }

        std::string address = grpc_host + ":" + grpc_port;
        RCLCPP_INFO(this->get_logger(), "gRPC Address: %s", address.c_str());
        RCLCPP_INFO(this->get_logger(), "Publishing to topic: %s", topic_name.c_str());

        // Initialize gRPC channels
        audio_channel_ = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
        sr_channel_ = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
        hw_channel_ = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());

        client_ = std::make_unique<SpeechRecognitionClient>(audio_channel_, sr_channel_,hw_channel_);


        // Create publisher with QoS settings
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
        publisher_ = this->create_publisher<std_msgs::msg::String>(topic_name, qos);

        // Start timer for periodic processing
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), // 10 Hz
            std::bind(&ReroSpeechRecognitionNode::processAudio, this));
    }

private:
    void processAudio()
    {
        // Check gRPC channel state
        if (audio_channel_->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE ||
            sr_channel_->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
            RCLCPP_WARN(this->get_logger(), "gRPC cannot communicate with ReroCore Audio Server. Retrying...");
            return;
        }

        try {
            // Stream audio and get speech recognition result
            SpeechRecognitionResult result = client_->StreamAudio();

            if (result.result().empty()) {
                RCLCPP_DEBUG(this->get_logger(), "Empty speech recognition result. Skipping.");
                return;
            }

            // Parse JSON result
            json::JSON resultObject = json::JSON::Load(result.result());
            if (!resultObject.hasKey("text")) {
                RCLCPP_WARN(this->get_logger(), "No 'text' field in JSON result. Skipping.");
                return;
            }

            // Create and publish message
            std_msgs::msg::String msg;
            msg.data = resultObject["text"].ToString();
            RCLCPP_INFO(this->get_logger(), "Speech recognition result: %s", msg.data.c_str());
            publisher_->publish(msg);
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to process speech recognition: %s", e.what());
        }
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::unique_ptr<SpeechRecognitionClient> client_;
    std::shared_ptr<grpc::Channel> audio_channel_;
    std::shared_ptr<grpc::Channel> sr_channel_;
    std::shared_ptr<grpc::Channel> hw_channel_;
    std::string grpc_host;
    std::string grpc_port;
    std::string topic_name;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ReroSpeechRecognitionNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}