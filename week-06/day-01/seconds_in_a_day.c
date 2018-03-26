#include<stdio.h>

int main()
{
    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;
    int secondsOfADay = 24 * 60 * 60;
    printf("Remaining seconds of this day: %d", secondsOfADay - currentHours * 60 * 60 + 34 * 60 + 42);
    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    return 0;
}
