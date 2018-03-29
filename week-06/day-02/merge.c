#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *array;
    int *array2;
    int *array3;
    int i, j, k, l, p, s;
    array = (int *)malloc(10 * sizeof(int));
    array2 = (int *)malloc(10 * sizeof(int));
    array3 = (int *)malloc(20 * sizeof(int));

    for (i = 0, j = 0; j < 10, i < 20; i+=2, j++)
        {
            array[j] = i;
            printf("%d ", array[j]);
        }
    printf("\n");

    for (k = 1, l = 0; l < 10, k <= 20; k += 2, l++)
        {
            array2[l] = k;
            printf("%d ", array2[l]);
        }

    printf("\n");
    int g = 0;
    int x = 1;
    for (s = 0; s < 10; s++)
    {
        array3[g] = array[s];
        array3[x] = array2[s];
        g += 2;
        x += 2;
    }
    for (p = 19; p >= 0; p--)
    {
        printf("%d ", array3[p]);
    }

    return 0;
}