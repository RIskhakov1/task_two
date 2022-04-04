// Copyright 2022 RIskhakov1

#include <stdio.h>
#include "sum.h"

#define MATRIX_SIZE 10000

//  result_arr[0] - сумма элементов главной диагонали
//  result_arr[i] - сумма эл-тов отрезков сдвинутых на i от гл.диаг.
error_code sum(int **matrix, long *result_arr) {
    error_code status = OK;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        result_arr[0] += matrix[i][i];
        for (int j = 1; i + j < MATRIX_SIZE; ++j) {
            if (i + j < MATRIX_SIZE) {
                result_arr[j] += matrix[i + j][i] + matrix[i][i + j];
            }
        }
    }
    return status;
}
