#include <stdio.h>

// Create a struct to store coordinates (for example: int x and int y)
// Create an array which can store coordinates, do not create multidimensonal arrays here
// Fill up the coordinates in the array with random number.

typedef struct {
    int x;
    int y;
} Coordinates;

int main()
{
    Coordinates cords[10];

    for (int i = 0; i < 10; i++){
        cords[i].x = i;
        cords[i].y = i+1;
    }

     for (int i = 0; i < 10; i++){
            printf("x:%d, y:%d\n", cords[i].x, cords[i].y);
    }

	return 0;
}
