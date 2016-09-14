// include/item.h

#ifndef ITEM_H
#define ITEM_H

/* Dados de cada usuário cadastrado. */
typedef struct {
  char cpf[15];
  char primeiro_nome[15];
  char ultimo_nome[15];
  char telefone[20];
}ITEM;

ITEM *criar_item(char cpf[], char primeiro_nome[], char ultimo_nome[], char telefone[]);
void apagar_item(ITEM **item);
void imprimir_item(ITEM *item);

#endif
