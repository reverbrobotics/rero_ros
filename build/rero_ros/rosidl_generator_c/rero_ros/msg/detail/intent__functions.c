// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice
#include "rero_ros/msg/detail/intent__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `input_text`
// Member `intent_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `slots`
#include "rero_ros/msg/detail/slot__functions.h"

bool
rero_ros__msg__Intent__init(rero_ros__msg__Intent * msg)
{
  if (!msg) {
    return false;
  }
  // input_text
  if (!rosidl_runtime_c__String__init(&msg->input_text)) {
    rero_ros__msg__Intent__fini(msg);
    return false;
  }
  // intent_name
  if (!rosidl_runtime_c__String__init(&msg->intent_name)) {
    rero_ros__msg__Intent__fini(msg);
    return false;
  }
  // probability
  // slots
  if (!rero_ros__msg__Slot__Sequence__init(&msg->slots, 0)) {
    rero_ros__msg__Intent__fini(msg);
    return false;
  }
  return true;
}

void
rero_ros__msg__Intent__fini(rero_ros__msg__Intent * msg)
{
  if (!msg) {
    return;
  }
  // input_text
  rosidl_runtime_c__String__fini(&msg->input_text);
  // intent_name
  rosidl_runtime_c__String__fini(&msg->intent_name);
  // probability
  // slots
  rero_ros__msg__Slot__Sequence__fini(&msg->slots);
}

bool
rero_ros__msg__Intent__are_equal(const rero_ros__msg__Intent * lhs, const rero_ros__msg__Intent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // input_text
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->input_text), &(rhs->input_text)))
  {
    return false;
  }
  // intent_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->intent_name), &(rhs->intent_name)))
  {
    return false;
  }
  // probability
  if (lhs->probability != rhs->probability) {
    return false;
  }
  // slots
  if (!rero_ros__msg__Slot__Sequence__are_equal(
      &(lhs->slots), &(rhs->slots)))
  {
    return false;
  }
  return true;
}

bool
rero_ros__msg__Intent__copy(
  const rero_ros__msg__Intent * input,
  rero_ros__msg__Intent * output)
{
  if (!input || !output) {
    return false;
  }
  // input_text
  if (!rosidl_runtime_c__String__copy(
      &(input->input_text), &(output->input_text)))
  {
    return false;
  }
  // intent_name
  if (!rosidl_runtime_c__String__copy(
      &(input->intent_name), &(output->intent_name)))
  {
    return false;
  }
  // probability
  output->probability = input->probability;
  // slots
  if (!rero_ros__msg__Slot__Sequence__copy(
      &(input->slots), &(output->slots)))
  {
    return false;
  }
  return true;
}

rero_ros__msg__Intent *
rero_ros__msg__Intent__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Intent * msg = (rero_ros__msg__Intent *)allocator.allocate(sizeof(rero_ros__msg__Intent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rero_ros__msg__Intent));
  bool success = rero_ros__msg__Intent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rero_ros__msg__Intent__destroy(rero_ros__msg__Intent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rero_ros__msg__Intent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rero_ros__msg__Intent__Sequence__init(rero_ros__msg__Intent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Intent * data = NULL;

  if (size) {
    data = (rero_ros__msg__Intent *)allocator.zero_allocate(size, sizeof(rero_ros__msg__Intent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rero_ros__msg__Intent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rero_ros__msg__Intent__fini(&data[i - 1]);
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
rero_ros__msg__Intent__Sequence__fini(rero_ros__msg__Intent__Sequence * array)
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
      rero_ros__msg__Intent__fini(&array->data[i]);
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

rero_ros__msg__Intent__Sequence *
rero_ros__msg__Intent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rero_ros__msg__Intent__Sequence * array = (rero_ros__msg__Intent__Sequence *)allocator.allocate(sizeof(rero_ros__msg__Intent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rero_ros__msg__Intent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rero_ros__msg__Intent__Sequence__destroy(rero_ros__msg__Intent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rero_ros__msg__Intent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rero_ros__msg__Intent__Sequence__are_equal(const rero_ros__msg__Intent__Sequence * lhs, const rero_ros__msg__Intent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rero_ros__msg__Intent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rero_ros__msg__Intent__Sequence__copy(
  const rero_ros__msg__Intent__Sequence * input,
  rero_ros__msg__Intent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rero_ros__msg__Intent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rero_ros__msg__Intent * data =
      (rero_ros__msg__Intent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rero_ros__msg__Intent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rero_ros__msg__Intent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rero_ros__msg__Intent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
