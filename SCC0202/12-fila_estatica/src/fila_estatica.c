#include<stdlib.h>
#include <stdio.h>
#include <item.h>
#include <fila_estatica.h>

#define TAM 100

struct fila_estatica {
  ITEM *vetor[TAM];
  int inicio;
  int fim;
};

FILA_ESTATICA *criar_fila(){
  FILA_ESTATICA *fila = (FILA_ESTATICA *)malloc(sizeof(FILA_ESTATICA));

  if (fila != NULL) {
    fila->fim = 0;
    fila->inicio = 0;
  }

  return fila;
}

void apagar_fila_estatica(FILA_ESTATICA **fila){
  if (fila != NULL && *fila != NULL) {
    for (int i = 0; i < tamanho_fila_estatica; i++) {
      apagar_item(desenfileirar(*fila));
    }

    free(*lista);
    *lista = NULL;
  }
}

int enfileirar(FILA_ESTATICA *fila, ITEM *item){
  if (fila != NULL && !fila_estatica_cheia(fila)) {
    fila->vetor[fila->fim] = item;
    fila->fim = (fila->fim + 1) % TAM;
    return 1;
  }
  
  return 0;
}

ITEM *desenfileirar(FILA_ESTATICA *fila){
  if (fila != NULL && !fila_Estatica_vazia(fila)) {
    ITEM *paux = fila->vetor[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM;
    return paux;
  }

  return NULL;
}

int fila_estatica_cheia(FILA_ESTATICA *fila){
  return ((fila->fim + 1) % TAM == fila->inicio);
}

int fila_estatica_vazia(FILA_ESTATICA *fila){
  return (fila->inicio == fila->fim);
}

int tamanho_fila_estatica(FILA_ESTATICA *fila){
  if (fila != NULL) {
    if (fila->inicio <= fila->fim) {
      return fila->fim - fila->inicio;
    } else {
      return TAM - fila->inicio + fila->fim;
    }
  }

  return 0;
}
