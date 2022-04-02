cmake_minimum_required(VERSION 3.22.3)
project(parallel_sum_lib)

add_library(${PROJECT_NAME} parallel_sum.c)
