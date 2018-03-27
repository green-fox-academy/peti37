#include<stdio.h>

int main()
{
    int number = 2017;
    float Pi = 3.14;
    char letter = 't';

    int* number_pointer = &number;
    float* Pi_pointer = &Pi;
    char* letter_pointer = &letter;

    printf("\tAddresses\tAddresses\n");
    printf("Number\t%p\t%p\n", &number, number_pointer);
    printf("Pi\t%p\t%p\n", &Pi, Pi_pointer);
    printf("letter\t%p\t%p\n", &letter, letter_pointer);
    printf("\n\tValues\tValues\n");
    printf("Number\t%d\t%d\n", number, *number_pointer);
    printf("Pi\t%.2f\t%.2f\n", Pi, *Pi_pointer);
    printf("Pi\t%c\t%c\n", letter, *letter_pointer);

    return 0;
}