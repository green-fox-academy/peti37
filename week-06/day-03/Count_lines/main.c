#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("program.txt", "r");
    char single_line[150];
    int number_lines = 0;

    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        number_lines++;
    }
    if(fptr == NULL)
        {
        printf("ERROR opening file");
        return 0;
        }
    printf("%d\n", number_lines);
    fclose(fptr);
    return 0;
}
