#include <stdio.h>
#include <string.h>

int occurance(char*, int);

int main ()
{
    char str[] = "This is a sample strings";
    int size = sizeof(str)/sizeof(char);
    char *first, *last;
    //printf("%d\n", size);
    int distance = occurance(str, size);
    printf("%d", distance);

    return 0;
}

int occurance(char* sent, int size)
{
    int count_first = 0;
    int count_last = 0;

    for (int i = 0; i < size; i++){
        count_first++;
        if (sent[i] == 's'){
            break;
        }
    }

    for (int i = size-1; i >= 0; i--){
        count_last++;
        if (sent[i] == 's'){
            break;
        }
    }
    return size - count_first - (count_last-1);
}
