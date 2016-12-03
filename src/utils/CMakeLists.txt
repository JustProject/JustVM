
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

AUX_SOURCE_DIRECTORY(. UTILS)
# build utils
ADD_LIBRARY(utils ${UTILS})

# build zlib & mini_zip & mem_zip
AUX_SOURCE_DIRECTORY(zip ZIP_LIB_SRCS)

AUX_SOURCE_DIRECTORY(mini_zip MINI_LIB_SRCS)

AUX_SOURCE_DIRECTORY(mem_zip MEM_ZIP_SRCS)

ADD_LIBRARY(zlib ${ZIP_LIB_SRCS})

ADD_LIBRARY(mini_zip_lib ${MINI_LIB_SRCS})

ADD_LIBRARY(mem_zip_lib ${MEM_ZIP_SRCS})

TARGET_LINK_LIBRARIES(mini_zip_lib
        zlib)

TARGET_LINK_LIBRARIES(mem_zip_lib
        mini_zip_lib)
