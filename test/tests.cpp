// Copyright 2022 RIskhakov1
#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

extern "C" {
#include "sum.h"
#include "system_lib_header.h"
}

#define MATRIX_SIZE 10000

void print_time(clock_t start, clock_t end) {
    printf("%s %f %s\n", "Subtest running time:", (double)(end - start) /
                                        (double)(CLOCKS_PER_SEC), "sec");
}

TEST(Test, Matrix) {
    int **matrix;
    int constructed_rows;
    construct_matrix(&matrix, &constructed_rows);
    long *result_arr = NULL;
    construct_arr(&result_arr);

    clock_t start, end;
    {  // все элементы = 0
        start = clock();
        sum(matrix, result_arr);
        end = clock();
        print_time(start, end);

        for (size_t i = 0; i < MATRIX_SIZE; ++i) {
            EXPECT_EQ(result_arr[i], 0);
        }
    }

    {  // все элементы = 1
        for (size_t i = 0; i < MATRIX_SIZE; ++i) {
            for (size_t j = 0; j < MATRIX_SIZE; ++j) {
                matrix[i][j] = 1;
            }
        }
        start = clock();
        sum(matrix, result_arr);
        end = clock();
        print_time(start, end);

        EXPECT_EQ(result_arr[0], MATRIX_SIZE);
        for (size_t i = 1; i < MATRIX_SIZE; ++i) {
            ASSERT_EQ(result_arr[i], 2 * (MATRIX_SIZE - i));
        }
    }

    {  // элемент = его расстояние до главной диагонали
        for (size_t i = 0; i < MATRIX_SIZE; ++i) {
            for (size_t j = 0; j < MATRIX_SIZE; ++j) {
                int num = i - j;
                matrix[i][j] = abs(num);
            }
            result_arr[i] = 0;
        }
        start = clock();
        sum(matrix, result_arr);
        end = clock();
        print_time(start, end);

        for (size_t i = 0; i < MATRIX_SIZE; ++i) {
            EXPECT_EQ(result_arr[i], 2 * i * (MATRIX_SIZE - i));
        }
    }

    free(result_arr);
    destruct_matrix(matrix, constructed_rows);
}
