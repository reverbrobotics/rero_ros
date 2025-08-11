#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <grpcpp/grpcpp.h>
#include <TTSClient.h>
#include "json.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;

using rero::TextToSpeech;
using rero::TTSRequest;
using rero::TTSResponse;

#include <memory>
#include <sstream>

/**
 * ROS2 node for subscribing to text messages and processing them with a gRPC TTS service.
 */
class ReroTTSNode : public rclcpp::Node
{
public:
    ReroTTSNode() : Node("rero_tts")
    {
        // Declare parameters with default values
        this->declare_parameter("core_host", "localhost");
        this->declare_parameter("core_port", "50053");
        this->declare_parameter("input_topic_name", "tts_input");

        // Get parameters
        grpc_host_ = this->get_parameter("core_host").as_string();
        grpc_port_ = this->get_parameter("core_port").as_string();
        input_topic_name_ = this->get_parameter("input_topic_name").as_string();

        // Validate parameters
        if (grpc_host_.empty() || grpc_port_.empty() || input_topic_name_.empty()) {
            RCLCPP_ERROR(this->get_logger(), "One or more parameters are empty. Shutting down.");
            rclcpp::shutdown();
            return;
        }

        std::string address = grpc_host_ + ":" + grpc_port_;
        RCLCPP_INFO(this->get_logger(), "gRPC Address: %s", address.c_str());
        RCLCPP_INFO(this->get_logger(), "Subscribing to topic: %s", input_topic_name_.c_str());

        // Initialize gRPC channel
        tts_channel_ = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
        client_ = std::make_unique<TTSClient>(tts_channel_);

        // Check gRPC channel state
        if (tts_channel_->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
            RCLCPP_WARN(this->get_logger(), "gRPC cannot communicate with ReroCore TTS Server. Retrying...");
        }

        // Create subscriber with QoS settings
        auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable();
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            input_topic_name_, qos,
            std::bind(&ReroTTSNode::ttsCallback, this, std::placeholders::_1));
    }

private:
    void ttsCallback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received text: %s", msg->data.c_str());

        // Skip empty messages
        if (msg->data.empty()) {
            RCLCPP_WARN(this->get_logger(), "Received empty text message. Skipping.");
            return;
        }

        // Check gRPC channel state
        if (tts_channel_->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
            RCLCPP_WARN(this->get_logger(), "gRPC cannot communicate with ReroCore TTS Server. Skipping.");
            return;
        }

        try {
            // Process text with TTS client
            TTSResponse response = client_->TTS(msg->data);
            RCLCPP_INFO(this->get_logger(), "TTS processing completed for text: %s", msg->data.c_str());
        } catch (const std::exception& e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to process TTS: %s", e.what());
        }
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    std::unique_ptr<TTSClient> client_;
    std::shared_ptr<grpc::Channel> tts_channel_;
    std::string grpc_host_;
    std::string grpc_port_;
    std::string input_topic_name_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ReroTTSNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}