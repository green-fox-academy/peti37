
#include <stdio.h>
#include <stdlib.h>

// - Create a two dimensional array
//   which can contain the different shades of specified colors
// - In `colors[0]` store the shades of green:
//   `"lime", "forest green", "olive", "pale green", "spring green"`
// - In `colors[1]` store the shades of red:
//   `"orange red", "red", "tomato"`
// - In `colors[2]` store the shades of pink:
//   `"orchid", "violet", "pink", "hot pink"

int main()
{
	int i, j;
    char* colors[3][5] = {
        {"lime", "forest green", "olive", "pale green", "spring green"},
        {"orange red", "red", "tomato" },
        {"orchid", "violet", "pink", "hot pink"}
        };
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            printf("matrix[%d][%d] is %s\n", i, j, colors[i][j]);
        }
    }
    return 0;
}