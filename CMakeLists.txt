cmake_minimum_required(VERSION 3.10)
project(HolaWorld)

set(CMAKE_CXX_STANDARD 11)

add_executable(HolaWorld src/main.cpp)

set_target_properties(HolaWorld PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
