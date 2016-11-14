# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# project name
PROJECT(JustVM)

# flag line
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# head file path
INCLUDE_DIRECTORIES(
        src/logger
        src/command
)

# Add all source files under the directory src to SOURCE_FILES
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)
AUX_SOURCE_DIRECTORY(src/jvm_args JVM_ARGS)
AUX_SOURCE_DIRECTORY(src/jvm JVM_RUNABLE)

ADD_SUBDIRECTORY(src/jvm_args)
ADD_SUBDIRECTORY(src/jvm)

# Executable target declaration
ADD_EXECUTABLE(JustVM ${JVM_ARGS} ${JVM_RUNABLE} ${SOURCE_FILES})
