// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

#include "rero_ros/msg/detail/slot__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_type_hash_t *
rero_ros__msg__Slot__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x7f, 0xb6, 0xe8, 0x5c, 0x95, 0x68, 0x0e, 0xa8,
      0xf1, 0x53, 0xe8, 0xb9, 0xaf, 0x3b, 0x48, 0x19,
      0x0b, 0x50, 0xba, 0x0a, 0x1b, 0x06, 0x5c, 0x02,
      0x30, 0x9b, 0x1b, 0x6b, 0xf8, 0x26, 0x2c, 0x04,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char rero_ros__msg__Slot__TYPE_NAME[] = "rero_ros/msg/Slot";

// Define type names, field names, and default values
static char rero_ros__msg__Slot__FIELD_NAME__raw_value[] = "raw_value";
static char rero_ros__msg__Slot__FIELD_NAME__entity[] = "entity";
static char rero_ros__msg__Slot__FIELD_NAME__slot_name[] = "slot_name";
static char rero_ros__msg__Slot__FIELD_NAME__range_start[] = "range_start";
static char rero_ros__msg__Slot__FIELD_NAME__range_end[] = "range_end";
static char rero_ros__msg__Slot__FIELD_NAME__type_name[] = "type_name";
static char rero_ros__msg__Slot__FIELD_NAME__type_value[] = "type_value";

static rosidl_runtime_c__type_description__Field rero_ros__msg__Slot__FIELDS[] = {
  {
    {rero_ros__msg__Slot__FIELD_NAME__raw_value, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__entity, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__slot_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__range_start, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__range_end, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__type_name, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Slot__FIELD_NAME__type_value, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rero_ros__msg__Slot__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rero_ros__msg__Slot__TYPE_NAME, 17, 17},
      {rero_ros__msg__Slot__FIELDS, 7, 7},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string raw_value\n"
  "string entity\n"
  "string slot_name\n"
  "uint16 range_start\n"
  "uint16 range_end\n"
  "string type_name\n"
  "string type_value";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rero_ros__msg__Slot__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rero_ros__msg__Slot__TYPE_NAME, 17, 17},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 118, 118},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rero_ros__msg__Slot__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rero_ros__msg__Slot__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
