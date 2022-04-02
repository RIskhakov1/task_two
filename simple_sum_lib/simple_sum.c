#include "sum.h"

#define MATRIX_SIZE 10000

//result_arr[0] - сумма элементов главной диагонали
//result_arr[i] - сумма эл-тов отрезков сдвинутых на i от гл.диаг.
void sum(int** matrix, int* result_arr)
{
    for (int i = 0; i < MATRIX_SIZE; ++i)
    {
        result_arr[0] += matrix[i][i];
        for (int j = 1; i + j < MATRIX_SIZE; ++j)
        {
            result_arr[j] += matrix[i + j][i] + matrix[i][i + j];
        }
    }
}
