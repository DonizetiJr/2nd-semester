#ifndef LISTALIGADA_H
#define LISTALIGADA_H

#include <item.h>

typedef struct lista_ligada LISTA_LIGADA;

LISTA_LIGADA *criar_lista();
void apagar_lista(LISTA_LIGADA **lista);

int inserir_item_inicio(LISTA_LIGADA *lista, ITEM *item);
int inserir_item_fim(LISTA_LIGADA *lista, ITEM *item);
int remover_item(LISTA_LIGADA *lista, int chave);
ITEM *recuperar_item(LISTA_LIGADA *lista, int chave);

int vazia(LISTA_LIGADA *lista);
int cheia(LISTA_LIGADA *lista);
int tamanho(LISTA_LIGADA *lista);
void imprimir_lista(LISTA_LIGADA *lista);

#endif
