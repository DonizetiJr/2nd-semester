/* src/item.c
Contém funções que manipulam diretamente o conteúdo de cada item */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <item.h>

/* Cria o item e atribui todos os dados de cadastro fornecidos pelo usuario. */
ITEM *criar_item(char cpf[], char primeiro_nome[], char ultimo_nome[], char telefone[]) {
  ITEM *item = (ITEM *)malloc(sizeof(ITEM));

  if(item != NULL) {
    strcpy(item->cpf,cpf);
    strcpy(item->primeiro_nome,primeiro_nome);
    strcpy(item->ultimo_nome, ultimo_nome);
    strcpy(item->telefone, telefone);
  }

  return item;
}

/* Libera a memória ocupada pelo item. */
void apagar_item(ITEM **item) {
  if(item != NULL && *item != NULL) {
    free(*item);
    *item = NULL;
  }
}

/* Imprime na tela do usuário todo o cadastro do item pedido. */
void imprimir_item(ITEM *item) {
  if(item != NULL) {
    printf("Primeiro Nome: %s\n", item->primeiro_nome);
    printf("Ultimo Nome: %s\n", item->ultimo_nome);
    printf("CPF: %s\n", item->cpf);
    printf("Telefone: %s\n", item->telefone);
    printf("-----------------------------\n");
  }
}
