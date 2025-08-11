// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rero_ros/msg/detail/slot__struct.h"
#include "rero_ros/msg/detail/slot__type_support.h"
#include "rero_ros/msg/detail/slot__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace rero_ros
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _Slot_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Slot_type_support_ids_t;

static const _Slot_type_support_ids_t _Slot_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Slot_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Slot_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Slot_type_support_symbol_names_t _Slot_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, rero_ros, msg, Slot)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, rero_ros, msg, Slot)),
  }
};

typedef struct _Slot_type_support_data_t
{
  void * data[2];
} _Slot_type_support_data_t;

static _Slot_type_support_data_t _Slot_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Slot_message_typesupport_map = {
  2,
  "rero_ros",
  &_Slot_message_typesupport_ids.typesupport_identifier[0],
  &_Slot_message_typesupport_symbol_names.symbol_name[0],
  &_Slot_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Slot_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Slot_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &rero_ros__msg__Slot__get_type_hash,
  &rero_ros__msg__Slot__get_type_description,
  &rero_ros__msg__Slot__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace rero_ros

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, rero_ros, msg, Slot)() {
  return &::rero_ros::msg::rosidl_typesupport_c::Slot_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
