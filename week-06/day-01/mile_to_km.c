#include<stdio.h>

int main()
{
    // Modify this program int he printf() to greet user instead of the World!
    // The program should ask for the age of the user
    int km;
    printf("Give me a distance in km!\n");
    scanf("%d", &km);

    printf("That is %.2f miles!\n", km*1.6);

    return 0;
}
