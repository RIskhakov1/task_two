// Copyright 2022 RIskhakov1

#include <time.h>
#include "error_code.h"

#ifndef SYSTEM_LIB_HEADER_H_
#define SYSTEM_LIB_HEADER_H_

error_code construct_matrix(int***, int*);

void destruct_matrix(int**, int);

error_code construct_arr(long**);

void print_status(error_code, clock_t, clock_t);

#endif  // SYSTEM_LIB_SYSTEM_LIB_HEADER_H_
