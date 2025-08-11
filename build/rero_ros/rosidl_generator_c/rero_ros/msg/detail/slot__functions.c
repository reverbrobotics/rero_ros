// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice
#include "rero_ros/msg/detail/slot__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `raw_value`
// Member `entity`
// Member `slot_name`
// Member `type_name`
// Member `type_value`
#include "rosidl_runtime_c/string_functions.h"

bool
rero_ros__msg__Slot__init(rero_ros__msg__Slot * msg)
{
  if (!msg) {
    return false;
  }
  // raw_value
  if (!rosidl_runtime_c__String__init(&msg->raw_value)) {
    rero_ros__msg__Slot__fini(msg);
    return false;
  }
  // entity
  if (!rosidl_runtime_c__String__init(&msg->entity)) {
    rero_ros__msg__Slot__fini(msg);
    return false;
  }
  // slot_name
  if (!rosidl_runtime_c__String__init(&msg->slot_name)) {
    rero_ros__msg__Slot__fini(msg);
    return false;
  }
  // range_start
  // range_end
  // type_name
  if (!rosidl_runtime_c__String__init(&msg->type_name)) {
    rero_ros__msg__Slot__fini(msg);
    return false;
  }
  // type_value
  if (!rosidl_runtime_c__String__init(&msg->type_value)) {
    rero_ros__msg__Slot__fini(msg);
    return false;
  }
  return true;
}

void
rero_ros__msg__Slot__fini(rero_ros__msg__Slot * msg)
{
  if (!msg) {
    return;
  }
  // raw_value
  rosidl_runtime_c__String__fini(&msg->raw_value);
  // entity
  rosidl_runtime_c__String__fini(&msg->entity);
  // slot_name
  rosidl_runtime_c__String__fini(&msg->slot_name);
  // range_start
  // range_end
  // type_name
  rosidl_runtime_c__String__fini(&msg->type_name);
  // type_value
  rosidl_runtime_c__String__fini(&msg->type_value);
}

bool
rero_ros__msg__Slot__are_equal(const rero_ros__msg__Slot * lhs, const rero_ros__msg__Slot * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // raw_value
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->raw_value), &(rhs->raw_value)))
  {
    return false;
  }
  // entity
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->entity), &(rhs->entity)))
  {
    return false;
  }
  // slot_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->slot_name), &(rhs->slot_name)))
  {
    return false;
  }
  // range_start
  if (lhs->range_start != rhs->range_start) {
    return false;
  }
  // range_end
  if (lhs->range_end != rhs->range_end) {
    return false;
  }
  // type_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type_name), &(rhs->type_name)))
  {
    return false;
  }
  // type_value
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type_value), &(rhs->type_value)))
  {
    return false;
  }
  return true;
}

bool
rero_ros__msg__Slot__copy(
  const rero_ros__msg__Slot * input,
  rero_ros__msg__Slot * output)
{
  if (!input || !output) {
    return false;
  }
  // raw_value
  if (!rosidl_runtime_c__String__copy(
      &(input->raw_value), &(output->raw_value)))
  {
    return false;
  }
  // entity
  if (!rosidl_runtime_c__String__copy(
      &(input->entity), &(output->entity)))
  {
    return false;
  }
  // slot_name
  if (!rosidl_runtime_c__String__copy(
      &(input->slot_name), &(output->slot_name)))
  {
    return false;
  }
  // range_start
  output->range_start = input->range_start;
  // range_end
  output->range_end = input->range_end;
  // type_name
  if (!rosidl_runtime_c__String__copy(
      &(input->type_name), &(output->type_name)))
  {
    return false;
  }
  // type_value
  if (!rosidl_runtime_c__String__copy(
      &(input->type_value), &(output->type_value)))
  {
    return false;
  }
  return true;
}

rero_ros__msg__Slot *
rero_ros__msg__Slot__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Slot * msg = (rero_ros__msg__Slot *)allocator.allocate(sizeof(rero_ros__msg__Slot), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rero_ros__msg__Slot));
  bool success = rero_ros__msg__Slot__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rero_ros__msg__Slot__destroy(rero_ros__msg__Slot * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rero_ros__msg__Slot__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rero_ros__msg__Slot__Sequence__init(rero_ros__msg__Slot__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Slot * data = NULL;

  if (size) {
    data = (rero_ros__msg__Slot *)allocator.zero_allocate(size, sizeof(rero_ros__msg__Slot), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rero_ros__msg__Slot__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rero_ros__msg__Slot__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
rero_ros__msg__Slot__Sequence__fini(rero_ros__msg__Slot__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      rero_ros__msg__Slot__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

rero_ros__msg__Slot__Sequence *
rero_ros__msg__Slot__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Slot__Sequence * array = (rero_ros__msg__Slot__Sequence *)allocator.allocate(sizeof(rero_ros__msg__Slot__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rero_ros__msg__Slot__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rero_ros__msg__Slot__Sequence__destroy(rero_ros__msg__Slot__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rero_ros__msg__Slot__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rero_ros__msg__Slot__Sequence__are_equal(const rero_ros__msg__Slot__Sequence * lhs, const rero_ros__msg__Slot__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rero_ros__msg__Slot__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rero_ros__msg__Slot__Sequence__copy(
  const rero_ros__msg__Slot__Sequence * input,
  rero_ros__msg__Slot__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rero_ros__msg__Slot);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rero_ros__msg__Slot * data =
      (rero_ros__msg__Slot *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rero_ros__msg__Slot__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rero_ros__msg__Slot__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rero_ros__msg__Slot__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
