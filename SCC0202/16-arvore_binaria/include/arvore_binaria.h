#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <item.h>

typedef struct arvore_binaria ARVORE_BINARIA;
typedef struct no {
  ITEM *item;
  struct no *filhoesq;
  struct no *filhodir;
} NO;

ARVORE_BINARIA *criar_arvore();
void apagar_arvore(ARVORE_BINARIA **arvore);

NO *criar_raiz(ARVORE_BINARIA *arvore, ITEM *item);
NO *inserir_filho(int filho, NO *no, ITEM *item);
int arvore_vazia(ARVORE_BINARIA *arvore);

int qnt_nos(ARVORE_BINARIA *arvore);
int altura_arvore(ARVORE_BINARIA *arvore);
int maior_elemento(ARVORE_BINARIA *arvore)

#endif
