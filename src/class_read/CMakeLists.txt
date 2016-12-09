# version
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

AUX_SOURCE_DIRECTORY(. CLASS_READ)

ADD_SUBDIRECTORY(constant_pool)
ADD_SUBDIRECTORY(access_flag)

# Executable target declaration
ADD_EXECUTABLE(class_reader_test
        ../utils/pystring/pystring.cpp
        ${CONSTANT_POOL_INFO_SRC}
        ${ACCESS_FLAG_SRC}
        ${CLASS_READ})

TARGET_LINK_LIBRARIES(class_reader_test
        zlib
        mem_zip_lib
        mini_zip_lib
        ${Boost_LIBRARIES})
