#include <stdio.h>
#include <stdlib.h>
#include <racional.h>

struct racional {
  int numerador;
  int denominador;
};

RACIONAL* create(int num, int den) {
  RACIONAL* rac = (RACIONAL*)malloc(sizeof(RACIONAL));

  if (rac != NULL) {
    rac->numerador = num;
    rac->denominador = den;
  }
  
  return rac;
}

void erase(RACIONAL **rac) {
  if(*rac != NULL) {
    free(*rac);
    *rac = NULL;
  }
}

RACIONAL* sum(RACIONAL *rac1, RACIONAL *rac2) {
  if(rac1 != NULL && rac2 != NULL) {
    return create(rac1->numerador*rac2->denominador +
		  rac1->denominador*rac2->numerador,
		  rac1->denominador*rac2->denominador); 
  }
  
  return NULL;
}

void print(RACIONAL *rac) {
  if(rac != NULL)
    printf("%d / %d\n", rac->numerador, rac->denominador);
}
