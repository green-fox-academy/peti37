#include<stdio.h>
#include<stdlib.h>

char* append_a(char*, int);

int main()
{
    char am[] = "kuty";
    int size = sizeof(am);
    printf("%s", append_a(am, size));

    return 0;
}

char* append_a(char *name, int size)
{
    char* new_name;
    new_name = (char *)malloc((size+1) * sizeof(char));
    new_name = name;
    new_name[size-1] = 'a';
    new_name[size] = '\0';
    return new_name;
}
