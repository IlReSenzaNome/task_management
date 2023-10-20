cmake_minimum_required(VERSION 3.25)
project(task_management)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_STANDARD 17)

add_executable(main src/main.cpp)

