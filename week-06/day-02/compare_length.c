#include<stdio.h>

int main()
{
    int p1[] = {1, 2, 3};
    int p2[] = {4, 5};
    if  (sizeof(p1)/sizeof(p1[0]) > sizeof(p2)/sizeof(p2[0]))
    {
        printf("p1 size is bigger");
    }
    else
    {
        printf("p2 size is bigger");
    }
    return 0;
}