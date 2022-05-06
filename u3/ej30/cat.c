#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cat.h"

void __cat_sound(void *this) {
    animal_t *animal = (animal_t *) this;
    printf("%s: Meow\n", animal->name);
}

// Memory allocator
cat_t *cat_new() {
    return (cat_t *)malloc(sizeof(cat_t));
}
// Constructor
void cat_ctor(cat_t *this) {
    animal_ctor((animal_t *)this);
    strcpy(this->animal.name, "Cat");
    this->animal.sound_func = __cat_sound;
}

void cat_dtor(cat_t *this) {
    animal_dtor((animal_t *)this);
}