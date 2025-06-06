cmake_minimum_required(VERSION 3.11.0)
project(rero_ros)

# Set C++ standard for ROS 2
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# Compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Needed on some platforms for atomic ops (e.g., abseil)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -latomic")

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Enable C++ standard propagation for Abseil
set(ABSL_PROPAGATE_CXX_STD ON)

# Fetch gRPC and dependencies
include(FetchContent)
set(ABSL_ENABLE_INSTALL ON)

FetchContent_Declare(
  grpc
  GIT_REPOSITORY https://github.com/grpc/grpc.git
  GIT_TAG        v1.58.0
)

set(FETCHCONTENT_QUIET OFF)
FetchContent_MakeAvailable(grpc)

# Set gRPC/Protobuf variables (no find_package for Protobuf!)
set(_REFLECTION grpc++_reflection)
set(_GRPC_GRPCPP grpc++)
set(_PROTOBUF_LIBPROTOBUF protobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

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
)

target_link_libraries(nlu
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}

  absl::strings
  absl::cord
  absl::base
)

# Install target
install(TARGETS
  nlu
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
