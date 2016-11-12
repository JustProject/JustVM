cmake_minimum_required(VERSION 3.5)
project(JustVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp logger/easylogging++.h)
add_executable(JustVM ${SOURCE_FILES})