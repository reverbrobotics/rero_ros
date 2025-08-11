// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "rero_ros/msg/detail/intent__rosidl_typesupport_introspection_c.h"
#include "rero_ros/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "rero_ros/msg/detail/intent__functions.h"
#include "rero_ros/msg/detail/intent__struct.h"


// Include directives for member types
// Member `input_text`
// Member `intent_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `slots`
#include "rero_ros/msg/slot.h"
// Member `slots`
#include "rero_ros/msg/detail/slot__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  rero_ros__msg__Intent__init(message_memory);
}

void rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_fini_function(void * message_memory)
{
  rero_ros__msg__Intent__fini(message_memory);
}

size_t rero_ros__msg__Intent__rosidl_typesupport_introspection_c__size_function__Intent__slots(
  const void * untyped_member)
{
  const rero_ros__msg__Slot__Sequence * member =
    (const rero_ros__msg__Slot__Sequence *)(untyped_member);
  return member->size;
}

const void * rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_const_function__Intent__slots(
  const void * untyped_member, size_t index)
{
  const rero_ros__msg__Slot__Sequence * member =
    (const rero_ros__msg__Slot__Sequence *)(untyped_member);
  return &member->data[index];
}

void * rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_function__Intent__slots(
  void * untyped_member, size_t index)
{
  rero_ros__msg__Slot__Sequence * member =
    (rero_ros__msg__Slot__Sequence *)(untyped_member);
  return &member->data[index];
}

void rero_ros__msg__Intent__rosidl_typesupport_introspection_c__fetch_function__Intent__slots(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rero_ros__msg__Slot * item =
    ((const rero_ros__msg__Slot *)
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_const_function__Intent__slots(untyped_member, index));
  rero_ros__msg__Slot * value =
    (rero_ros__msg__Slot *)(untyped_value);
  *value = *item;
}

void rero_ros__msg__Intent__rosidl_typesupport_introspection_c__assign_function__Intent__slots(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rero_ros__msg__Slot * item =
    ((rero_ros__msg__Slot *)
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_function__Intent__slots(untyped_member, index));
  const rero_ros__msg__Slot * value =
    (const rero_ros__msg__Slot *)(untyped_value);
  *item = *value;
}

bool rero_ros__msg__Intent__rosidl_typesupport_introspection_c__resize_function__Intent__slots(
  void * untyped_member, size_t size)
{
  rero_ros__msg__Slot__Sequence * member =
    (rero_ros__msg__Slot__Sequence *)(untyped_member);
  rero_ros__msg__Slot__Sequence__fini(member);
  return rero_ros__msg__Slot__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_member_array[4] = {
  {
    "input_text",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Intent, input_text),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "intent_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Intent, intent_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "probability",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Intent, probability),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "slots",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros__msg__Intent, slots),  // bytes offset in struct
    NULL,  // default value
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__size_function__Intent__slots,  // size() function pointer
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_const_function__Intent__slots,  // get_const(index) function pointer
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__get_function__Intent__slots,  // get(index) function pointer
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__fetch_function__Intent__slots,  // fetch(index, &value) function pointer
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__assign_function__Intent__slots,  // assign(index, value) function pointer
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__resize_function__Intent__slots  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_members = {
  "rero_ros__msg",  // message namespace
  "Intent",  // message name
  4,  // number of fields
  sizeof(rero_ros__msg__Intent),
  false,  // has_any_key_member_
  rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_member_array,  // message members
  rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_init_function,  // function to initialize message memory (memory has to be allocated)
  rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_type_support_handle = {
  0,
  &rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_members,
  get_message_typesupport_handle_function,
  &rero_ros__msg__Intent__get_type_hash,
  &rero_ros__msg__Intent__get_type_description,
  &rero_ros__msg__Intent__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_rero_ros
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rero_ros, msg, Intent)() {
  rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rero_ros, msg, Slot)();
  if (!rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_type_support_handle.typesupport_identifier) {
    rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &rero_ros__msg__Intent__rosidl_typesupport_introspection_c__Intent_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
