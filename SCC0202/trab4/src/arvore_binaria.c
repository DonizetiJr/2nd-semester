// Donizeti Carlos dos santos Junior 9393882

#include <stdlib.h>
#include <stdio.h>
#include <arvore_binaria.h>

#define FILHO_ESQ 0
#define FILHO_DIR 1

ARVORE_BINARIA *criar_arvore() {
  ARVORE_BINARIA *arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
  if (arvore != NULL) {
    arvore->raiz = NULL;
  }

  return arvore;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, NO *no) {
  arvore->raiz = (NO *)malloc(sizeof(NO));
   
  if (arvore != NULL) {
    arvore->raiz = no;
  }
  
  return arvore->raiz;
}

void apagar_arvore_aux(NO *raiz) {
  if (raiz != NULL) {
    apagar_arvore_aux(raiz->filhoesq);
    apagar_arvore_aux(raiz->filhodir);
    free(raiz);
  }
}

void apagar_arvore(ARVORE_BINARIA **arvore) {
  apagar_arvore_aux((*arvore)->raiz);
  free(*arvore);
  *arvore = NULL;
}
