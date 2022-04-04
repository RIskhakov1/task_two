//  Copyright 2022 RIskhakov1

#include <stdlib.h>
#include <stdio.h>
#include "system_lib_header.h"

#define MATRIX_SIZE 10000

//  constructed_rows - содержит число успешно созданных строк
//  изначально устанавливается = 10000, число изменяется в случае ошибки
error_code construct_matrix(int ***matrix, int* constructed_rows) {
    error_code status = OK;
    *matrix = (int **)calloc(MATRIX_SIZE * sizeof(int), sizeof(int));
    status = (*matrix == NULL) ? MEMORY_ALLOCATION_ERROR : OK;

    if (status == OK) {
        *constructed_rows = MATRIX_SIZE;
        for (int i = 0; i < MATRIX_SIZE; ++i) {
            (*matrix)[i] = (int *)calloc(MATRIX_SIZE * sizeof(int),
                                                    sizeof(int));
            if ((*matrix)[i] == NULL) {
                *constructed_rows = i;
                status = MEMORY_ALLOCATION_ERROR;
                break;
            }
        }
    }
    return status;
}

void destruct_matrix(int **matrix, int constructed_rows) {
    for (int i = 0; i < constructed_rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

error_code construct_arr(long** arr) {
    error_code status = OK;
    *arr = (long*)calloc(MATRIX_SIZE*sizeof(long), sizeof(long));
    status = (*arr == NULL) ? MEMORY_ALLOCATION_ERROR : OK;
    return status;
}

void print_status(error_code status, clock_t start, clock_t end) {
    switch (status) {
    case OK:
        printf("Program succesfully worked\n");
        printf("%s %f\n", "Running time:",
                    (double)(end - start) / (double)(CLOCKS_PER_SEC));
        break;

    case MEMORY_ALLOCATION_ERROR:
        printf("Unable to allocate memory\n");
        break;

    case CREATING_THREAD_ERROR:
        printf("Unable to create thread\n");
        break;
    default:
        break;
    }
}
