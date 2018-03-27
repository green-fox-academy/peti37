#include<stdio.h>
#include<stdlib.h>

int doubling(int*);

int main()
{
    int number = 7;
    int* number_pointer = &number;
    doubling(number_pointer);
    printf("%d", number);
    return 0;
}

int doubling(int* n)
{
    return *n *= 2;
}