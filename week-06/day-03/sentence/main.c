#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

int main()
{
    //printf("Type in a sentence:\n\n");
    char string[256] = "Dumm dumm dumm!";
    //printf("%s", string);
    separator(string);

    return(0);
}

void separator(char* sentence)
{
    char* word = strtok(sentence, " ");
    while(word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
}
