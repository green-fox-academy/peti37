#include<stdio.h>
#include<stdlib.h>

char* append_a(char*, int);

int main()
{
    int numbers[] = {1, 5, 6, 8};
    printf("%d", sum(numbers));
    return 0;
}

int sum(int *array)
{
    int summed_num = 0;
    for (int i = 0; i < sizeof(array); i++)
    {
        summed_num += array[i];
    }
    return summed_num;
}