// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/slot.hpp"


#ifndef RERO_ROS__MSG__DETAIL__SLOT__STRUCT_HPP_
#define RERO_ROS__MSG__DETAIL__SLOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__rero_ros__msg__Slot __attribute__((deprecated))
#else
# define DEPRECATED__rero_ros__msg__Slot __declspec(deprecated)
#endif

namespace rero_ros
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Slot_
{
  using Type = Slot_<ContainerAllocator>;

  explicit Slot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_value = "";
      this->entity = "";
      this->slot_name = "";
      this->range_start = 0;
      this->range_end = 0;
      this->type_name = "";
      this->type_value = "";
    }
  }

  explicit Slot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : raw_value(_alloc),
    entity(_alloc),
    slot_name(_alloc),
    type_name(_alloc),
    type_value(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->raw_value = "";
      this->entity = "";
      this->slot_name = "";
      this->range_start = 0;
      this->range_end = 0;
      this->type_name = "";
      this->type_value = "";
    }
  }

  // field types and members
  using _raw_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _raw_value_type raw_value;
  using _entity_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _entity_type entity;
  using _slot_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _slot_name_type slot_name;
  using _range_start_type =
    uint16_t;
  _range_start_type range_start;
  using _range_end_type =
    uint16_t;
  _range_end_type range_end;
  using _type_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_name_type type_name;
  using _type_value_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_value_type type_value;

  // setters for named parameter idiom
  Type & set__raw_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->raw_value = _arg;
    return *this;
  }
  Type & set__entity(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->entity = _arg;
    return *this;
  }
  Type & set__slot_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->slot_name = _arg;
    return *this;
  }
  Type & set__range_start(
    const uint16_t & _arg)
  {
    this->range_start = _arg;
    return *this;
  }
  Type & set__range_end(
    const uint16_t & _arg)
  {
    this->range_end = _arg;
    return *this;
  }
  Type & set__type_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type_name = _arg;
    return *this;
  }
  Type & set__type_value(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    rero_ros::msg::Slot_<ContainerAllocator> *;
  using ConstRawPtr =
    const rero_ros::msg::Slot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<rero_ros::msg::Slot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<rero_ros::msg::Slot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      rero_ros::msg::Slot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<rero_ros::msg::Slot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      rero_ros::msg::Slot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<rero_ros::msg::Slot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<rero_ros::msg::Slot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<rero_ros::msg::Slot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__rero_ros__msg__Slot
    std::shared_ptr<rero_ros::msg::Slot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__rero_ros__msg__Slot
    std::shared_ptr<rero_ros::msg::Slot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Slot_ & other) const
  {
    if (this->raw_value != other.raw_value) {
      return false;
    }
    if (this->entity != other.entity) {
      return false;
    }
    if (this->slot_name != other.slot_name) {
      return false;
    }
    if (this->range_start != other.range_start) {
      return false;
    }
    if (this->range_end != other.range_end) {
      return false;
    }
    if (this->type_name != other.type_name) {
      return false;
    }
    if (this->type_value != other.type_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const Slot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Slot_

// alias to use template instance with default allocator
using Slot =
  rero_ros::msg::Slot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace rero_ros

#endif  // RERO_ROS__MSG__DETAIL__SLOT__STRUCT_HPP_
