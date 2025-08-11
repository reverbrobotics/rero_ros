// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/slot.h"


#ifndef RERO_ROS__MSG__DETAIL__SLOT__STRUCT_H_
#define RERO_ROS__MSG__DETAIL__SLOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'raw_value'
// Member 'entity'
// Member 'slot_name'
// Member 'type_name'
// Member 'type_value'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Slot in the package rero_ros.
typedef struct rero_ros__msg__Slot
{
  rosidl_runtime_c__String raw_value;
  rosidl_runtime_c__String entity;
  rosidl_runtime_c__String slot_name;
  uint16_t range_start;
  uint16_t range_end;
  rosidl_runtime_c__String type_name;
  rosidl_runtime_c__String type_value;
} rero_ros__msg__Slot;

// Struct for a sequence of rero_ros__msg__Slot.
typedef struct rero_ros__msg__Slot__Sequence
{
  rero_ros__msg__Slot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rero_ros__msg__Slot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RERO_ROS__MSG__DETAIL__SLOT__STRUCT_H_
