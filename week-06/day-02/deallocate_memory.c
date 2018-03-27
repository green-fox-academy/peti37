#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *array;
    int i, j;
    array = (int *)malloc(10 * sizeof(int));
    for (i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            array[i] = i;
        }
        else
        {
            array[i] = i+1;
        }
        printf("%d ", array[i]);
    }
    array = (int*)realloc(0, sizeof(int));

    return 0;
}