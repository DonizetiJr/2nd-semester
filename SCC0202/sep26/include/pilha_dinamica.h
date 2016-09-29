#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

#include <item.h>

typedef struct pilha_dinamica PILHA_DINAMICA;

PILHA_DINAMICA *criar_pilha_dinamica();
void apagar_pilha_dinamica(PILHA_DINAMICA **pilha);

int empilhar(PILHA_DINAMICA *pilha, ITEM *item);
ITEM *desempilhar(PILHA_DINAMICA *pilha);
ITEM *topo(PILHA_DINAMICA *pilha);

int pilha_vazia(PILHA_DINAMICA *pilha);
int pilha_cheia(PILHA_DINAMICA *pilha);
int tamanho_pilha_dinamica(PILHA_DINAMICA *pilha);
void imprimir_topo(PILHA_DINAMICA *pilha);


#endif
