// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice
#ifndef RERO_ROS__MSG__DETAIL__SLOT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define RERO_ROS__MSG__DETAIL__SLOT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "rero_ros/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rero_ros/msg/detail/slot__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_serialize_rero_ros__msg__Slot(
  const rero_ros__msg__Slot * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_deserialize_rero_ros__msg__Slot(
  eprosima::fastcdr::Cdr &,
  rero_ros__msg__Slot * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t get_serialized_size_rero_ros__msg__Slot(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t max_serialized_size_rero_ros__msg__Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_serialize_key_rero_ros__msg__Slot(
  const rero_ros__msg__Slot * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t get_serialized_size_key_rero_ros__msg__Slot(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t max_serialized_size_key_rero_ros__msg__Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rero_ros, msg, Slot)();

#ifdef __cplusplus
}
#endif

#endif  // RERO_ROS__MSG__DETAIL__SLOT__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
