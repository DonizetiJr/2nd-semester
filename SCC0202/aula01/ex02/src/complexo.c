#include <stdio.h>
#include <stdlib.h>
#include <complexo.h>

struct complexo {
  int real;
  int imaginario;
};

COMPLEXO* create(int real, int im) {
  COMPLEXO* comp = (COMPLEXO*)malloc(sizeof(COMPLEXO));

  if(comp != NULL) {
    comp->real = real;
    comp->imaginario = im;
  }

  return comp;
}

void erase(COMPLEXO** comp) {
  if(*comp != NULL) {
    free(*comp);
    *comp = NULL;
  }
}

COMPLEXO* sum(COMPLEXO *comp1, COMPLEXO *comp2) {
  if(comp1 != NULL && comp2 != NULL) {
    return create(comp1->real + comp2->real,
		  comp1->imaginario + comp2->imaginario);
  }
  return NULL;
}

COMPLEXO* mult(COMPLEXO *comp1, COMPLEXO *comp2) {
  if(comp1 != NULL && comp2 != NULL) {
    return create(comp1->real * comp2->real - comp1->imaginario * comp2->imaginario,
		  comp1->real * comp2->imaginario + comp1->imaginario * comp2->real);
  }
  return NULL;
}

void print(COMPLEXO *comp) {
  if(comp != NULL) {
    printf("%d + %di\n", comp->real, comp->imaginario);
  }
}

