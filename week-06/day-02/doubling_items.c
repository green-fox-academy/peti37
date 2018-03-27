#include <stdio.h>
#include <stdlib.h>

void double_items(int*);

int main()
{
	int ag[] = {3, 4, 5, 6, 7};
	double_items(ag);
	printf("%d\n", ag[1]);
    return 0;
}

void double_items(int* input_arr)
{
    for (int i = 0; i < sizeof(input_arr); i++)
    {
        input_arr[i] *= 2;
    }
}