#include "ros/ros.h"
#include "std_msgs/String.h"
#include <grpcpp/grpcpp.h>
#include <NLUClient.h>
#include "rero_ros/Intent.h"
#include "rero_ros/Slot.h"
#include "json.h"

using grpc::Status;
using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientWriter;

using rero::Intent;
using rero::Slot;

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */

ros::Publisher pub;
NLUClient* client;

void speechRecognitionCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]", msg->data.c_str());

    std::string res(msg->data.c_str());

    Intent intent = client->GetSpeechIntent(res);

    rero_ros::Intent outputMsg;
    outputMsg.inputText = intent.inputtext();
    outputMsg.intentName = intent.intentname();
    outputMsg.probability = intent.probability();

    for(int i=0; i<intent.slots_size(); i++) {
        rero_ros::Slot msgSlot;
        msgSlot.rawValue = intent.slots(i).rawvalue();
        msgSlot.entity = intent.slots(i).entity();
        msgSlot.slotName = intent.slots(i).slotname();
        msgSlot.rangeStart = intent.slots(i).rangestart();
        msgSlot.rangeEnd = intent.slots(i).rangeend();
        outputMsg.slots.push_back(msgSlot);
    }

    pub.publish(outputMsg);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "rero_nlu");

  ros::NodeHandle n;

  std::string grpcHost;
  std::string grpcPort;
  std::string inputTopicName;
  std::string outputTopicName;

  n.getParam("core_host", grpcHost);
  n.getParam("core_port", grpcPort);
  n.getParam("input_topic_name", inputTopicName);
  n.getParam("output_topic_name", outputTopicName);

  std::string address = grpcHost+":"+grpcPort;

  client = new NLUClient(grpc::CreateChannel(address, grpc::InsecureChannelCredentials()));

  pub = n.advertise<rero_ros::Intent>(outputTopicName, 1000);
  ros::Subscriber sub = n.subscribe(inputTopicName, 1000, speechRecognitionCallback);

  ros::spin();

  delete client;
  return 0;
}
