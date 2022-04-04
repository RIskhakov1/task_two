// Copyright 2022 RIskhakov1

#include <sys/sysinfo.h>
#include <pthread.h>
#include <stdlib.h>
#include "sum.h"
#include "error_code.h"

#define MATRIX_SZ 10000
#define CACHE_LINE_SZ 16

//  вычисляет диапазоны смещений относительно главной диагонали
//  в которых будут работать потоки
//  диапазоны кратны размеру кэш линии
error_code get_ranges(int **ranges, int amount_threads) {
    error_code status = OK;
    *ranges = (int *)calloc((amount_threads + 1) * sizeof(int), sizeof(int));
    status = (*ranges == NULL) ? MEMORY_ALLOCATION_ERROR : OK;

    if (status == OK) {
        (*ranges)[0] = 0;
        (*ranges)[amount_threads] = MATRIX_SZ;

        int range = MATRIX_SZ / amount_threads;
        while (range % CACHE_LINE_SZ != 0) {
            --range;
        }

        for (int i = 1; i < amount_threads; ++i) {
            (*ranges)[i] = i * range;
        }
    }
    return status;
}

void *calculate(void *th_data) {
    thread_data *data = (thread_data *)th_data;
    for (int i = data->ranges[data->id]; i < data->ranges[data->id + 1];
                                     i += CACHE_LINE_SZ) {
        for (int j = 0; j < MATRIX_SZ; ++j) {
            for (int k = 0; k < CACHE_LINE_SZ; ++k) {
                if (j + i + k < MATRIX_SZ && i + k != 0) {
                    data->result_arr[i + k] += data->matrix[j][i + j + k];
                }
                if (j - i - k >= 0) {
                    data->result_arr[i + k] += data->matrix[j][j - i - k];
                }
            }
        }
    }
}

error_code sum(int **matrix, long *result_arr) {
    error_code status = OK;
    int amount_threads = get_nprocs() - 1;
    int *ranges = NULL;
    status = get_ranges(&ranges, amount_threads);


    if (status == OK) {
        pthread_t *threads = (pthread_t *)malloc(amount_threads
                                    * sizeof(pthread_t));
        status = (threads == NULL) ? MEMORY_ALLOCATION_ERROR : OK;

        if (status == OK) {
            thread_data *th_data = (thread_data *)malloc(amount_threads
                                    * sizeof(thread_data));
            for (int i = 0; i < amount_threads; ++i) {
                th_data[i].id = i;
                th_data[i].matrix = matrix;
                th_data[i].result_arr = result_arr;
                th_data[i].ranges = ranges;
                pthread_create(&threads[i], NULL, calculate, &th_data[i]);
            }

            for (int i = 0; i < amount_threads; ++i) {
                pthread_join(threads[i], NULL);
            }

            free(threads);
            free(th_data);
        }
    }

    free(ranges);
    return status;
}
