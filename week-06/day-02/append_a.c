#include<stdio.h>
#include<stdlib.h>

char* append_a(char*, int);

int main()
{
    char am[] = "kuty";
    int size = sizeof(am) / sizeof(char);
    char* appended_word = append_a(am, size);
    for(int i = 0; i < size+1; i++)
    {
        printf("%c", appended_word[i]);
    }
    //printf("%s\n", appended_word);
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