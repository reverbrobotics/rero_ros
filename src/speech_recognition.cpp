#include "ros/ros.h"
#include "std_msgs/String.h"
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

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv) {
  ros::init(argc, argv, "rero_speech_recognition", ros::init_options::AnonymousName);

  ros::NodeHandle n;

  std::string grpcHost;
  std::string grpcPort;
  std::string topicName;

  n.getParam("core_host", grpcHost);
  n.getParam("core_port", grpcPort);
  n.getParam("topic_name", topicName);

  std::cout << "topic name: " << topicName << std::endl;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(topicName, 1000);

  auto audioChannel = grpc::CreateChannel(grpcHost+":"+grpcPort, grpc::InsecureChannelCredentials());
  auto srChannel = grpc::CreateChannel(grpcHost+":"+grpcPort, grpc::InsecureChannelCredentials());

  SpeechRecognitionClient client(audioChannel, srChannel);

  while (ros::ok()) {
    if(audioChannel->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE ||
     srChannel->GetState(false) == GRPC_CHANNEL_TRANSIENT_FAILURE) {
      ROS_INFO("gRPC Cannot Communicate with ReroCore Audio Server!");
      ros::Duration(2.0).sleep();
      ros::spinOnce();
      continue;
    }

    std_msgs::String msg;
    SpeechRecognitionResult result = client.StreamAudio();

    if(result.result().empty()) {
        ros::spinOnce();
        continue;
    }

    json::JSON resultObject = json::JSON::Load(result.result());

    msg.data = resultObject["text"].ToString();

    ROS_INFO("sr result: %s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();
  }

  return 0;
}
