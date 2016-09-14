#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

#define TAM 500

typedef struct no {
  ITEM *item;
  int prox_indice; // próximo índex utilizado (ou -1)
} NO;

struct lista_estatica {
  NO *vetor[TAM]; // vetor de nós
  int fim; // indice do ultimo nó utilizado no vetor
};

LISTA_ESTATICA *criar_lista() {
  LISTA_ESTATICA *lista = (LISTA_ESTATICA *)malloc(sizeof(LISTA_ESTATICA));

  if(lista != NULL) {
    lista->vetor[0] = (NO *)malloc(sizeof(NO));
    lista->vetor[0]->item = NULL;
    lista->vetor[0]->prox_indice = -1;
    lista->fim = 0;
  }

  return lista;
}

void apagar_lista(LISTA_ESTATICA **lista) {
  if(lista != NULL && *lista != NULL) {
    int indice;
    NO *paux = (*lista)->vetor[0];
    indice = paux->prox_indice;

    while(indice != -1) {
      indice = paux->prox_indice; 
      apagar_item(&(paux->item));
      free(paux);

      paux = (*lista)->vetor[indice];
    }
     
     free(*lista);
     *lista = NULL;
  }
}

void remover_elemento(LISTA_ESTATICA *lista, int chave) {
  if (lista != NULL) {
    int indice = lista->vetor[0]->prox_indice;
    NO *paux = NULL;
    NO *prem = lista->vetor[indice];
    
    while (prem->item->chave != chave) {
      paux = prem;
      prem = lista->vetor[prem->prox_indice];
    }

    if (prem->prox_indice == -1) {
      lista->fim = paux->prox_indice;
    }
    
    paux->prox_indice = prem->prox_indice;
    apagar_item(&(prem->item));
    free(prem);
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

void inserir_lista_estatica(LISTA_ESTATICA *lista, ITEM *item, int prox_indice) {
  if (lista != NULL && item != NULL) {
    if(!cheia(lista)) {
      lista->vetor[lista->fim]->prox_indice = prox_indice;
      lista->fim = prox_indice;

      lista->vetor[lista->fim] = (NO *)malloc(sizeof(NO));
      lista->vetor[lista->fim]->item = item;
      lista->vetor[prox_indice]->prox_indice = -1;
      
    }
  }
}

ITEM *buscar_lista_estatica(LISTA_ESTATICA *lista, int target) {
  if(lista != NULL && vazia(lista)) {
    for (int i = 0; i <= lista->fim ; i++) {
      if (lista->vetor[i]->item->chave == target) {
	return lista->vetor[i]->item;
      }
    }
  }
  
  return NULL;
}

void imprimir_lista(LISTA_ESTATICA *lista){
   if(lista != NULL) {
    NO *paux = lista->vetor[0];
    int indice = paux->prox_indice;

    while(indice != -1) {
      indice = paux->prox_indice;
      imprimir_item(paux->item);
      paux = lista->vetor[indice];
    }
  }
}
