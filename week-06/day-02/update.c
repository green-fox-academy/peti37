#include<stdio.h>

// update the value of number variable to 42 using the "number_pointer"

int main()
{
    int number = 1234;
    int* number_pointer = &number;
    *number_pointer = 42;
    printf("%d", number);

    return 0;
}