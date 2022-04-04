cmake_minimum_required(VERSION 3.22.2)
project(simple_sum_lib)

add_library(${PROJECT_NAME} simple_sum.c)

target_include_directories(${PROJECT_NAME} PUBLIC ../system_lib)