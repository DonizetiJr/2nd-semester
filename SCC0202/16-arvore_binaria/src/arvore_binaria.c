#include <stdlib.h>
#include <stdio.h>
#include <arvore_binaria.h>

#define FILHO_ESQ 0
#define FILHO_DIR 1

struct arvore_binaria {
  NO *raiz;
};

ARVORE_BINARIA *criar_arvore() {
  ARVORE_BINARIA *arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
  if (arvore != NULL) {
    arvore->raiz = NULL;
  }

  return arvore;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, ITEM *item) {
  arvore->raiz = (NO *)malloc(sizeof(NO));

  if (arvore != NULL) {
    arvore->raiz->filhodir = NULL;
    arvore->raiz->filhoesq = NULL;
    arvore->raiz->item = item;
  }

  return arvore->raiz;
}

void apagar_arvore_aux(NO *raiz) {
  if (raiz != NULL) {
    apagar_arvore_aux(raiz->filhoesq);
    apagar_arvore_aux(raiz->filhodir);
    apagar_item(&(raiz->item));
    free(raiz);
  }
}

void apagar_arvore(ARVORE_BINARIA **arvore) {
  apagar_arvore_aux((*arvore)->raiz);
  free(*arvore);
  *arvore = NULL;
}

NO *inserir_filho(int filho, NO *no, ITEM *item) {
  NO *pnovo = (NO *)malloc(sizeof(NO));

  if (pnovo != NULL) {
    pnovo->filhodir = NULL;
    pnovo->filhoesq = NULL;
    pnovo->item = item;

    if (filho == FILHO_ESQ) {
      no->filhoesq = pnovo;
    } else if (filho == FILHO_DIR) {
      no->filhodir = pnovo;
    }
  }

  return pnovo;
}

int arvore_vazia(ARVORE_BINARIA *arvore) {
  return (arvore == NULL || arvore->raiz == NULL);
}

int qnt_nos_aux(NO *raiz) {
  int qnt_esq = qnt_nos_aux(raiz->filhoesq);
  int qnt_dir = qnt_nos_aux(raiz->filhodir);

  return (qnt_esq + qnt_dir);
}

int qnt_nos(ARVORE_BINARIA *arvore) {
  return qnt_nos_aux(arvore->raiz);
}

int altura_arvore_aux(NO *no) {
  if (no == NULL) return -1;
  int esq = altura_arvore_aux(no->filhoesq);
  int dir = altura_arvore_aux(no->filhodir);
  return ((esq > dir) ? esq : dir) + 1;
}

int altura_arvore(ARVORE_BINARIA *arvore) {
  return altura_arvore_aux(arvore->raiz);
}

int maior_elemento_aux(NO *no) {
   if (no == NULL) return -1;

   int esq = maior_elemento_aux(no->filhoesq);
   int dir = maior_elemento_aux(no->filhodir);
   if (no->item->valor > esq && no->item->valor > dir) {
      return no->item->valor;
   } else {
      return (esq > dir) ? esq : dir;
   }
}

int maior_elemento(ARVORE_BINARIA *arvore) {
   return maior_elemento_aux(arvore->raiz);
}

int soma_elementos(NO *no) {
   if (no == NULL) return no->item->valor;

   int esq = soma_elementos_aux(no->filhoesq);
   int dir = soma_elementos_aux(no->filhodir);
   return (esq + dir);
}

int soma_elementos(ARVORE_BINARIA *arvore) {
   return (soma_elementos_aux(arvore->raiz) + arvore->raiz->item->valor);
}
