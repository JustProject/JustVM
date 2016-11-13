# version
cmake_minimum_required(VERSION 3.5)
# project name
project(JustVM)
# flag line
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# head file path
INCLUDE_DIRECTORIES(
        src/logger src/command
)

AUX_SOURCE_DIRECTORY(src DIR_SRCS)

set(SOURCE_FILES src/main.cpp)
add_executable(JustVM ${SOURCE_FILES})