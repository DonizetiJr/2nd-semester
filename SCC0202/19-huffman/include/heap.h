#ifndef HEAP_H
#define HEAP_H

#include <arvore_binaria.h>

typedef struct heap_estatica HEAP_ESTATICA;

HEAP_ESTATICA *criar_heap();
void apagar_heap(HEAP_ESTATICA **heap);

int inserir_heap(HEAP_ESTATICA *heap, NO *no);
NO *remover_heap(HEAP_ESTATICA*heap);

int cheia(HEAP_ESTATICA *heap);
int vazia(HEAP_ESTATICA *heap);
int tamanho_heap(HEAP_ESTATICA *heap);
void print_heap(HEAP_ESTATICA *heap);

#endif
