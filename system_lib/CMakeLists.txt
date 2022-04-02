cmake_minimum_required(VERSION 3.22.3)
project(system_lib)

add_library(${PROJECT_NAME} source.c)

set(SYSTEM_LIB_INCLUDE_DIRS ${INCLUDE_DIRS} PARENT_SCOPE)