cmake_minimum_required(VERSION 3.22.2)
project(task_two)


if(USE_SIMPLE)
    set(USING_LIB "simple")
endif()

if(USE_PARALLEL)
    set(USING_LIB "parallel")  
endif()


add_executable(${PROJECT_NAME} main.c system_lib/source.c ${USING_LIB}_sum_lib/${USING_LIB}_sum.c)
target_include_directories(${PROJECT_NAME} PUBLIC ${USING_LIB}_sum_lib system_lib)
target_link_libraries(${PROJECT_NAME} ${USING_LIB}_sum_lib system_lib)
add_subdirectory(${USING_LIB}_sum_lib)
add_subdirectory(system_lib)
add_subdirectory(test)