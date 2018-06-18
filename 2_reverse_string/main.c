#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverser(char*, int);

int main()
{
    char word[] = "hesus!";
    int size = strlen(word) - 1;
    printf("%s\n", reverser(word, size));
    return 0;
}

char* reverser(char* word, int size){
    char temp_char;
    int i = 0;
    int j = size;

   while (i < j) {
      temp_char = word[i];
      word[i] = word[j];
      word[j] = temp_char;
      i++;
      j--;
   }
    return word;
}
