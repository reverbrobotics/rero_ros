// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/intent.hpp"


#ifndef RERO_ROS__MSG__DETAIL__INTENT__BUILDER_HPP_
#define RERO_ROS__MSG__DETAIL__INTENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rero_ros/msg/detail/intent__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rero_ros
{

namespace msg
{

namespace builder
{

class Init_Intent_slots
{
public:
  explicit Init_Intent_slots(::rero_ros::msg::Intent & msg)
  : msg_(msg)
  {}
  ::rero_ros::msg::Intent slots(::rero_ros::msg::Intent::_slots_type arg)
  {
    msg_.slots = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rero_ros::msg::Intent msg_;
};

class Init_Intent_probability
{
public:
  explicit Init_Intent_probability(::rero_ros::msg::Intent & msg)
  : msg_(msg)
  {}
  Init_Intent_slots probability(::rero_ros::msg::Intent::_probability_type arg)
  {
    msg_.probability = std::move(arg);
    return Init_Intent_slots(msg_);
  }

private:
  ::rero_ros::msg::Intent msg_;
};

class Init_Intent_intent_name
{
public:
  explicit Init_Intent_intent_name(::rero_ros::msg::Intent & msg)
  : msg_(msg)
  {}
  Init_Intent_probability intent_name(::rero_ros::msg::Intent::_intent_name_type arg)
  {
    msg_.intent_name = std::move(arg);
    return Init_Intent_probability(msg_);
  }

private:
  ::rero_ros::msg::Intent msg_;
};

class Init_Intent_input_text
{
public:
  Init_Intent_input_text()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Intent_intent_name input_text(::rero_ros::msg::Intent::_input_text_type arg)
  {
    msg_.input_text = std::move(arg);
    return Init_Intent_intent_name(msg_);
  }

private:
  ::rero_ros::msg::Intent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rero_ros::msg::Intent>()
{
  return rero_ros::msg::builder::Init_Intent_input_text();
}

}  // namespace rero_ros

#endif  // RERO_ROS__MSG__DETAIL__INTENT__BUILDER_HPP_
