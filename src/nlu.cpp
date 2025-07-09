#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <grpcpp/grpcpp.h>
#include <NLUClient.h>
#include "rero_ros/msg/intent.hpp"
#include "rero_ros/msg/slot.hpp"
#include "json.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;

using rero::Intent;
using rero::Slot;
#include <iostream>
#include <sstream>

class ReroNLUNode : public rclcpp::Node
{
public:
    ReroNLUNode() : Node("rero_nlu")
    {
      // Declare parameters with default values
        this->declare_parameter("core_host", "localhost");
        this->declare_parameter("core_port", "50052");
        this->declare_parameter("input_topic_name", "speech_recognition");
        this->declare_parameter("output_topic_name", "nlu_intent");

        // Get parameters
        std::string grpcHost = this->get_parameter("core_host").as_string();
        std::string grpcPort = this->get_parameter("core_port").as_string();
        std::string inputTopicName = this->get_parameter("input_topic_name").as_string();
        std::string outputTopicName = this->get_parameter("output_topic_name").as_string();
        
        std::string address = grpcHost + ":" + grpcPort;
	RCLCPP_INFO(this->get_logger(), "gRPC Address: [%s]", address.c_str());
        
        // Initialize gRPC client
        auto nluChannel = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
        client_ = std::make_unique<NLUClient>(nluChannel);
	
        if(nluChannel->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
            RCLCPP_INFO(this->get_logger(), "gRPC Cannot Communicate with ReroCore Audio Server!");
        }

	RCLCPP_INFO(this->get_logger(), "before publisher created");
	
        // Create publisher and subscriber
        publisher_ = this->create_publisher<rero_ros::msg::Intent>(outputTopicName, 10);

	RCLCPP_INFO(this->get_logger(), "Publisher created!");
	
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            inputTopicName, 1000,
            std::bind(&ReroNLUNode::speechRecognitionCallback, this, std::placeholders::_1));

	RCLCPP_INFO(this->get_logger(), "Subscriber created!");
    }

private:
    void speechRecognitionCallback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "I heard: [%s]", msg->data.c_str());
        
        std::string res(msg->data.c_str());
        
        Intent intent = client_->GetSpeechIntent(res);
        
        rero_ros::msg::Intent outputMsg;
        outputMsg.input_text = intent.inputtext();
        outputMsg.intent_name = intent.intentname();
        outputMsg.probability = intent.probability();
        
        for(int i = 0; i < intent.slots_size(); i++) {
            rero_ros::msg::Slot msgSlot;
            msgSlot.raw_value = intent.slots(i).rawvalue();
            msgSlot.entity = intent.slots(i).entity();
            msgSlot.slot_name = intent.slots(i).slotname();
            msgSlot.range_start = intent.slots(i).rangestart();
            msgSlot.range_end = intent.slots(i).rangeend();
            outputMsg.slots.push_back(msgSlot);
        }
        
        publisher_->publish(outputMsg);
    }
    
    rclcpp::Publisher<rero_ros::msg::Intent>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    std::unique_ptr<NLUClient> client_;
};

int main(int argc, char **argv)
{

    rclcpp::init(argc, argv);

    auto node = std::make_shared<ReroNLUNode>();
    
    rclcpp::spin(node);
    
    rclcpp::shutdown();
    return 0;
}
