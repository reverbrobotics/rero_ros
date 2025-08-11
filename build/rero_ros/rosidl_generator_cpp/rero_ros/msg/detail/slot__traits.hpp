// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rero_ros:msg/Slot.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/slot.hpp"


#ifndef RERO_ROS__MSG__DETAIL__SLOT__TRAITS_HPP_
#define RERO_ROS__MSG__DETAIL__SLOT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rero_ros/msg/detail/slot__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace rero_ros
{

namespace msg
{

inline void to_flow_style_yaml(
  const Slot & msg,
  std::ostream & out)
{
  out << "{";
  // member: raw_value
  {
    out << "raw_value: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_value, out);
    out << ", ";
  }

  // member: entity
  {
    out << "entity: ";
    rosidl_generator_traits::value_to_yaml(msg.entity, out);
    out << ", ";
  }

  // member: slot_name
  {
    out << "slot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.slot_name, out);
    out << ", ";
  }

  // member: range_start
  {
    out << "range_start: ";
    rosidl_generator_traits::value_to_yaml(msg.range_start, out);
    out << ", ";
  }

  // member: range_end
  {
    out << "range_end: ";
    rosidl_generator_traits::value_to_yaml(msg.range_end, out);
    out << ", ";
  }

  // member: type_name
  {
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << ", ";
  }

  // member: type_value
  {
    out << "type_value: ";
    rosidl_generator_traits::value_to_yaml(msg.type_value, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Slot & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: raw_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "raw_value: ";
    rosidl_generator_traits::value_to_yaml(msg.raw_value, out);
    out << "\n";
  }

  // member: entity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "entity: ";
    rosidl_generator_traits::value_to_yaml(msg.entity, out);
    out << "\n";
  }

  // member: slot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slot_name: ";
    rosidl_generator_traits::value_to_yaml(msg.slot_name, out);
    out << "\n";
  }

  // member: range_start
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_start: ";
    rosidl_generator_traits::value_to_yaml(msg.range_start, out);
    out << "\n";
  }

  // member: range_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "range_end: ";
    rosidl_generator_traits::value_to_yaml(msg.range_end, out);
    out << "\n";
  }

  // member: type_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_name: ";
    rosidl_generator_traits::value_to_yaml(msg.type_name, out);
    out << "\n";
  }

  // member: type_value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type_value: ";
    rosidl_generator_traits::value_to_yaml(msg.type_value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Slot & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace rero_ros

namespace rosidl_generator_traits
{

[[deprecated("use rero_ros::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const rero_ros::msg::Slot & msg,
  std::ostream & out, size_t indentation = 0)
{
  rero_ros::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rero_ros::msg::to_yaml() instead")]]
inline std::string to_yaml(const rero_ros::msg::Slot & msg)
{
  return rero_ros::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rero_ros::msg::Slot>()
{
  return "rero_ros::msg::Slot";
}

template<>
inline const char * name<rero_ros::msg::Slot>()
{
  return "rero_ros/msg/Slot";
}

template<>
struct has_fixed_size<rero_ros::msg::Slot>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rero_ros::msg::Slot>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rero_ros::msg::Slot>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RERO_ROS__MSG__DETAIL__SLOT__TRAITS_HPP_
