#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

int main ()
{
	char string[55] = "This is a string for testing";
	int iCounter = 0;
	for(int h = 0; h < sizeof(string)/sizeof(string[0]); h++)
    {
        if(string[h] == 'i')
        {
            iCounter++;
        }
    }

	char* p;
	p = (char*)calloc(iCounter, sizeof(char));
	int i;
	int j = 0;
	for(i = 0; i < sizeof(string)/sizeof(string[0]); i++)
	{
	    if(string[i] == 'i')
        {
            p[j] = (char)i;
            j++;
        }
	}

	for(int h = 0; h < iCounter; h++){
        printf("%d\n", p[h]);
	}
	return 0;
}
