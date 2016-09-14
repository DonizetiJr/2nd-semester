#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

#define TAM 100

struct lista_estatica {
  ITEM *vetor[TAM];
  int fim;
};

LISTA_ESTATICA *criar_lista() {
  LISTA_ESTATICA *lista = (LISTA_ESTATICA *)malloc(sizeof(LISTA_ESTATICA));
  lista->fim = -1;

  return lista;
}

void apagar_lista(LISTA_ESTATICA **lista) {
  if(lista != NULL && *lista != NULL) {
     for (int i = 0; i <= (*lista)->fim; i++) {
       apagar_item(&((*lista)->vetor[i]));
     }
     free(*lista);
     *lista = NULL;
  }
}

int cheia(LISTA_ESTATICA *lista) {
  return (lista != NULL && lista->fim == TAM - 1);
}

int vazia(LISTA_ESTATICA *lista){
  return lista->fim == -1;
}

int tamanho(LISTA_ESTATICA *lista){
  if(lista != NULL) {
    return ++(lista->fim);
  }
  return 0;
}

int inserir_lista_estatica(LISTA_ESTATICA *lista, ITEM *item) {
  if (lista != NULL && item != NULL) {
    if(!cheia(lista)) {
      ++lista->fim;
      lista->vetor[lista->fim] = item;
      return 1;
    }
  }
  return 0;
}

ITEM *buscar_lista_estatica(LISTA_ESTATICA *lista, int target) {
  if(lista != NULL && vazia(lista)) {
    for (int i = 0; i <= lista->fim ; i++) {
      if (lista->vetor[i]->chave == target) {
	return lista->vetor[i];
      }
    }
  }
  
  return NULL;
}

void imprimir_lista(LISTA_ESTATICA *lista){
  if(lista != NULL && !vazia(lista)) {
    for (int i = 0; i <= lista->fim; i++) 
      imprimir_item(lista->vetor[i]);
  }
}
