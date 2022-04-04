// Copyright 2022 RIskhakov1

#include <stdlib.h>
#include <time.h>
#include "system_lib_header.h"
#include "error_code.h"
#include "sum.h"


int main() {
    error_code status = OK;
    int **matrix = NULL;
    int constructed_rows;
    status = construct_matrix(&matrix, &constructed_rows);

    clock_t start, end;
    if (status == OK) {
        long *result_arr = NULL;
        status = construct_arr(&result_arr);
        if (status == OK) {
            start = clock();
            status = sum(matrix, result_arr);
            end = clock();
        }
        free(result_arr);
    }

    destruct_matrix(matrix, constructed_rows);

    print_status(status, start, end);
    return status;
}
