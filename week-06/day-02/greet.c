#include <stdio.h>
#include <stdlib.h>

void greet(char*);

int main()
{
    char al[] = "GreenFox";
    greet(al);
    return 0;
}

void greet(char *name)
{
    printf("Hello, %s!\n", name);
}