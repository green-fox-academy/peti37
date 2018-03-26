#include<stdio.h>

int main()
{
    // Modify this program int he printf() to greet user instead of the World!
    // The program should ask for the age of the user
    int chickens;
    int pigs;
    printf("Number of chickens?\n");
    scanf("%d", &chickens);
    printf("Number of pigs?\n");
    scanf("%d", &pigs);

    printf("All of these animals have %d legs.\n", chickens*2 + pigs*4);

    return 0;
}
