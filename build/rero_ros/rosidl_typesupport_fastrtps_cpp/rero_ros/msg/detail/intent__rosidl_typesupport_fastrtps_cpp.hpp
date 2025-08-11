// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

#ifndef RERO_ROS__MSG__DETAIL__INTENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define RERO_ROS__MSG__DETAIL__INTENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rero_ros/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "rero_ros/msg/detail/intent__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace rero_ros
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
cdr_serialize(
  const rero_ros::msg::Intent & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rero_ros::msg::Intent & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
get_serialized_size(
  const rero_ros::msg::Intent & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
max_serialized_size_Intent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
cdr_serialize_key(
  const rero_ros::msg::Intent & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
get_serialized_size_key(
  const rero_ros::msg::Intent & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
max_serialized_size_key_Intent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rero_ros

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rero_ros, msg, Intent)();

#ifdef __cplusplus
}
#endif

#endif  // RERO_ROS__MSG__DETAIL__INTENT__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
