// Copyright 2022 RIskhakov1

#ifndef SYSTEM_LIB_ERROR_CODE_H_
#define SYSTEM_LIB_ERROR_CODE_H_

typedef enum error_code {
    OK = 0,
    MEMORY_ALLOCATION_ERROR,
    CREATING_THREAD_ERROR
} error_code;

#endif  // SYSTEM_LIB_ERROR_CODE_H_
