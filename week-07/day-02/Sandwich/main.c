#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/
typedef struct {
    char name[20];
    float price;
    float weight;
} Sandwich;

float full_price(Sandwich, int);

int main()
{
    Sandwich sandwich;
    strcpy(sandwich.name, "cheesburger");
    sandwich.price = 290;
    sandwich.weight = 200;

    printf("The price of 3 CheesBurgers is %.f", full_price(sandwich, 3));

    return 0;
}

float full_price(Sandwich sandwich, int orders){
    float summed_price = sandwich.price * orders;
    return summed_price;
}
