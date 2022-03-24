#include <stdio.h>
#include <stdlib.h>
#define M 2
#define N 2
 
/*C lang: Initialize variables for iteration*/
int i;
int j;
int r;

/*function defintion*/
void print_arr(int** arr, int m, int n);
 
/*  Program to pass the 2D array to a function in C */
int main(void)
{
    int m = M;
    int n = N;
 
    /*  dynamically create an array of pointers of size `m` */
    int **arr = (int **)malloc(m * sizeof(int *));
 
    /*  dynamically allocate memory of size `n` for each row */
    for (r = 0; r < m; r++) {
        arr[r] = (int *)malloc(n * sizeof(int));
    }

    int const_arr[M][N] = {
        { 1, 2 },
        { 3, 4 }
    };

    /*assign constant arr to double array pointer */
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) {
            arr[i][j] = const_arr[i][j];
        }
    }

    print_arr(arr, m, n);
    /*  deallocate memory */
    for (i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

void print_arr(int** arr, int m, int n)
{
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) {
            arr[i][j] = i + j;
            arr[i][j] = i + j;
            printf("%d ", arr[i][j]);
        }
    printf("\n");
    }
}
