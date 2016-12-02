# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# project name
PROJECT(ClassRead)

# flag line
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

AUX_SOURCE_DIRECTORY(. CLASS_READ)

ADD_SUBDIRECTORY(constant_pool)

# Executable target declaration
ADD_EXECUTABLE(ClassRead
        class_read_test.cpp
        ${CONSTANT_POOL_INFO_SRC}
        ${CLASS_READ})

TARGET_LINK_LIBRARIES(ClassRead
        zlib
        utils
        mini_zip_lib
        mem_zip_lib
        ${BOOST_SYSTEM_LIB}
        ${BOOST_FILE_SYSTEM_LIB}
        ${Boost_LIBRARIES})