#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "animal.h"
#include "cat.h"
#include "duck.h"


int main(int argc, char* argv[]) {

    animal_t *animal = animal_new();
    animal_ctor(animal);

    cat_t *cat = cat_new();
    cat_ctor(cat);

    duck_t *duck = duck_new();
    duck_ctor(duck);

    animal_sound(animal);
    animal_sound((animal_t *)cat);
    animal_sound((animal_t *)duck);

    animal_dtor(animal);
    free(animal);

    cat_dtor(cat);
    free(cat);

    duck_dtor(duck);
    free(duck);

    return EXIT_SUCCESS;
}