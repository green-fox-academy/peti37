#include <stdio.h>

// print out the ascii values of the array

int main()
{
    int array[] = { 103, 114, 101, 101, 110, 32, 102, 111, 120};
    for(int i = 0; i < sizeof(array)/sizeof(int); i++)
    {
        printf("%c", array[i]);
    }
    return 0;
}
