// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/intent.h"


#ifndef RERO_ROS__MSG__DETAIL__INTENT__FUNCTIONS_H_
#define RERO_ROS__MSG__DETAIL__INTENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "rero_ros/msg/rosidl_generator_c__visibility_control.h"

#include "rero_ros/msg/detail/intent__struct.h"

/// Initialize msg/Intent message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * rero_ros__msg__Intent
 * )) before or use
 * rero_ros__msg__Intent__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__init(rero_ros__msg__Intent * msg);

/// Finalize msg/Intent message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
void
rero_ros__msg__Intent__fini(rero_ros__msg__Intent * msg);

/// Create msg/Intent message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * rero_ros__msg__Intent__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
rero_ros__msg__Intent *
rero_ros__msg__Intent__create(void);

/// Destroy msg/Intent message.
/**
 * It calls
 * rero_ros__msg__Intent__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
void
rero_ros__msg__Intent__destroy(rero_ros__msg__Intent * msg);

/// Check for msg/Intent message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__are_equal(const rero_ros__msg__Intent * lhs, const rero_ros__msg__Intent * rhs);

/// Copy a msg/Intent message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__copy(
  const rero_ros__msg__Intent * input,
  rero_ros__msg__Intent * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_type_hash_t *
rero_ros__msg__Intent__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_runtime_c__type_description__TypeDescription *
rero_ros__msg__Intent__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_runtime_c__type_description__TypeSource *
rero_ros__msg__Intent__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
const rosidl_runtime_c__type_description__TypeSource__Sequence *
rero_ros__msg__Intent__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/Intent messages.
/**
 * It allocates the memory for the number of elements and calls
 * rero_ros__msg__Intent__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__Sequence__init(rero_ros__msg__Intent__Sequence * array, size_t size);

/// Finalize array of msg/Intent messages.
/**
 * It calls
 * rero_ros__msg__Intent__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
void
rero_ros__msg__Intent__Sequence__fini(rero_ros__msg__Intent__Sequence * array);

/// Create array of msg/Intent messages.
/**
 * It allocates the memory for the array and calls
 * rero_ros__msg__Intent__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
rero_ros__msg__Intent__Sequence *
rero_ros__msg__Intent__Sequence__create(size_t size);

/// Destroy array of msg/Intent messages.
/**
 * It calls
 * rero_ros__msg__Intent__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
void
rero_ros__msg__Intent__Sequence__destroy(rero_ros__msg__Intent__Sequence * array);

/// Check for msg/Intent message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__Sequence__are_equal(const rero_ros__msg__Intent__Sequence * lhs, const rero_ros__msg__Intent__Sequence * rhs);

/// Copy an array of msg/Intent messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_rero_ros
bool
rero_ros__msg__Intent__Sequence__copy(
  const rero_ros__msg__Intent__Sequence * input,
  rero_ros__msg__Intent__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // RERO_ROS__MSG__DETAIL__INTENT__FUNCTIONS_H_
