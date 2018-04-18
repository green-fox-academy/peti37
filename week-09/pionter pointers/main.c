
#include <stdio.h>

//Print value of num using
//both single and double pointers

int main()
{
    int num = 1234;
    int *ptr2;
    int **ptr1;
    ptr2 = num;
    ptr1 = ptr2;


    printf("%d\n",ptr1);
    return 0;
}
