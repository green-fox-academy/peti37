#include<stdio.h>

int main()
{
    int favorite_number = 37;
    printf("%d\n", favorite_number);

    int a = 123;
    int b = 256;
    int c = a;
    a = b;
    b = c;
    printf("a = %d\nb = %d\n", a, b);
    return 0;
}
