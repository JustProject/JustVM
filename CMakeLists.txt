# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# project name
PROJECT(JustVM)

# flag line
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
SET(BOOST_ROOT /Users/liufengkai/boost)
SET(BOOST_INCLUDE_DIR /Users/liufengkai/boost/include)

FIND_LIBRARY(Boost NAMES filesystem system)

SET(BOOST_SYSTEM_LIB ${BOOST_ROOT}/lib/libboost_system.a)
SET(BOOST_FILE_SYSTEM_LIB ${BOOST_ROOT}/lib/libboost_filesystem.a)

# head file path
INCLUDE_DIRECTORIES(
        src/logger
        src/command
        src/utils
        ${BOOST_INCLUDE_DIR}
)

ADD_SUBDIRECTORY(src/utils)
ADD_SUBDIRECTORY(src/class_read)

# Add all source files under the directory src to SOURCE_FILES
AUX_SOURCE_DIRECTORY(src SOURCE_FILES)
AUX_SOURCE_DIRECTORY(src/jvm_args JVM_ARGS)
AUX_SOURCE_DIRECTORY(src/jvm JVM_RUNABLE)
AUX_SOURCE_DIRECTORY(src/class_path JVM_CLASS_PATH)
AUX_SOURCE_DIRECTORY(src/utils/pystring PYSTRING)

# Executable target declaration
ADD_EXECUTABLE(JustVM
        ${JVM_ARGS}
        ${JVM_RUNABLE}
        ${JVM_CLASS_PATH}
        ${PYSTRING}
        ${JVM_CLASS_READER}
        ${CLASS_READ}
        ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(JustVM
        zlib
        utils
        mini_zip_lib
        mem_zip_lib
        ${BOOST_SYSTEM_LIB}
        ${BOOST_FILE_SYSTEM_LIB}
        ${Boost_LIBRARIES})
