#include<stdio.h>
#include<stdlib.h>

int factorial(int);

int main()
{
    int number = 7;
    printf("%d", factorial(number));
    return 0;
}

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}