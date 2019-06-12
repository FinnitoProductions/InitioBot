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
  )

set(project_HEADERS
  include/digital_motor.hpp
  include/drivetrain.hpp
  include/robot_map.hpp
  include/scheduler.hpp
  include/subsystem.hpp
  )

add_executable(initiobot ${project_SRCS} ${project_HEADERS})
target_link_libraries(initiobot pigpio pthread)
