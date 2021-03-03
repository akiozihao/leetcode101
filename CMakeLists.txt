cmake_minimum_required(VERSION 3.0)

project(LEETCODE101)

include_directories(${CMAKE_SOURCE_DIR}/include)

# set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_BUILD_TYPE Debug)

add_executable(main_cmake cspiration/068.cpp)