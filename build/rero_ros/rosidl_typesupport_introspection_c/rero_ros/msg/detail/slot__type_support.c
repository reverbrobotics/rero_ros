// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rero_ros/msg/detail/slot__rosidl_typesupport_introspection_c.h"
#include "rero_ros/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rero_ros/msg/detail/slot__functions.h"
#include "rero_ros/msg/detail/slot__struct.h"


// Include directives for member types
// Member `raw_value`
// Member `entity`
// Member `slot_name`
// Member `type_name`
// Member `type_value`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rero_ros__msg__Slot__init(message_memory);
}

void rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_fini_function(void * message_memory)
{
  rero_ros__msg__Slot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_member_array[7] = {
  {
    "raw_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, raw_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "entity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, entity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "slot_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, slot_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_start",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, range_start),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "range_end",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, range_end),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, type_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type_value",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Slot, type_value),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_members = {
  "rero_ros__msg",  // message namespace
  "Slot",  // message name
  7,  // number of fields
  sizeof(rero_ros__msg__Slot),
  false,  // has_any_key_member_
  rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_member_array,  // message members
  rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_init_function,  // function to initialize message memory (memory has to be allocated)
  rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_type_support_handle = {
  0,
  &rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_members,
  get_message_typesupport_handle_function,
  &rero_ros__msg__Slot__get_type_hash,
  &rero_ros__msg__Slot__get_type_description,
  &rero_ros__msg__Slot__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rero_ros
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rero_ros, msg, Slot)() {
  if (!rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_type_support_handle.typesupport_identifier) {
    rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rero_ros__msg__Slot__rosidl_typesupport_introspection_c__Slot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
