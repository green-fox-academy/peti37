#include<stdio.h>

// The "other_high_number_pointer" should point to the same memory address
// without using the "&" operator.

int main()
{
    int *array;
    int i;
    array = (int *)malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++)
    {
        array[i] = 5;
        printf("%d ", array[i]);
    }
    free(array);
    
    return 0;
}