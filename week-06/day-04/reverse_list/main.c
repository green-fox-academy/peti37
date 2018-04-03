#include <stdio.h>
#include <stdlib.h>

// - Create an array variable named `aj`
//   with the following content: `[3, 4, 5, 6, 7]`
// - Reverse the order of the elements in `aj`
// - Print the elements of the reversed `aj`


int main()
{
    char A = 'A';
      int i;
      for (i = 0; i < 8; i++) {
          printf("%d", !!((A << i) & 0x80));
      }
      printf("\n");
    return 0;
}

