cmake_minimum_required(VERSION 3.22.2)
project(parallel_sum_lib)

add_library(${PROJECT_NAME} parallel_sum.c)

target_include_directories(${PROJECT_NAME} PUBLIC ../system_lib)
