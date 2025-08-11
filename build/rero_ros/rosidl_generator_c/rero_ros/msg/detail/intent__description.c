// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

#include "rero_ros/msg/detail/intent__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_type_hash_t *
rero_ros__msg__Intent__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5b, 0x8d, 0xe7, 0x1e, 0x1c, 0x25, 0xd1, 0xd7,
      0x00, 0x8d, 0x3e, 0x28, 0x70, 0x50, 0xd2, 0xf9,
      0x1d, 0x61, 0x65, 0x37, 0xfe, 0xc4, 0x9b, 0x2a,
      0x8b, 0x3f, 0x87, 0xfd, 0x9d, 0xb9, 0x05, 0x2a,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "rero_ros/msg/detail/slot__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t rero_ros__msg__Slot__EXPECTED_HASH = {1, {
    0x7f, 0xb6, 0xe8, 0x5c, 0x95, 0x68, 0x0e, 0xa8,
    0xf1, 0x53, 0xe8, 0xb9, 0xaf, 0x3b, 0x48, 0x19,
    0x0b, 0x50, 0xba, 0x0a, 0x1b, 0x06, 0x5c, 0x02,
    0x30, 0x9b, 0x1b, 0x6b, 0xf8, 0x26, 0x2c, 0x04,
  }};
#endif

static char rero_ros__msg__Intent__TYPE_NAME[] = "rero_ros/msg/Intent";
static char rero_ros__msg__Slot__TYPE_NAME[] = "rero_ros/msg/Slot";

// Define type names, field names, and default values
static char rero_ros__msg__Intent__FIELD_NAME__input_text[] = "input_text";
static char rero_ros__msg__Intent__FIELD_NAME__intent_name[] = "intent_name";
static char rero_ros__msg__Intent__FIELD_NAME__probability[] = "probability";
static char rero_ros__msg__Intent__FIELD_NAME__slots[] = "slots";

static rosidl_runtime_c__type_description__Field rero_ros__msg__Intent__FIELDS[] = {
  {
    {rero_ros__msg__Intent__FIELD_NAME__input_text, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Intent__FIELD_NAME__intent_name, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Intent__FIELD_NAME__probability, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {rero_ros__msg__Intent__FIELD_NAME__slots, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_UNBOUNDED_SEQUENCE,
      0,
      0,
      {rero_ros__msg__Slot__TYPE_NAME, 17, 17},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription rero_ros__msg__Intent__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {rero_ros__msg__Slot__TYPE_NAME, 17, 17},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
rero_ros__msg__Intent__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {rero_ros__msg__Intent__TYPE_NAME, 19, 19},
      {rero_ros__msg__Intent__FIELDS, 4, 4},
    },
    {rero_ros__msg__Intent__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&rero_ros__msg__Slot__EXPECTED_HASH, rero_ros__msg__Slot__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = rero_ros__msg__Slot__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "string input_text\n"
  "string intent_name\n"
  "float32 probability\n"
  "Slot[] slots";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
rero_ros__msg__Intent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {rero_ros__msg__Intent__TYPE_NAME, 19, 19},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 69, 69},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
rero_ros__msg__Intent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *rero_ros__msg__Intent__get_individual_type_description_source(NULL),
    sources[1] = *rero_ros__msg__Slot__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
