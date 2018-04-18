#include <stdio.h>
#include <stdlib.h>
int* resizer(int* array, int size, int new_size);
/**
 * Create a function called "resize" that takes a pointer to an int array, it's size and it's new size,
 * then it should return a new pointer that points to the new resized array.
 * It should copy all the elements to the new array, if the array is bigger it should fill all the new slots with zeros.
 * It should delete the old array.
 */

int main()
{
    printf("Hello\n");
    int array[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(array)/sizeof(array[0]);

    resizer(&array, size, 8);

    for(int i = 0; i < 8; i++)
    {
        printf("%d\n", resizer(&array, size, 8)[i]);
    }

    return 0;
}

int* resizer(int* array, int size, int new_size)
{
    int* new_array;
    new_array = (int*)calloc(new_size, sizeof(int));
    for(int i = 0; i < size; i ++)
    {
        new_array[i] = array[i];
    }
    array = (int *)realloc(array, 0);
    return new_array;
}
