#include<stdio.h>

int main()
{
    int matrix[4][4];
    int i, j, k, l;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 1;
            }
            else
            {
               matrix[i][j] = 0;
            }
        }
    }

    for (k = 0; k < 4; k++)
    {
        for (l = 0; l < 4; l++)
        {
            printf("%d ", matrix[k][l]);
        }
        printf("\n");
    }
    return 0;
}