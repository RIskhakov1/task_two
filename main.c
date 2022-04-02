#include <stdlib.h>
#include "header.h"
#include "error_code.h"
#include "sum.h"

#include <stdio.h>

int main()
{
    error_code status = OK;
    int **matrix = NULL;
    int constructed_rows;
    status = construct_matrix(&matrix, &constructed_rows);

    if (status == OK)
    {
        int *result_arr = NULL;
        status = construct_arr(&result_arr);
        if (status == OK)
        {
            sum(matrix, result_arr);
        }
        free(result_arr);
    }

    destruct_matrix(&matrix, &constructed_rows);
    return status;
}