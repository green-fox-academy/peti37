#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fptr;
    FILE* fptrRead;
    fptr = fopen("my-file.txt", "w");
    char single_line[150];
    char name[] = "Nemeth Peter";
    fprintf(fptr, "%s", name);
    fclose(fptr);

    fptrRead = fopen("my-file.txt", "r");
    while(!feof(fptr)){
        fgets(single_line, 150, fptr);
        printf("%s", single_line);
    }
    fclose(fptr);
    return 0;
}
