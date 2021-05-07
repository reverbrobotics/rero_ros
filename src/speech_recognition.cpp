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
  ros::init(argc, argv, "rero_speech_recognition");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("result", 1000);

  std::string grpcHost = "0.0.0.0";
  std::string grpcPort = "50052";

  SpeechRecognitionClient client(
          grpc::CreateChannel(grpcHost+":"+grpcPort, grpc::InsecureChannelCredentials()),
            grpc::CreateChannel(grpcHost+":"+grpcPort, grpc::InsecureChannelCredentials())
            );

  while (ros::ok()) {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    SpeechRecognitionResult result = client.StreamAudio();
    json::JSON resultObject = json::JSON::Load(result.result());

    msg.data = resultObject["text"].ToString();

    ROS_INFO("sr result: %s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();
  }

  return 0;
}
