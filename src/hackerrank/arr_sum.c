#include <stdio.h>
#include <stdlib.h>


/*iteration variable Initialization */
int i;

int arr_sum(int size_of_arr, int* arr);

int main()
{
    int i;
    int ar[3] = {
        1, 2, 3
    };
    for ( i = 0; i < 3; i++ )
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
    int r = arr_sum(3, ar);
    printf("sum: %d", r);
    return 0;
}

int arr_sum(int size_of_arr, int* arr) {
    int sum = 0;
    for (i =0; i < size_of_arr; i++)
    {
        sum += arr[i];
    }
    return sum;
}
