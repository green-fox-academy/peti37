#include<stdio.h>

int main()
{
    const double aSide = 115;
    const double bSide = 52;
    const double cSide = 66;
    double surface = 2*aSide*bSide + 2*aSide*cSide + 2*bSide*cSide;
    double volume = aSide * bSide * cSide;
    printf("Cuboid surface is: %.2f\n", surface);
    printf("Cuboid volume is is: %.2f\n", volume);

    return 0;
}
