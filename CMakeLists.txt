cmake_minimum_required(VERSION 3.5)
project(action_bridge)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(clf_ue_audio_msgs REQUIRED)
find_package(clf_audio_msgs)

# find ROS 1 packages
include(cmake/find_ros1_package.cmake)

find_package(PkgConfig REQUIRED)

find_ros1_package(actionlib REQUIRED)
find_ros1_package(roscpp REQUIRED)
find_ros1_package(clf_ue_audio_one_msgs REQUIRED)
find_ros1_package(audio_common_msgs)

ament_export_include_directories(include)
include_directories(include)

add_executable(action_bridge_ue_audio_node
    "src/action_bridge_ue_audio.cpp"
)
ament_target_dependencies(action_bridge_ue_audio_node
    "ros1_roscpp" "ros1_actionlib" "ros1_clf_ue_audio_one_msgs" "ros1_audio_common_msgs"
    "rclcpp" "rclcpp_action" "clf_ue_audio_msgs" "clf_audio_msgs"
)

install(TARGETS action_bridge_ue_audio_node
    DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
