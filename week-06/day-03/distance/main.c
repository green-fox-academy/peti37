#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurance of character 's'
void occurance(char*, int);

int main ()
{
    char str[] = "This is a sample string";
    int size = sizeof(str)/sizeof(char);
    char *first, *last;
    occurance(str, size);

    return 0;
}

void occurance(char* sent, int size)
{
    int count_first = 0;
    int count_last = 0;
    for (int i = 0; i < size; i++){
        while (sent[i] != 's'){
            count_first++;
        }
    }

    for (int i = size; i > 0; i--){
        while (sent[i] != 's'){
            count_last++;
        }
    }

    printf("%d\n", count_first);
    printf("%d\n", count_last);
}
