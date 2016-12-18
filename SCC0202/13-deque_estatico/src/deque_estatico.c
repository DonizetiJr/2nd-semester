#include<stdlib.h>
#include <stdio.h>
#include <item.h>
#include <deque_estatico.h>

#define TAM 100

struct deque_estatico {
  ITEM *vetor[TAM];
  int inicio;
  int fim;
};

DEQUE_ESTATICO *criar_fila(){
  DEQUE_ESTATICO *fila = (DEQUE_ESTATICO *)malloc(sizeof(DEQUE_ESTATICO));

  if (fila != NULL) {
    fila->fim = 0;
    fila->inicio = 0;
  }

  return fila;
}

void apagar_deque_estatico(DEQUE_ESTATICO **fila){
  if (fila != NULL && *fila != NULL) {
    for (int i = 0; i < tamanho_deque_estatico; i++) {
      apagar_item(desenfileirar(*fila));
    }

    free(*lista);
    *lista = NULL;
  }
}

int inserir_inicio(DEQUE_ESTATICO *deque, ITEM *item) {
  if (!deque_estatico_cheia(deque)) {
    deque->inicio = (deque->incio - 1 + TAM) % TAM;
    deque->vetor[deque->inicio] = item;
    return 1;
  }

  return 0;
}

int inserir_fim(DEQUE_ESTATICO *deque, ITEM *item) {
   if (!deque_estatico_cheia(deque)) {
     deque->vetor[deque->fim] = item;
     deque->fim = (deque->fim + 1) % TAM;
     return 1;
  }

  return 0;
}

ITEM *remover_inicio(DEQUE_ESTATICO *deque) {
  if (!deque_estatico_vazia(deque)) {
    ITEM *paux = deque->vetor[deque->inicio];
    deque->inicio = (deque->inicio + 1) % TAM;
    return paux;
  }

  return paux;
}

ITEM *remover_fim(DEQUE_ESTATICO *deque) {
   if (!deque_estatico_vazia(deque)) {
      ITEM *paux = deque->vetor[deque->inicio];
      deque->fim = (deque->fim - 1 + TAM) % TAM;
      return deque->vetor[deque->fim];
  }

  return NULL;
}

int deque_estatico_cheia(DEQUE_ESTATICO *fila){
  return ((fila->fim + 1) % TAM == fila->inicio);
}

int deque_estatico_vazia(DEQUE_ESTATICO *fila){
  return (fila->inicio == fila->fim);
}

int tamanho_deque_estatico(DEQUE_ESTATICO *fila){
  if (fila != NULL) {
    if (fila->inicio <= fila->fim) {
      return fila->fim - fila->inicio;
    } else {
      return TAM - fila->inicio + fila->fim;
    }
  }

  return 0;
}
