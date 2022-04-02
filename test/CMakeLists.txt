cmake_minimum_required(VERSION 3.22.3)
project(tests)

set(CMAKE_CXX_STANDARD 17)
string(APPEND CMAKE_CXX_FLAGS " -fprofile-arcs -ftest-coverage -O0")

if (BUILD_SANITIZERS)
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=address -fsanitize=undefined -fsanitize=leak")
endif()

if (BUILD_SANITIZERS_THREAD)
    string(APPEND CMAKE_CXX_FLAGS " -fsanitize=thread")
endif()
string(APPEND CMAKE_EXE_LINKER_FLAGS " -coverage -lgcov")

if(USE_SIMPLE)
    set(USING_LIB "simple")
endif()

if(USE_PARALLEL)
    set(USING_LIB "parallel")  
endif()

add_executable(${PROJECT_NAME} tests.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../parallel_sum_lib ../simple_sum_lib)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTest gtest_main)