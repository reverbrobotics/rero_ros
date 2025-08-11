// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice
#include "rero_ros/msg/detail/intent__rosidl_typesupport_fastrtps_cpp.hpp"
#include "rero_ros/msg/detail/intent__functions.h"
#include "rero_ros/msg/detail/intent__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace rero_ros
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const rero_ros::msg::Slot &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  rero_ros::msg::Slot &);
size_t get_serialized_size(
  const rero_ros::msg::Slot &,
  size_t current_alignment);
size_t
max_serialized_size_Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
bool cdr_serialize_key(
  const rero_ros::msg::Slot &,
  eprosima::fastcdr::Cdr &);
size_t get_serialized_size_key(
  const rero_ros::msg::Slot &,
  size_t current_alignment);
size_t
max_serialized_size_key_Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace rero_ros


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
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: input_text
  cdr << ros_message.input_text;

  // Member: intent_name
  cdr << ros_message.intent_name;

  // Member: probability
  cdr << ros_message.probability;

  // Member: slots
  {
    size_t size = ros_message.slots.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rero_ros::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.slots[i],
        cdr);
    }
  }

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  rero_ros::msg::Intent & ros_message)
{
  // Member: input_text
  cdr >> ros_message.input_text;

  // Member: intent_name
  cdr >> ros_message.intent_name;

  // Member: probability
  cdr >> ros_message.probability;

  // Member: slots
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.slots.resize(size);
    for (size_t i = 0; i < size; i++) {
      rero_ros::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.slots[i]);
    }
  }

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
get_serialized_size(
  const rero_ros::msg::Intent & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: input_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.input_text.size() + 1);

  // Member: intent_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.intent_name.size() + 1);

  // Member: probability
  {
    size_t item_size = sizeof(ros_message.probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: slots
  {
    size_t array_size = ros_message.slots.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rero_ros::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.slots[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
max_serialized_size_Intent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: input_text
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: intent_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // Member: probability
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: slots
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rero_ros::msg::typesupport_fastrtps_cpp::max_serialized_size_Slot(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rero_ros::msg::Intent;
    is_plain =
      (
      offsetof(DataType, slots) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
cdr_serialize_key(
  const rero_ros::msg::Intent & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: input_text
  cdr << ros_message.input_text;

  // Member: intent_name
  cdr << ros_message.intent_name;

  // Member: probability
  cdr << ros_message.probability;

  // Member: slots
  {
    size_t size = ros_message.slots.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      rero_ros::msg::typesupport_fastrtps_cpp::cdr_serialize_key(
        ros_message.slots[i],
        cdr);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
get_serialized_size_key(
  const rero_ros::msg::Intent & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: input_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.input_text.size() + 1);

  // Member: intent_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.intent_name.size() + 1);

  // Member: probability
  {
    size_t item_size = sizeof(ros_message.probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: slots
  {
    size_t array_size = ros_message.slots.size();
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        rero_ros::msg::typesupport_fastrtps_cpp::get_serialized_size_key(
        ros_message.slots[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_rero_ros
max_serialized_size_key_Intent(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Member: input_text
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: intent_name
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: probability
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: slots
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        rero_ros::msg::typesupport_fastrtps_cpp::max_serialized_size_key_Slot(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = rero_ros::msg::Intent;
    is_plain =
      (
      offsetof(DataType, slots) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _Intent__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const rero_ros::msg::Intent *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Intent__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<rero_ros::msg::Intent *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Intent__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const rero_ros::msg::Intent *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Intent__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Intent(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Intent__callbacks = {
  "rero_ros::msg",
  "Intent",
  _Intent__cdr_serialize,
  _Intent__cdr_deserialize,
  _Intent__get_serialized_size,
  _Intent__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Intent__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Intent__callbacks,
  get_message_typesupport_handle_function,
  &rero_ros__msg__Intent__get_type_hash,
  &rero_ros__msg__Intent__get_type_description,
  &rero_ros__msg__Intent__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace rero_ros

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_rero_ros
const rosidl_message_type_support_t *
get_message_type_support_handle<rero_ros::msg::Intent>()
{
  return &rero_ros::msg::typesupport_fastrtps_cpp::_Intent__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, rero_ros, msg, Intent)() {
  return &rero_ros::msg::typesupport_fastrtps_cpp::_Intent__handle;
}

#ifdef __cplusplus
}
#endif
