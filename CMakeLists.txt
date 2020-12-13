cmake_minimum_required(VERSION 2.6)
project(Toy_Emulator)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -g3")

add_subdirectory(emulator)
add_subdirectory(test)
