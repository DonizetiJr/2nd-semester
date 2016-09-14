#ifndef LISTAESTATICA_H
#define LISTAESTATICA_H

#include <item.h>

typedef struct lista_estatica LISTA_ESTATICA;

LISTA_ESTATICA *criar_lista(int tamanho);
void apagar_lista(LISTA_ESTATICA **lista);
int remover_posicao(LISTA_ESTATICA *lista, int chave);

int inserir_ordenado(LISTA_ESTATICA *lista, ITEM *item);
int vazia(LISTA_ESTATICA *lista);
int cheia(LISTA_ESTATICA *lista, int tamanho);
int tamanho(LISTA_ESTATICA *lista);

ITEM *buscar_lista_estatica(LISTA_ESTATICA *lista, int pos);
LISTA_ESTATICA *copiar_lista_estatica(LISTA_ESTATICA *lista);
void inverter_lista(LISTA_ESTATICA *lista);
LISTA_ESTATICA *inverter_em_nova_lista(LISTA_ESTATICA *lista); 
LISTA_ESTATICA *intercalar_listas_estaticas(LISTA_ESTATICA *l1, LISTA_ESTATICA *l2);

void imprimir_lista(LISTA_ESTATICA *lista);

#endif
