#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

float circle_area(float);

int main()
{

    float area = circle_area(10);
    printf("%.2f", area);
    return 0;
}

float circle_area(float radius){
    float area = 0;
    area = radius * radius * PI;
    return area;
}
