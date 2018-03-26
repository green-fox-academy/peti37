#include<stdio.h>

int main()
{
    for (int i = 0; i <= 100; i++){
        int b = i % 15;
        switch (b){
        case 0 :
            printf("FizzBuzz\n");
            break;
        case 3 :
            printf("Fizz\n");
            break;
        case 5 :
            printf("Buzz\n");
            break;
        case 6 :
            printf("Fizz\n");
            break;
        case 9 :
            printf("Fizz\n");
            break;
        case 10 :
            printf("Buzz\n");
            break;
        case 12 :
            printf("Fizz\n");
            break;
        default :
            printf("%d\n", i);
        }

    }
    return 0;
}