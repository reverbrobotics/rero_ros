// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/intent.hpp"


#ifndef RERO_ROS__MSG__DETAIL__INTENT__STRUCT_HPP_
#define RERO_ROS__MSG__DETAIL__INTENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'slots'
#include "rero_ros/msg/detail/slot__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__rero_ros__msg__Intent __attribute__((deprecated))
#else
# define DEPRECATED__rero_ros__msg__Intent __declspec(deprecated)
#endif

namespace rero_ros
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Intent_
{
  using Type = Intent_<ContainerAllocator>;

  explicit Intent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input_text = "";
      this->intent_name = "";
      this->probability = 0.0f;
    }
  }

  explicit Intent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : input_text(_alloc),
    intent_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->input_text = "";
      this->intent_name = "";
      this->probability = 0.0f;
    }
  }

  // field types and members
  using _input_text_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _input_text_type input_text;
  using _intent_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _intent_name_type intent_name;
  using _probability_type =
    float;
  _probability_type probability;
  using _slots_type =
    std::vector<rero_ros::msg::Slot_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rero_ros::msg::Slot_<ContainerAllocator>>>;
  _slots_type slots;

  // setters for named parameter idiom
  Type & set__input_text(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->input_text = _arg;
    return *this;
  }
  Type & set__intent_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->intent_name = _arg;
    return *this;
  }
  Type & set__probability(
    const float & _arg)
  {
    this->probability = _arg;
    return *this;
  }
  Type & set__slots(
    const std::vector<rero_ros::msg::Slot_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<rero_ros::msg::Slot_<ContainerAllocator>>> & _arg)
  {
    this->slots = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rero_ros::msg::Intent_<ContainerAllocator> *;
  using ConstRawPtr =
    const rero_ros::msg::Intent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rero_ros::msg::Intent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rero_ros::msg::Intent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rero_ros::msg::Intent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rero_ros::msg::Intent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rero_ros::msg::Intent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rero_ros::msg::Intent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rero_ros::msg::Intent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rero_ros::msg::Intent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rero_ros__msg__Intent
    std::shared_ptr<rero_ros::msg::Intent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rero_ros__msg__Intent
    std::shared_ptr<rero_ros::msg::Intent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Intent_ & other) const
  {
    if (this->input_text != other.input_text) {
      return false;
    }
    if (this->intent_name != other.intent_name) {
      return false;
    }
    if (this->probability != other.probability) {
      return false;
    }
    if (this->slots != other.slots) {
      return false;
    }
    return true;
  }
  bool operator!=(const Intent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Intent_

// alias to use template instance with default allocator
using Intent =
  rero_ros::msg::Intent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rero_ros

#endif  // RERO_ROS__MSG__DETAIL__INTENT__STRUCT_HPP_
