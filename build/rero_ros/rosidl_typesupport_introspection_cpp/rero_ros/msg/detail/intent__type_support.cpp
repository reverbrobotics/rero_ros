// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "rero_ros/msg/detail/intent__functions.h"
#include "rero_ros/msg/detail/intent__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace rero_ros
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Intent_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) rero_ros::msg::Intent(_init);
}

void Intent_fini_function(void * message_memory)
{
  auto typed_message = static_cast<rero_ros::msg::Intent *>(message_memory);
  typed_message->~Intent();
}

size_t size_function__Intent__slots(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<rero_ros::msg::Slot> *>(untyped_member);
  return member->size();
}

const void * get_const_function__Intent__slots(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<rero_ros::msg::Slot> *>(untyped_member);
  return &member[index];
}

void * get_function__Intent__slots(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<rero_ros::msg::Slot> *>(untyped_member);
  return &member[index];
}

void fetch_function__Intent__slots(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const rero_ros::msg::Slot *>(
    get_const_function__Intent__slots(untyped_member, index));
  auto & value = *reinterpret_cast<rero_ros::msg::Slot *>(untyped_value);
  value = item;
}

void assign_function__Intent__slots(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<rero_ros::msg::Slot *>(
    get_function__Intent__slots(untyped_member, index));
  const auto & value = *reinterpret_cast<const rero_ros::msg::Slot *>(untyped_value);
  item = value;
}

void resize_function__Intent__slots(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<rero_ros::msg::Slot> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Intent_message_member_array[4] = {
  {
    "input_text",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros::msg::Intent, input_text),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "intent_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros::msg::Intent, intent_name),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "probability",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros::msg::Intent, probability),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "slots",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<rero_ros::msg::Slot>(),  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(rero_ros::msg::Intent, slots),  // bytes offset in struct
    nullptr,  // default value
    size_function__Intent__slots,  // size() function pointer
    get_const_function__Intent__slots,  // get_const(index) function pointer
    get_function__Intent__slots,  // get(index) function pointer
    fetch_function__Intent__slots,  // fetch(index, &value) function pointer
    assign_function__Intent__slots,  // assign(index, value) function pointer
    resize_function__Intent__slots  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Intent_message_members = {
  "rero_ros::msg",  // message namespace
  "Intent",  // message name
  4,  // number of fields
  sizeof(rero_ros::msg::Intent),
  false,  // has_any_key_member_
  Intent_message_member_array,  // message members
  Intent_init_function,  // function to initialize message memory (memory has to be allocated)
  Intent_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Intent_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Intent_message_members,
  get_message_typesupport_handle_function,
  &rero_ros__msg__Intent__get_type_hash,
  &rero_ros__msg__Intent__get_type_description,
  &rero_ros__msg__Intent__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace rero_ros


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<rero_ros::msg::Intent>()
{
  return &::rero_ros::msg::rosidl_typesupport_introspection_cpp::Intent_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, rero_ros, msg, Intent)() {
  return &::rero_ros::msg::rosidl_typesupport_introspection_cpp::Intent_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
