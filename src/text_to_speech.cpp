#include "ros/ros.h"
#include "std_msgs/String.h"
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

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

ros::Publisher pub;
TTSClient* client;

void ttsCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());

    std::string res(msg->data.c_str());

    TTSResponse response = client->TTS(res);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rero_tts");

  ros::NodeHandle n;

  std::string grpcHost;
  std::string grpcPort;
  std::string inputTopicName;


  n.getParam("core_host", grpcHost);
  n.getParam("core_port", grpcPort);
  n.getParam("input_topic_name", inputTopicName);

  std::string address = grpcHost+":"+grpcPort;

  auto ttsChannel = grpc::CreateChannel(address, grpc::InsecureChannelCredentials());
  client = new TTSClient(ttsChannel);

    if(ttsChannel->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
        ROS_INFO("gRPC Cannot Communicate with ReroCore TTS Server!");
    }

  ros::Subscriber sub = n.subscribe(inputTopicName, 1000, ttsCallback);

  ros::spin();

  delete client;
  return 0;
}