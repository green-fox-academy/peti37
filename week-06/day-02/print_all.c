#include<stdio.h>

int main()
{
    int af[] = {4, 5, 6, 7};
    int i;
    for (i = 0; i < sizeof(af)/sizeof(af[0]); i++)
    {
        printf("%d\n", af[i]);
    }
    return 0;
}