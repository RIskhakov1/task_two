// Copyright 2022 RIskhakov1

#include "error_code.h"

#ifndef PARALLEL_SUM_SUM_H_
#define PARALLEL_SUM_SUM_H_

error_code sum(int**, long*);

typedef struct {
    int** matrix;
    long *result_arr;
    int id;
    int* ranges;
} thread_data;

#endif //  PARALLEL_SUM_LIB_SUM_H_
