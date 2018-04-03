#include <stdio.h>
#include <stdlib.h>

enum trans_type {MANUAL, AUTOMATIC, CVT, SEMI_AUTOMATIC, DUAL_CLUTCH};

typedef struct {
	char man_name[256];
	float price;
	int year_of_man;
	enum trans_type type;
} Car;

int get_older_cars_than(Car*, int, int);
int get_transmission_count(Car*, int, enum trans_type);


int main()
{
    Car cars[3];
    strcpy(cars[0].man_name, "Tesla");
    cars[0].price = 62700;
    cars[0].year_of_man = 2018;
    cars[0].type = AUTOMATIC;

    strcpy(cars[1].man_name, "Audi");
    cars[1].price = 800;
    cars[1].year_of_man = 2010;
    cars[1].type = MANUAL;

    strcpy(cars[2].man_name, "Ford");
    cars[2].price = 1200;
    cars[2].year_of_man = 2016;
    cars[2].type = MANUAL;

    int size = sizeof(cars)/sizeof(cars[0]);

    printf("Number of cars that are older then 1 year: %d\n", get_older_cars_than(cars, size, 1));
    printf("Number of cars that have Manual transmission: %d\n", get_transmission_count(cars, size, MANUAL));

    return 0;
}

int get_older_cars_than(Car* array, int size, int age){
    int i, counter;
    for (i = 0; i < size; i++){
        if (2018-array[i].year_of_man > 1)
            counter++;
    }
    return counter;
}

int get_transmission_count(Car* array, int size, enum trans_type type){
    int i;
    int counter = 0;
    for (i = 0; i < size; i++){
        if (array[i].type == type)
            counter++;
    }
    return counter;
}
