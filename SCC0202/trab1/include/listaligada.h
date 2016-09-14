// include/listaligada.h

#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <item.h>

/* Nó que representará cada usuário. */
typedef struct no {
  ITEM *item;
  struct no *proximo;
  struct no *anterior;
} NO;

/* Lista duplamente ligada, circular com sentinela. */
typedef struct lista_ligada {
  NO *sentinela;
  NO *fim;
  int tamanho;
} LISTA_LIGADA;

LISTA_LIGADA *criar_lista();
void apagar_no(NO *no);

int cheia(LISTA_LIGADA *lista);
int vazia(LISTA_LIGADA *lista);
int tamanho(LISTA_LIGADA *lista);

#endif
