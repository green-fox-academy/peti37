#include <stdio.h>
#include <string.h>

// create a program which asks for full name and age
// and stores it in a char array
// parse that array to first_name, last_name, age (use tokenizing)
// print out the the stored variables
// example:
//   printf("Your name is: %s %s and you are %d years old", first_name, last_name, age);

int main ()
{
    char data[50];
    char* first_name;
    char* last_name;
    char* age;
    char* data_array;

    printf("Give me your fullname and your age: ");
    gets(data);

    for (char *p = strtok(data, " "); p != NULL; p = strtok(NULL, " "))
    {
        for (int i = 0; p != NULL; i++)
        {
            strcpy(data_array[i], p);
        }
    }
    first_name = data_array[0];
    last_name = data_array[1];
    age = data_array[2];
    printf("Your name is: %s %s and you are %s years old", first_name, last_name, age);
    return 0;
}
