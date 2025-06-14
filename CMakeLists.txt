cmake_minimum_required(VERSION 3.11.0)
project(rero_ros  LANGUAGES C CXX)

# Set C++ standard for ROS 2

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else()
  add_definitions(-D_WIN32_WINNT=0x600)
endif()

# Compiler warnings
#if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#  add_compile_options(-Wall -Wextra -Wpedantic)
#endif()

# Needed on some platforms for atomic ops (e.g., abseil)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -latomic")

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(ARCH "X86_64" CACHE STRING "Architecture type")

option(GRPC_FETCHCONTENT "Use git to fetch grpc" ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/common.cmake)

# Enable C++ standard propagation for Abseil
#set(ABSL_PROPAGATE_CXX_STD ON)


# ROS 2 interface generation
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Slot.msg"
  "msg/Intent.msg"
  DEPENDENCIES std_msgs
)

rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME} "rosidl_typesupport_cpp")

# Include directories for client lib
include_directories(
  ${PROJECT_SOURCE_DIR}/lib/client/include
  ${PROJECT_SOURCE_DIR}/lib/client/src
)

# Detect platform for static lib selection
message(STATUS "Architecture: ${CMAKE_SYSTEM_PROCESSOR}")
if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
  set(RERO_LIB_NAME "libReroClientARMv7.a")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
  set(RERO_LIB_NAME "libReroClientARM64.a")
else()
  set(RERO_LIB_NAME "libReroClient.a")
endif()

set(RERO_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/client/${RERO_LIB_NAME}")

# Build your executable
add_executable(nlu src/nlu.cpp)

ament_target_dependencies(nlu
  rclcpp
  std_msgs
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  -static-libgcc
  -static-libstdc++
  -lstdc++fs
)

#target_link_libraries(nlu
#  rclcpp
#  std_msgs
#  ${cpp_typesupport_target}
#  ${_REFLECTION}
#  ${_GRPC_GRPCPP}
#  ${_PROTOBUF_LIBPROTOBUF}
#  ${RERO_LIB_PATH}
#  -static-libgcc
#  -static-libstdc++
#  -lstdc++fs
#)

# Install target
install(TARGETS
  nlu
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
