#include <stdio.h>
#include <stdlib.h>

int main()
{
    char path[] = "my-file.txt";
    int number = 5;
    char word[] = "Bumm!";

    write_lines(path, word, number);

    return 0;
}
void write_lines(char* path, char* word, int number)
{
    FILE *fptr;
    fptr = fopen(path, "w");

    for (int i = 0; i < number; ++i) {
        fprintf(fptr, "%s\n", word);
    }
    fclose(fptr);
}
