cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)
project(Utils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (LIB_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

aux_source_directory(${LIB_SOURCE_DIR} LIB_SRCS)
aux_source_directory(${LIB_INCLUDE_DIR} LIB_INCLUDES)

add_library(Utils STATIC ${LIB_SRCS} ${LIB_INCLUDES})
target_include_directories(Utils
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${LIB_INCLUDE_DIR}>
)
