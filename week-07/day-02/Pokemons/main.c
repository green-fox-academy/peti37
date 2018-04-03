#include <stdio.h>
#include <stdlib.h>

enum poke_type {NORMAL, FIRE, WATER, ELECTRIC, GRASS, ICE, FIGHTING, POISION, GROUND, FLYING, PSYCHIC, BUG, ROCK, GHOST, DRAGON, DARK, STEEL, FAIRY};

typedef struct {
    char name[256];
    int age;
    float strength;
    float speed;
    enum poke_type type;
} Pokemon;

int get_faster(Pokemon*, int, float);

int main()
{
    Pokemon pokemons[10];
    strcpy(pokemons[0].name, "Bulbasaur");
    pokemons[0].age = 2;
    pokemons[0].strength = 5.6;
    pokemons[0].speed = 3.3;
    pokemons[0].type = GRASS;

    strcpy(pokemons[1].name, "Pikachu");
    pokemons[1].age = 1;
    pokemons[1].strength = 6.0;
    pokemons[1].speed = 7.3;
    pokemons[1].type = ELECTRIC;

    strcpy(pokemons[2].name, "Squirtle");
    pokemons[2].age = 4;
    pokemons[2].strength = 3.5;
    pokemons[2].speed = 4.1;
    pokemons[2].type = WATER;

    strcpy(pokemons[3].name, "Wartortle");
    pokemons[3].age = 5;
    pokemons[3].strength = 7.5;
    pokemons[3].speed = 5.0;
    pokemons[3].type = WATER;

    strcpy(pokemons[4].name, "Charmander");
    pokemons[4].age = 2;
    pokemons[4].strength = 4.5;
    pokemons[4].speed = 4.5;
    pokemons[4].type = FIRE;

    strcpy(pokemons[5].name, "Charizard");
    pokemons[5].age = 7;
    pokemons[5].strength = 9.1;
    pokemons[5].speed = 8.2;
    pokemons[5].type = FIRE;

    strcpy(pokemons[6].name, "Jigglypuff");
    pokemons[6].age = 1;
    pokemons[6].strength = 4.7;
    pokemons[6].speed = 1.2;
    pokemons[6].type = FAIRY;

    strcpy(pokemons[7].name, "Abra");
    pokemons[7].age = 5;
    pokemons[7].strength = 5.7;
    pokemons[7].speed = 4.2;
    pokemons[7].type = PSYCHIC;

    strcpy(pokemons[8].name, "Geodude");
    pokemons[8].age = 9;
    pokemons[8].strength = 5.1;
    pokemons[8].speed = 2.2;
    pokemons[8].type = ROCK;

    strcpy(pokemons[9].name, "Ratata");
    pokemons[9].age = 0;
    pokemons[9].strength = 1.0;
    pokemons[9].speed = 5.9;
    pokemons[9].type = NORMAL;

    int size = sizeof(pokemons)/sizeof(pokemons[0]);
    printf("The number of pokemons those are faster then 4.0 is: %d\n", get_faster(pokemons, size, 4.0));
    return 0;
}

int get_faster(Pokemon* pokes, int size, float speed){
    int i;
    int counter = 0;
    for(i = 0; i < size; i++){
        if(pokes[i].speed > speed)
            counter++;
    }
    return counter;
}
