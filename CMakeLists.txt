cmake_minimum_required(VERSION 3.5)

project(lab4)

add_executable(lab4 main.cpp)

set_property(TARGET lab4 PROPERTY CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")