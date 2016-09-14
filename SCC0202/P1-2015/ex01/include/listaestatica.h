#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <item.h>

typedef struct lista_estatica LISTA_ESTATICA;

LISTA_ESTATICA *criar_lista();
void apagar_lista(LISTA_ESTATICA **lista);
void remover_elemento(LISTA_ESTATICA *lista, int chave);

int vazia(LISTA_ESTATICA *lista);
int cheia(LISTA_ESTATICA *lista);
int tamanho(LISTA_ESTATICA *lista);
void inserir_lista_estatica(LISTA_ESTATICA *lista, ITEM *item, int prox_indice);
ITEM *buscar_lista_estatica(LISTA_ESTATICA *lista, int target);
void imprimir_lista(LISTA_ESTATICA *lista);


#endif
