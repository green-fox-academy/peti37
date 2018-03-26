#include<stdio.h>

int main()
{
    int number1;
    int number2;

    printf("Give me 2 number:\n");
    scanf("%d", &number1);
    printf("Give me 1 more:\n");
    scanf("%d", &number2);

    if  (number1 > number2){
        printf("This one is larger: %d", number1);
    }
    else {
        printf("This one is larger: %d", number2);
    }
    return 0;
}