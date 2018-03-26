#include<stdio.h>

int main()
{
    for (int i = 0; i <= 100; i++){
        if (i % 3 == 0 && i % 5 != 0){
            printf("Fizz\n");
        }
        else if (i % 5 == 0&& i % 3 != 0){
            printf("Buzz\n");
        }
        else if (i % 5 == 0 && i % 3 == 0){
            printf("Fizz-Buzz\n");
        }
        else {
            printf("%d\n", i);
        }
    }
    return 0;
}