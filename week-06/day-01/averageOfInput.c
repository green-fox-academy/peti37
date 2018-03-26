#include<stdio.h>

int main()
{
    int a;
    int b;
    int c;
    int d;
    int e;

    printf("Give me 5 numbers:\n");
    scanf("%d", &a);
    printf("4 more\n");
    scanf("%d", &b);
    printf("3 more\n");
    scanf("%d", &c);
    printf("2 more\n");
    scanf("%d", &d);
    printf("1 more\n");
    scanf("%d", &e);

    printf("Sum of the numbers: %d, Average of the numbers: %d", a+b+c+d+e, (a+b+c+d+e)/5);

    return 0;
}
