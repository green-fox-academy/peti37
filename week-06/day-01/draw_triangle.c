#include<stdio.h>

int main()
{
    int number;
    scanf("%d", &number);
    for (int j = 0; j <= number; j++){
        for (int i = 0; i < j; i++){
            printf("*");
        }
        printf("*\n");
    }
    return 0;
}