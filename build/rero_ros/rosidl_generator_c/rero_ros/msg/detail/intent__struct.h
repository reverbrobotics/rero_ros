// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/intent.h"


#ifndef RERO_ROS__MSG__DETAIL__INTENT__STRUCT_H_
#define RERO_ROS__MSG__DETAIL__INTENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'input_text'
// Member 'intent_name'
#include "rosidl_runtime_c/string.h"
// Member 'slots'
#include "rero_ros/msg/detail/slot__struct.h"

/// Struct defined in msg/Intent in the package rero_ros.
typedef struct rero_ros__msg__Intent
{
  rosidl_runtime_c__String input_text;
  rosidl_runtime_c__String intent_name;
  float probability;
  rero_ros__msg__Slot__Sequence slots;
} rero_ros__msg__Intent;

// Struct for a sequence of rero_ros__msg__Intent.
typedef struct rero_ros__msg__Intent__Sequence
{
  rero_ros__msg__Intent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} rero_ros__msg__Intent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // RERO_ROS__MSG__DETAIL__INTENT__STRUCT_H_
