cmake_minimum_required(VERSION 3.5)
project(JustVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp logger/log.h command/optioninfo.h command/behaviour.h command/params.h command/argument.h command/option.h command/required.h command/paramslist.h)
add_executable(JustVM ${SOURCE_FILES})