// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice
#include "rero_ros/msg/detail/intent__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rero_ros/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "rero_ros/msg/detail/intent__struct.h"
#include "rero_ros/msg/detail/intent__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rero_ros/msg/detail/slot__functions.h"  // slots
#include "rosidl_runtime_c/string.h"  // input_text, intent_name
#include "rosidl_runtime_c/string_functions.h"  // input_text, intent_name

// forward declare type support functions

bool cdr_serialize_rero_ros__msg__Slot(
  const rero_ros__msg__Slot * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_rero_ros__msg__Slot(
  eprosima::fastcdr::Cdr & cdr,
  rero_ros__msg__Slot * ros_message);

size_t get_serialized_size_rero_ros__msg__Slot(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_rero_ros__msg__Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_rero_ros__msg__Slot(
  const rero_ros__msg__Slot * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_rero_ros__msg__Slot(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_rero_ros__msg__Slot(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rero_ros, msg, Slot)();


using _Intent__ros_msg_type = rero_ros__msg__Intent;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_serialize_rero_ros__msg__Intent(
  const rero_ros__msg__Intent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: input_text
  {
    const rosidl_runtime_c__String * str = &ros_message->input_text;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: intent_name
  {
    const rosidl_runtime_c__String * str = &ros_message->intent_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: probability
  {
    cdr << ros_message->probability;
  }

  // Field name: slots
  {
    size_t size = ros_message->slots.size;
    auto array_ptr = ros_message->slots.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_rero_ros__msg__Slot(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_deserialize_rero_ros__msg__Intent(
  eprosima::fastcdr::Cdr & cdr,
  rero_ros__msg__Intent * ros_message)
{
  // Field name: input_text
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->input_text.data) {
      rosidl_runtime_c__String__init(&ros_message->input_text);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->input_text,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'input_text'\n");
      return false;
    }
  }

  // Field name: intent_name
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->intent_name.data) {
      rosidl_runtime_c__String__init(&ros_message->intent_name);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->intent_name,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'intent_name'\n");
      return false;
    }
  }

  // Field name: probability
  {
    cdr >> ros_message->probability;
  }

  // Field name: slots
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->slots.data) {
      rero_ros__msg__Slot__Sequence__fini(&ros_message->slots);
    }
    if (!rero_ros__msg__Slot__Sequence__init(&ros_message->slots, size)) {
      fprintf(stderr, "failed to create array for field 'slots'");
      return false;
    }
    auto array_ptr = ros_message->slots.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_rero_ros__msg__Slot(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t get_serialized_size_rero_ros__msg__Intent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Intent__ros_msg_type * ros_message = static_cast<const _Intent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: input_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->input_text.size + 1);

  // Field name: intent_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->intent_name.size + 1);

  // Field name: probability
  {
    size_t item_size = sizeof(ros_message->probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: slots
  {
    size_t array_size = ros_message->slots.size;
    auto array_ptr = ros_message->slots.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_rero_ros__msg__Slot(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t max_serialized_size_rero_ros__msg__Intent(
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

  // Field name: input_text
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

  // Field name: intent_name
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

  // Field name: probability
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: slots
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
      size_t inner_size;
      inner_size =
        max_serialized_size_rero_ros__msg__Slot(
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
    using DataType = rero_ros__msg__Intent;
    is_plain =
      (
      offsetof(DataType, slots) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
bool cdr_serialize_key_rero_ros__msg__Intent(
  const rero_ros__msg__Intent * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: input_text
  {
    const rosidl_runtime_c__String * str = &ros_message->input_text;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: intent_name
  {
    const rosidl_runtime_c__String * str = &ros_message->intent_name;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: probability
  {
    cdr << ros_message->probability;
  }

  // Field name: slots
  {
    size_t size = ros_message->slots.size;
    auto array_ptr = ros_message->slots.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_rero_ros__msg__Slot(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t get_serialized_size_key_rero_ros__msg__Intent(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Intent__ros_msg_type * ros_message = static_cast<const _Intent__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: input_text
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->input_text.size + 1);

  // Field name: intent_name
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->intent_name.size + 1);

  // Field name: probability
  {
    size_t item_size = sizeof(ros_message->probability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: slots
  {
    size_t array_size = ros_message->slots.size;
    auto array_ptr = ros_message->slots.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_rero_ros__msg__Slot(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_rero_ros
size_t max_serialized_size_key_rero_ros__msg__Intent(
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
  // Field name: input_text
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

  // Field name: intent_name
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

  // Field name: probability
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: slots
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
      size_t inner_size;
      inner_size =
        max_serialized_size_key_rero_ros__msg__Slot(
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
    using DataType = rero_ros__msg__Intent;
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
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const rero_ros__msg__Intent * ros_message = static_cast<const rero_ros__msg__Intent *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_rero_ros__msg__Intent(ros_message, cdr);
}

static bool _Intent__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  rero_ros__msg__Intent * ros_message = static_cast<rero_ros__msg__Intent *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_rero_ros__msg__Intent(cdr, ros_message);
}

static uint32_t _Intent__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_rero_ros__msg__Intent(
      untyped_ros_message, 0));
}

static size_t _Intent__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_rero_ros__msg__Intent(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Intent = {
  "rero_ros::msg",
  "Intent",
  _Intent__cdr_serialize,
  _Intent__cdr_deserialize,
  _Intent__get_serialized_size,
  _Intent__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _Intent__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Intent,
  get_message_typesupport_handle_function,
  &rero_ros__msg__Intent__get_type_hash,
  &rero_ros__msg__Intent__get_type_description,
  &rero_ros__msg__Intent__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rero_ros, msg, Intent)() {
  return &_Intent__type_support;
}

#if defined(__cplusplus)
}
#endif
