#include <stdio.h>
#include <stdlib.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    /*to return array pointer inside function*/
    /*option 1: static*/
    /*static int ar[2] = {1,1};*/

    /*option 2: malloc*/
    int i;
    int *score_arr = malloc( a_count );
    *result_count = 2;
    int a_score = 0;
    int b_score = 0;
    for(i=0; i < a_count; i++)
    {
        if (a[i] > b[i])
        {
            a_score++;
        }
        else if (a[i] < b[i])
        {
            b_score++;
        }
    }
    score_arr[0] = a_score;
    score_arr[1] = b_score;
    
    return score_arr;
}

int main()
{
    int result_count;
    int i;
    int a[3] = { 5, 6, 7 };
    int b[3] = { 3, 6, 10 };
    int* result = compareTriplets(3, a, 3, b, &result_count);
    for (i = 0; i < result_count; i++) {
        printf("%d", *(result + i));

        if (i != result_count - 1) {
            printf(" "); 
        }
    }
    return 0;
}
