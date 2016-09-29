#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#include <item.h>

typedef struct pilha_estatica PILHA_ESTATICA;

PILHA_ESTATICA *criar_pilha_estatica();
void apagar_pilha_estatica(PILHA_ESTATICA **pilha);

int empilhar(PILHA_ESTATICA *pilha, ITEM *item);
ITEM *desempilhar(PILHA_ESTATICA *pilha);
ITEM *topo(PILHA_ESTATICA *pilha);

int pilha_vazia(PILHA_ESTATICA *pilha);
int pilha_cheia(PILHA_ESTATICA *pilha);
int tamanho_pilha_estatica(PILHA_ESTATICA *pilha);
void imprimir_topo(PILHA_ESTATICA *pilha);


#endif
