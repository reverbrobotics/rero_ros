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

find_library(ONNXRUNTIME_LIBRARY NAMES onnxruntime HINTS /usr/local/onnxruntime/lib)
find_path(ONNXRUNTIME_INCLUDE_DIR NAMES onnxruntime_cxx_api.h HINTS /usr/local/onnxruntime/include)
if(NOT ONNXRUNTIME_LIBRARY OR NOT ONNXRUNTIME_INCLUDE_DIR)
  message(FATAL_ERROR "ONNX Runtime not found. Please ensure it is installed in /usr/local/onnxruntime.")
endif()

# Find libsamplerate
find_library(SAMPLERATE_LIBRARY NAMES samplerate HINTS /usr/lib /usr/local/lib /usr/lib/aarch64-linux-gnu)
find_path(SAMPLERATE_INCLUDE_DIR NAMES samplerate.h HINTS /usr/include /usr/local/include)
if(NOT SAMPLERATE_LIBRARY OR NOT SAMPLERATE_INCLUDE_DIR)
  message(FATAL_ERROR "libsamplerate not found. Please install it (e.g., sudo apt install libsamplerate0-dev).")
endif()

include_directories(
  ${PROJECT_SOURCE_DIR}/lib/client/include
  ${PROJECT_SOURCE_DIR}/lib/client/src
  ${CMAKE_CURRENT_BINARY_DIR}
  ${ONNXRUNTIME_INCLUDE_DIR}
  ${SAMPLERATE_INCLUDE_DIR}
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

add_executable(vad_node src/vad_node.cpp)
ament_target_dependencies(vad_node rclcpp std_msgs)

add_executable(doa_node src/doa_node.cpp)
ament_target_dependencies(doa_node rclcpp std_msgs)

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


target_link_libraries(doa_node
  ${cpp_typesupport_target}
  ${ONNXRUNTIME_LIBRARY}
  ${SAMPLERATE_LIBRARY}
)

target_link_libraries(vad_node
  ${cpp_typesupport_target}
  ${ONNXRUNTIME_LIBRARY}
  ${SAMPLERATE_LIBRARY}
)

install(TARGETS
  nlu
  text_to_speech
  speech_recognition
  audio_stream
  audio_subscriber
  vad_node
  doa_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
