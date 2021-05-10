#include "ros/ros.h"
#include "std_msgs/String.h"
#include <grpcpp/grpcpp.h>
#include <AudioClient.h>
#include "rero_ros/Intent.h"
#include "rero_ros/Slot.h"
#include "json.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;

using rero::StreamRequest;
using rero::AudioStreamer;
using rero::Audio;

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

ros::Publisher pub;

void speechRecognitionCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());

}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rero_nlu");

  ros::NodeHandle n;

  std::string grpcHost;
  std::string grpcPort;
  std::string inputTopicName;
  std::string outputTopicName;

  n.getParam("/rero_ros/core_host", grpcHost);
  n.getParam("/rero_ros/core_port", grpcPort);
  n.getParam("/rero_ros/input_topic_name", inputTopicName);
  n.getParam("/rero_ros/output_topic_name", outputTopicName);

  pub = n.advertise<rero_ros::Intent>(outputTopicName, 1000);
  ros::Subscriber sub = n.subscribe(inputTopicName, 1000, speechRecognitionCallback);

  ros::spin();

  return 0;
}
