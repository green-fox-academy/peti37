#include <stdio.h>

// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

double GetSurface(struct rectangular_cuboid);
double GetVolume(struct rectangular_cuboid);

int main()
{
    struct rectangular_cuboid cube1 = {10, 10, 10};
    printf("cube1 surface is %.2f\n", GetSurface(cube1));
    printf("cube1 volume is %.2f\n", GetVolume(cube1));
    return 0;
}

double GetSurface(struct rectangular_cuboid cube){
    double surface = 2*cube.a*cube.b + 2*cube.a*cube.c + 2*cube.b*cube.c;
    return surface;
}

double GetVolume(struct rectangular_cuboid cube){
    double volume = cube.a * cube.b * cube.c;
    return volume;
}
