#include<stdio.h>

//Add two numbers using pointers

int main()
{
    int a = 20;
    int b = 17;
    int* a_pointer = &a;
    int* b_pointer = &b;
    printf("%d", *a_pointer + *b_pointer);

    return 0;
}