cmake_minimum_required(VERSION 3.2)
project(LinkedList)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(LinkedList ${SOURCE_FILES} list.h list.cpp listplus.h listplus.cpp)
