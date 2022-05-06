#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duck.h"

void __duck_sound(void *this) {
    animal_t* animal = (animal_t*)this;
    printf("%s: Quacks\n", animal->name);
}

duck_t *duck_new() {
    return (duck_t *)malloc(sizeof(duck_t));
}

void duck_ctor(duck_t *this) {
    animal_ctor((animal_t *)this);
    strcpy(this->animal.name, "Duck");
    this->animal.sound_func = __duck_sound;
}

void duck_dtor(duck_t *this) {
    animal_dtor((animal_t *)this);
}