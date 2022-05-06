#ifndef CAT_H_
#define CAT_H_

#include "animal.h"

typedef struct {
    animal_t animal;
} cat_t;

cat_t *cat_new();

void cat_ctor(cat_t *);

void cat_dtor(cat_t *);

#endif /* CAT_H_ */