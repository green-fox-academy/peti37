#include <stdio.h>
#include <stdlib.h>
int* range(int start, int until, int step);

/* Create a function called "range" that creates a new array and returns a pointer to it.
 * It should fill the array with numbers based on it's paramters.
 * It should take 3 paramters:
 * int from: the first number in the array
 * int to: it will fill the array till it would reach this number (so this number is not in the array)
 * int step: the step between the numbers
 *
 * Examples:
 * range(0, 10, 2) -> {0, 2, 4, 6, 8}
 * range(1, -8, -3) -> {1, -2, -5}
 *
 * It should delete any dynamically allocated resource before the program exits.
 */

int main()
{
    int start = 1;
    int until = 20;
    int step = 3;
    int size = (until - start) / step;
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", (int)range(start, until, step)[i]);
    }
    free(range(start, until, step));
    return 0;
}

int* range(int start, int until, int step)
{
    int size = (until - start) / step;
    int counter = 0;
    int * array;
    array = (int*)malloc(size);
    for(int i = start; i < until; i += step)
    {
        array[counter] = i;
        counter++;
    }
    return array;
}
