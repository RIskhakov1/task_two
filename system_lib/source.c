#include <stdlib.h>
#include "header.h"

#define MATRIX_SIZE 10000

// constructed_rows - содержит число успешно созданных строк
// изначально устанавливается = 10000, число изменяется в случае ошибки
error_code construct_matrix(int ***matrix, int* constructed_rows)
{
    error_code status = OK;
    *matrix = (int **)calloc(MATRIX_SIZE * sizeof(int), sizeof(int));
    status = (*matrix == NULL) ? MEMORY_ALLOCATION_ERROR : OK;

    if (status == OK)
    {
        *constructed_rows = MATRIX_SIZE;
        for (int i = 0; i < MATRIX_SIZE; ++i)
        {
            (*matrix)[i] = (int *)calloc(MATRIX_SIZE * sizeof(int), sizeof(int));
            if ((*matrix)[i] == NULL)
            {
                *constructed_rows = i;
                status = MEMORY_ALLOCATION_ERROR;
                break;
            }
        }
    }

    return status;
}

void destruct_matrix(int ***matrix, int* constructed_rows)
{
    for (int i = 0; i < *constructed_rows; ++i)
    {
        free((*matrix)[i]);
    }
    free(*matrix);
}

error_code construct_arr(int** arr)
{
    error_code status = OK;
    *arr = (int*)calloc(MATRIX_SIZE*sizeof(int), sizeof(int));
    status = (*arr == NULL) ? MEMORY_ALLOCATION_ERROR : OK;
    return status;
}
