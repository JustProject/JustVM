# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

# project name
PROJECT(JustVM)

# flag line
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#
SET(BOOST_ROOT /Users/liufengkai/boost)
SET(Boost_INCLUDE_DIR ${BOOST_ROOT}/include)
SET(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib)
set(Boost_USE_STATIC_LIBS ON)

FIND_PACKAGE(Boost 1.62.0 COMPONENTS system filesystem REQUIRED)
#FIND_PACKAGE(zlib1g)

LINK_DIRECTORIES(${Boost_LIBRARY_DIR})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

# head file path
INCLUDE_DIRECTORIES(
        src/logger
        src/command
        src/utils
        src/run_time/reflect
)

ADD_SUBDIRECTORY(src/utils)
ADD_SUBDIRECTORY(src/class_read)
ADD_SUBDIRECTORY(src/misc)

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
        ${UTILS}
        ${JVM_CLASS_READER}
        ${CLASS_READ}
        ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(JustVM
        zlib
        mem_zip_lib
        mini_zip_lib
        ${Boost_LIBRARIES})
