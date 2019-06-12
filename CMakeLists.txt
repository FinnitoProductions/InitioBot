cmake_minimum_required (VERSION 2.6)
project (initiobot)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
  include
  )

link_directories(
  )

set(project_SRCS
  src/digital_motor.cpp
  src/drive_client.cpp
  src/drivetrain.cpp
  src/scheduler.cpp
  src/subsystem.cpp
  src/input_devices.cpp
  src/obstacle_sensor.cpp
  src/servo.cpp
  src/utilities.cpp
  src/console_reader.cpp
  )

set(project_HEADERS
  include/digital_motor.hpp
  include/drivetrain.hpp
  include/robot_map.hpp
  include/scheduler.hpp
  include/subsystem.hpp
  include/input_devices.hpp
  include/obstacle_sensor.hpp
  include/servo.hpp
  include/utilities.hpp
  include/console_reader.hpp
  )

add_executable(initiobot ${project_SRCS} ${project_HEADERS})
target_link_libraries(initiobot pigpio pthread)
