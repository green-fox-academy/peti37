#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("program.txt", "r");
    char single_line[150];

    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        printf("%s", single_line);
    }
    fclose(fptr);
    return 0;
}
