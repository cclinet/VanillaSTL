cmake_minimum_required(VERSION 3.20)
project(VanillaSTL)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra -Wno-sign-compare")

add_subdirectory(Test)