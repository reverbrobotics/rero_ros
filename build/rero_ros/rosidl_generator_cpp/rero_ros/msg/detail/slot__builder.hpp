// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/slot.hpp"


#ifndef RERO_ROS__MSG__DETAIL__SLOT__BUILDER_HPP_
#define RERO_ROS__MSG__DETAIL__SLOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "rero_ros/msg/detail/slot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace rero_ros
{

namespace msg
{

namespace builder
{

class Init_Slot_type_value
{
public:
  explicit Init_Slot_type_value(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  ::rero_ros::msg::Slot type_value(::rero_ros::msg::Slot::_type_value_type arg)
  {
    msg_.type_value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_type_name
{
public:
  explicit Init_Slot_type_name(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_type_value type_name(::rero_ros::msg::Slot::_type_name_type arg)
  {
    msg_.type_name = std::move(arg);
    return Init_Slot_type_value(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_range_end
{
public:
  explicit Init_Slot_range_end(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_type_name range_end(::rero_ros::msg::Slot::_range_end_type arg)
  {
    msg_.range_end = std::move(arg);
    return Init_Slot_type_name(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_range_start
{
public:
  explicit Init_Slot_range_start(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_range_end range_start(::rero_ros::msg::Slot::_range_start_type arg)
  {
    msg_.range_start = std::move(arg);
    return Init_Slot_range_end(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_slot_name
{
public:
  explicit Init_Slot_slot_name(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_range_start slot_name(::rero_ros::msg::Slot::_slot_name_type arg)
  {
    msg_.slot_name = std::move(arg);
    return Init_Slot_range_start(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_entity
{
public:
  explicit Init_Slot_entity(::rero_ros::msg::Slot & msg)
  : msg_(msg)
  {}
  Init_Slot_slot_name entity(::rero_ros::msg::Slot::_entity_type arg)
  {
    msg_.entity = std::move(arg);
    return Init_Slot_slot_name(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

class Init_Slot_raw_value
{
public:
  Init_Slot_raw_value()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Slot_entity raw_value(::rero_ros::msg::Slot::_raw_value_type arg)
  {
    msg_.raw_value = std::move(arg);
    return Init_Slot_entity(msg_);
  }

private:
  ::rero_ros::msg::Slot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::rero_ros::msg::Slot>()
{
  return rero_ros::msg::builder::Init_Slot_raw_value();
}

}  // namespace rero_ros

#endif  // RERO_ROS__MSG__DETAIL__SLOT__BUILDER_HPP_
