#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct complexo COMPLEXO;

COMPLEXO* create(int real, int im);

void erase(COMPLEXO** comp);

COMPLEXO* sum(COMPLEXO *comp1, COMPLEXO *comp2);

COMPLEXO* mult(COMPLEXO *comp1, COMPLEXO *comp2);

void print(COMPLEXO *comp); 

#endif
