# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# project name
PROJECT(JustVM)

# flag line
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # FIXME Maybe you'd like to add a -fpermissive to pass the build?

# head file path
INCLUDE_DIRECTORIES(
        src/logger
        src/command
)

# Add all source files under the directory src to SOURCE_FILES
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)

# Executable target declaration
ADD_EXECUTABLE(JustVM ${SOURCE_FILES})
