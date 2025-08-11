// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from rero_ros:msg/Intent.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "rero_ros/msg/intent.hpp"


#ifndef RERO_ROS__MSG__DETAIL__INTENT__TRAITS_HPP_
#define RERO_ROS__MSG__DETAIL__INTENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "rero_ros/msg/detail/intent__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'slots'
#include "rero_ros/msg/detail/slot__traits.hpp"

namespace rero_ros
{

namespace msg
{

inline void to_flow_style_yaml(
  const Intent & msg,
  std::ostream & out)
{
  out << "{";
  // member: input_text
  {
    out << "input_text: ";
    rosidl_generator_traits::value_to_yaml(msg.input_text, out);
    out << ", ";
  }

  // member: intent_name
  {
    out << "intent_name: ";
    rosidl_generator_traits::value_to_yaml(msg.intent_name, out);
    out << ", ";
  }

  // member: probability
  {
    out << "probability: ";
    rosidl_generator_traits::value_to_yaml(msg.probability, out);
    out << ", ";
  }

  // member: slots
  {
    if (msg.slots.size() == 0) {
      out << "slots: []";
    } else {
      out << "slots: [";
      size_t pending_items = msg.slots.size();
      for (auto item : msg.slots) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Intent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: input_text
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_text: ";
    rosidl_generator_traits::value_to_yaml(msg.input_text, out);
    out << "\n";
  }

  // member: intent_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "intent_name: ";
    rosidl_generator_traits::value_to_yaml(msg.intent_name, out);
    out << "\n";
  }

  // member: probability
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "probability: ";
    rosidl_generator_traits::value_to_yaml(msg.probability, out);
    out << "\n";
  }

  // member: slots
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.slots.size() == 0) {
      out << "slots: []\n";
    } else {
      out << "slots:\n";
      for (auto item : msg.slots) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Intent & msg, bool use_flow_style = false)
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
  const rero_ros::msg::Intent & msg,
  std::ostream & out, size_t indentation = 0)
{
  rero_ros::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use rero_ros::msg::to_yaml() instead")]]
inline std::string to_yaml(const rero_ros::msg::Intent & msg)
{
  return rero_ros::msg::to_yaml(msg);
}

template<>
inline const char * data_type<rero_ros::msg::Intent>()
{
  return "rero_ros::msg::Intent";
}

template<>
inline const char * name<rero_ros::msg::Intent>()
{
  return "rero_ros/msg/Intent";
}

template<>
struct has_fixed_size<rero_ros::msg::Intent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<rero_ros::msg::Intent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<rero_ros::msg::Intent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // RERO_ROS__MSG__DETAIL__INTENT__TRAITS_HPP_
