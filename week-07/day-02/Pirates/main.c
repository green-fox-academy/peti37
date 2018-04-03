#include <stdio.h>

/*
Create a struct that represents a pirate
It should store:
 - name
 - an int value which tells us if he/she has a wooden leg?
 - gold count
Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates
Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate
Create a function that takes an array of pirates (and it's length) then returns the name of the
richest that has wooden leg
*/

struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

int sum_of_golds(struct Pirate*, int);
int averagegolds(struct Pirate*, int);
char* richest(struct Pirate*, int);


int main()
{
    struct Pirate pirate[3];
    int size = sizeof(pirate)/sizeof(pirate[0]);
    strcpy(pirate[0].name, "Red Beard");
    pirate[0].has_wooden_leg = 1;
    pirate[0].gold_count = 200;

    strcpy(pirate[1].name, "Black Beard");
    pirate[1].has_wooden_leg = 0;
    pirate[1].gold_count = 500;

    strcpy(pirate[2].name, "Jack Sparrow");
    pirate[2].has_wooden_leg = 1;
    pirate[2].gold_count = 10;

    printf("Sum of golds: %d\n", sum_of_golds(pirate, size));
    printf("Average of golds: %d\n", average_golds(pirate, size));
    printf("Richest pirate who has wooden leg is: %s, DURRR!\n", richest(pirate, size));

    return 0;
}

int sum_of_golds(struct Pirate* pirate, int size){
    int gold_sum = 0;
    for (int i = 0; i < size; i++){
        gold_sum += pirate[i].gold_count;
    }
    return gold_sum;
}

int average_golds(struct Pirate* pirate, int size){
    int gold_sum = 0;
    for (int i = 0; i < size; i++){
        gold_sum += pirate[i].gold_count;
    }
    return gold_sum/size;
}

char* richest(struct Pirate* pirate, int size){
    int i, max_gold;
    max_gold = pirate[0].gold_count;

    for (i = 1; i < size; i++){
        if (pirate[i].gold_count > max_gold)
            max_gold = pirate[i].gold_count;
    }

    for (i = 0; i < size; i++){
        if (pirate[i].gold_count = max_gold && pirate[i].has_wooden_leg == 1)
            return pirate[i].name;
    }
    return NULL;
}
