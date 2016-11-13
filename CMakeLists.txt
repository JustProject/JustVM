# version
cmake_minimum_required(VERSION 3.5)
# project name
project(JustVM)
# flag line
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# head file path
INCLUDE_DIRECTORIES(

)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

# set environment
SET(JAVA_HOME ${/usr/libexec/java_home})

set(SOURCE_FILES src/main.cpp src/logger/log.h src/command/optioninfo.h src/command/behaviour.h src/command/params.h src/command/argument.h src/command/option.h src/command/required.h src/command/paramslist.h)
add_executable(JustVM ${SOURCE_FILES})