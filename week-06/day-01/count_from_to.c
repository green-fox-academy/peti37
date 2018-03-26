#include<stdio.h>

int main()
{
    int number;
    int number2;
    printf("Give me a whole number:");
    scanf("%d", &number);
    printf("Give me one more:");
    scanf("%d", &number2);

    if (number > number2) {
        printf("The second number should be bigger.");
    }
    else {
        for (int i = number; i < number2; i++){
            printf("%d\n", i);
        }
    }
    return 0;
}