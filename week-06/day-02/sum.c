#include<stdio.h>
#include<stdlib.h>


int main()
{
    int numbers[] = {1, 5, 6, 8, 1};
    int size = sizeof(numbers)/sizeof(numbers[0]);
    printf("%d", sum(numbers, size));
    return 0;
}

int sum(int *array, int size)
{
    int summed_num = 0;
    for (int i = 0; i < size; i++)
    {
        summed_num += array[i];
    }
    return summed_num;
}