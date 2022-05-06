#ifndef DUCK_H_
#define DUCK_H_

#include "animal.h"

typedef struct {
    animal_t animal;
} duck_t;

duck_t *duck_new();

void duck_ctor(duck_t *);

void duck_dtor(duck_t *);


#endif /* DUCK_H_ */