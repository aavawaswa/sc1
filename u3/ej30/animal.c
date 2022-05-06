#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "animal.h"

void __animal_sound(void *this) {
    animal_t* animal = (animal_t *)this;
    printf("%s: Beeeep\n", animal->name);
}

animal_t *animal_new() {
    return (animal_t *)malloc(sizeof(animal_t));
}

void animal_ctor(animal_t *this) {
    this->name = (char *)malloc(10 * sizeof(char));
    strcpy(this->name, "Animal");
    this->sound_func = &__animal_sound;
}

void animal_dtor(animal_t *this) {
    free(this->name);
}

void animal_get_name(animal_t *this, char *buffer) {
    strcpy(buffer, this->name);
}

void animal_sound(animal_t *this) {
    this->sound_func(this);
}