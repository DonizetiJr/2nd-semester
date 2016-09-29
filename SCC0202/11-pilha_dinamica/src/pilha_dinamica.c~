#include <stdlib.h>
#include <stdio.h>
#include <item.h>
#include <pilha_estatica.h>

#define TAM 100

struct pilha_estatica {
  ITEM *vetor[TAM];
  int topo;
};

PILHA_ESTATICA *criar_pilha_estatica(){
  PILHA_ESTATICA *pilha = (PILHA_ESTATICA *)malloc(sizeof(PILHA_ESTATICA));

  if (pilha != NULL) {
    pilha->topo = -1;
  }

  return pilha;
}

void apagar_pilha_estatica(PILHA_ESTATICA **pilha){
  if (pilha != NULL && *pilha != NULL) {
    for (int i = 0; i < TAM - (*pilha)->topo; i++) {
      ITEM *prem = desempilhar(*pilha);
      apagar_item(&prem);
    }

    free(*pilha);
    *pilha = NULL;
  }
}

int empilhar(PILHA_ESTATICA *pilha, ITEM *item){
  if (pilha != NULL && !pilha_cheia(pilha)) {
    pilha->topo++;
    pilha->vetor[pilha->topo] = item;
    return 1;
  }

  return 0;
}

ITEM *desempilhar(PILHA_ESTATICA *pilha){
  if (pilha != NULL && !pilha_vazia(pilha)) {
    ITEM *paux = pilha->vetor[pilha->topo];
    pilha->topo--;
    return paux;
  }

  return NULL;
}

ITEM *topo(PILHA_ESTATICA *pilha){
  if (pilha != NULL && !pilha_vazia(pilha)) {
    return pilha->vetor[pilha->topo];
  }
  
  return NULL;
}

int pilha_vazia(PILHA_ESTATICA *pilha){
  return(pilha->topo == -1);
}

int pilha_cheia(PILHA_ESTATICA *pilha){
  return(pilha->topo == TAM-1);
}

int tamanho_pilha_estatica(PILHA_ESTATICA *pilha){
  return (pilha->topo+1);
}

void imprimir_topo(PILHA_ESTATICA *pilha) {
  if (pilha != NULL && !pilha_vazia(pilha)) {
    imprimir_item(topo(pilha));
  }
}

