#include<stdio.h>

int main()
{
    int a;

    printf("Give me a number:\n");
    scanf("%d", &a);

    if  (a <= 0){
        printf("Not enough");
    }
    else if (a == 1) {
        printf("One.");
    }
    else if (a == 2) {
        printf("Two.");
    }
    else if (a > 2) {
        printf("A lot.");
    }

    return 0;
}