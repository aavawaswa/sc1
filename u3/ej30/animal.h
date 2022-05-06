#ifndef ANIMAL_H_
#define ANIMAL_H_

typedef void (*sound_func_t)(void *);

typedef struct {
    char *name;
    // This member is a pointer to the function which
    // performs the actual sound behavior
    sound_func_t sound_func;
} animal_t;


animal_t *animal_new();

void animal_ctor(animal_t *);
void animal_dtor(animal_t *);

void animal_get_name(animal_t *, char *);
void animal_sound(animal_t *);

#endif /* ANIMAL_H_ */