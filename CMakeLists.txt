cmake_minimum_required(VERSION 3.11.0)
project(rero_ros LANGUAGES C CXX)

# Set C++ standard for ROS 2
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
else()
  add_definitions(-D_WIN32_WINNT=0x600)
endif()

# ROS 2 dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

option(GRPC_FETCHCONTENT "Use git to fetch grpc" ON)
option(ABSL_ENABLE_INSTALL "Enable Abseil installation" ON)

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


include_directories(
  ${PROJECT_SOURCE_DIR}/lib/client/include
  ${PROJECT_SOURCE_DIR}/lib/client/src
  ${CMAKE_CURRENT_BINARY_DIR}
)


if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "arm")
  set(RERO_LIB_NAME "libReroClientARMv7.a")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
  set(RERO_LIB_NAME "libReroClientARM64.a")
else()
  set(RERO_LIB_NAME "libReroClient.a")
endif()

set(RERO_LIB_PATH "${PROJECT_SOURCE_DIR}/lib/client/${RERO_LIB_NAME}")


add_executable(nlu src/nlu.cpp)
ament_target_dependencies(nlu rclcpp std_msgs)

add_executable(speech_recognition src/speech_recognition.cpp)
ament_target_dependencies(speech_recognition rclcpp std_msgs)

add_executable(text_to_speech src/text_to_speech.cpp)
ament_target_dependencies(text_to_speech rclcpp std_msgs)

add_executable(audio_stream src/audio_stream.cpp)
ament_target_dependencies(audio_stream rclcpp std_msgs)

add_executable(audio_subscriber src/audio_subscriber.cpp)
ament_target_dependencies(audio_subscriber rclcpp std_msgs)

ament_export_dependencies(rosidl_default_runtime)

target_link_libraries(nlu
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  absl::check
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_initialize
)





target_link_libraries(text_to_speech
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  absl::check
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_initialize
)

target_link_libraries(speech_recognition
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  absl::check
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_initialize
)


target_link_libraries(audio_stream
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  absl::check
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_initialize
)

target_link_libraries(audio_subscriber
  ${cpp_typesupport_target}
  ${RERO_LIB_PATH}
  ${_REFLECTION}
  ${_GRPC_GRPCPP}
  ${_PROTOBUF_LIBPROTOBUF}
  absl::check
  absl::flags
  absl::flags_parse
  absl::log
  absl::log_initialize
)

install(TARGETS
  nlu
  text_to_speech
  speech_recognition
  audio_stream
  audio_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
