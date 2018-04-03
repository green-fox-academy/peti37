#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct {
    char address[50];
    int price;
    int rooms;
    int area;
} house_t;

void worth_to_buy(house_t);
int how_many_worth(house_t*, int);

int main()
{
    house_t White = {"Washington dc", 5000000, 85, 500};
    worth_to_buy(White);

    house_t houses[3];
    int size = sizeof(houses)/sizeof(houses[0]);
    strcpy(houses[0].address, "Washington dc");
    houses[0].price = 500000;
    houses[0].rooms = 85;
    houses[0].area = 500;

    strcpy(houses[1].address, "Budapest...");
    houses[1].price = 10000;
    houses[1].rooms = 3;
    houses[1].area = 40;

    strcpy(houses[2].address, "Pecs");
    houses[2].price = 900;
    houses[2].rooms = 2;
    houses[2].area = 35;


    printf("Number of houses worth to buy is: %d\n", how_many_worth(houses, size));

    return 0;
}

void worth_to_buy(house_t house){
    if  (house.price / house.area < 400)
        printf("Yes, it is!\n");
    else
        printf("No, it is not!\n");
}

int how_many_worth(house_t* house, int size){
    int counter = 0;
    for(int i = 0; i < size; i++){
        if  (house[i].price / house[i].area < 400)
            counter++;
    }
    return counter;
}
