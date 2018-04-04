#include <stdio.h>
#include <string.h>

int main()
{
    char sentence[] = "welcome to the real world";

    for (char *p = strtok(sentence, " "); p != NULL; p = strtok(NULL, " "))
    {
        printf("%s", p);
    }

    return 0;
}
