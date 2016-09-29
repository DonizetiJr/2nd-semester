#include <stdlib.h>
#include <stdio.h>
#include <item.h>
#include <pilha_dinamica.h>

typedef struct no {
  ITEM *item;
  struct no *anterior;
} NO;

struct pilha_dinamica {
  NO *topo;
  int tamanho;
};

void apagar_no(NO *no) {
  if (no != NULL) {
    apagar_item(&(no->item));

    free(no);
    no = NULL;
  }
}

PILHA_DINAMICA *criar_pilha_dinamica(){
  PILHA_DINAMICA *pilha = (PILHA_DINAMICA *)malloc(sizeof(PILHA_DINAMICA));

  if (pilha != NULL) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
  }

  return pilha;
}

void apagar_pilha_dinamica(PILHA_DINAMICA **pilha){
  if (pilha != NULL && *pilha != NULL && !pilha_vazia(*pilha)) {
    NO *paux = (*pilha)->topo;

    while (paux != NULL) {
      NO *prem = paux;
      paux = paux->anterior;
      apagar_no(prem);
    }

    free(*pilha);
    *pilha = NULL;
  }
}

int empilhar(PILHA_DINAMICA *pilha, ITEM *item){
  if (pilha != NULL && !pilha_cheia(pilha)) {
    NO *pnovo = (NO *)malloc(sizeof(NO));
    if (pnovo != NULL) {
      pnovo->item = item;
      pnovo->anterior = pilha->topo;
      pilha->topo = pnovo;
      pilha->tamanho++;
    }
    return 1;
  }

  return 0;
}

ITEM *desempilhar(PILHA_DINAMICA *pilha){
  if (pilha != NULL && !pilha_vazia(pilha)) {
    NO *paux = pilha->topo;
    pilha->topo = pilha->topo->anterior;
    paux->anterior = NULL;
    pilha->tamanho--;
    return paux->item;
  }

  return NULL;
}

ITEM *topo(PILHA_DINAMICA *pilha){
  if (pilha != NULL && !pilha_vazia(pilha)) {
    return pilha->topo->item;
  }
  
  return NULL;
}

int pilha_vazia(PILHA_DINAMICA *pilha){
  return(pilha->topo == NULL);
}

int pilha_cheia(PILHA_DINAMICA *pilha){
  return(pilha == NULL);
}

int tamanho_pilha_dinamica(PILHA_DINAMICA *pilha){
  return (pilha->tamanho);
}

void imprimir_topo(PILHA_DINAMICA *pilha) {
  if (pilha != NULL && !pilha_vazia(pilha)) {
    imprimir_item(topo(pilha));
  }
}

