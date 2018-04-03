#include <stdio.h>

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct car {
	enum car_type type;
	double km;
	double gas;
};

void stats(struct car);

int main()
{
	struct car volvo = {VOLVO, 200000, 50};
	struct car tesla = {TESLA, 10000, 0};

    stats(volvo);
    stats(tesla);

	return 0;
}

void stats(struct car c){
    switch (c.type){
    case TESLA:
        printf("Name: Tesla,\nKms:%.2f\n\n", c.km);
        break;
    case VOLVO:
        printf("Name: Volvo,\nGas amount: %d,\nKms:%.2f\n\n",(int)c.gas, c.km);
    }
}
