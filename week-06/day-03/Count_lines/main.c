#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("programas.txt", "r");
    char single_line[150];
    int number_lines = 0;

    if(fptr == NULL)
        printf("ERROR opening file");
        return 0;

    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        number_lines++;
    }
    printf("%d\n", number_lines);
    fclose(fptr);
    return 0;
}
