#include <stdio.h>
#include <stdlib.h>

// - Create an array variable named `abc`
//   with the following content: `["first", "second", "third"]`
// - Swap the first and the third element of `abc` by using a function
// - That function should take an array as a parameter and return the correct array
char* swap(char**);

int main()
{
	char* abc[3] = {"first", "second", "third"};
	swap(abc);
    for (int i = 0; i < sizeof(abc)/sizeof(char*); i++){
        printf("%s\n", abc[i]);
    }
    return 0;
}

char* swap(char** input_arr){
    char* temp_string = input_arr[0];
    input_arr[0] = input_arr[1];
    input_arr[1] = temp_string;
    return input_arr;
}
