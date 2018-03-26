#include<stdio.h>

int main()
{
    double massInKg = 81.2;
    double heightInM = 1.78;
    double bmi;
    bmi = massInKg / (heightInM * heightInM);
    printf("%.2f\n", bmi);
    return 0;
}
