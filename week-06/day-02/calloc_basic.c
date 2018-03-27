#include<stdio.h>
#include<stdlib.h>


int main()
{
    int *array;
    int i;
    array = (int *)calloc(10, sizeof(int));
    for (i = 0; i < 10; i++)
    {
        if (i < 5)
        {
            array[i] = 5;
        }
        printf("%d ", array[i]);
    }
    free(array);

    return 0;
}