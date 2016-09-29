#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>
#include <item.h>

typedef struct NO {
  ITEM *item;
  struct NO *proximo;
  struct NO *anterior;
} NO;
  
struct lista_ligada {
  NO *inicio;
  NO *fim;
  int tamanho;
};

LISTA_LIGADA *criar_lista() {
  LISTA_LIGADA *lista = (LISTA_LIGADA *)malloc(sizeof(LISTA_LIGADA));

  if(lista != NULL) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
  }
  
  return lista;
}

void apagar_no(NO *no) {
  apagar_item(&(no->item));
  free(no);
}

void apagar_lista(LISTA_LIGADA **lista) {
  if(lista != NULL && *lista != NULL) {
    NO *paux = (*lista)->inicio;
    NO *prem = NULL;

    while(paux != NULL) {
      prem = paux;
      paux = paux->proximo;
      apagar_no(prem);
    }
    free(*lista);
    *lista = NULL;
  }
}

int inserir_item_inicio(LISTA_LIGADA *lista, ITEM *item) {
  if(lista != NULL && !vazia(lista)) {
    NO *pnovo = (NO *)malloc(sizeof(NO));

    if (pnovo != NULL) {
      pnovo->item = item;
      pnovo->anterior = NULL;
      pnovo->proximo = lista->inicio;

      if (lista->inicio == NULL) {
	lista->fim = pnovo;
      } else {
	lista->inicio->anterior = pnovo;
      }

      lista->inicio = pnovo;
      lista->tamanho++;
    } 
    return 1;
  }
  return 0;
}

int inserir_item_fim(LISTA_LIGADA *lista, ITEM *item) {
  if(lista != NULL && !vaiza(lista)) {
    NO *pnovo = (NO *)malloc(sizeof(NO));

    if(pnovo != NULL) {
      pnovo->item = item;
      pnovo->proximo = NULL;
      pnovo->anterior = lista->fim;

      if(lista->fim == NULL) {
	lista->inicio = pnovo;
      } else {
	lista->fim->proximo = pnovo;
      }

      lista->fim = pnovo;
      lista->tamanho++;
      return 1;
    } 
  }
  return 0;
}

int remover_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL && !vaiza(lista)) {
    NO *prem = lista->inicio;

    while(prem != NULL && prem->item->chave != chave) {
      prem = prem->proximo;
    }

    if(prem != NULL) {
      if (prem == lista->inicio) { 
	lista->inicio = prem->proximo;
      } else {
	prem->anterior->proximo = prem->proximo;
      }
      
      if(prem == lista->fim) {
	lista->fim = prem->anterior;
      } else {
	prem->proximo->anterior = prem->anterior;
      }

      lista->tamanho--;
      apagar_no(prem);
      return 1;
    }
  }
  return 0;
}

ITEM *recuperar_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL) {
    NO *paux = lista->inicio;

    while(paux != NULL) {
      if(paux->item->chave == chave) {
	return paux->item;
      }
      paux = paux->proximo;
    }
  }
  return NULL;
}

int cheia(LISTA_LIGADA *lista) {
  return (lista == NULL);
}

int vazia(LISTA_LIGADA *lista){
  return (lista->inicio == NULL);
}

int tamanho(LISTA_LIGADA *lista){
  if(lista != NULL) {
    return (lista->tamanho);
  }
  return 0;
}

void imprimir_lista(LISTA_LIGADA *lista){
  if(lista != NULL && !vazia(lista)) {
    NO *paux = lista->inicio;

    while(paux != NULL) {
      imprimir_item(paux->item);
      paux = paux->proximo;
    }   
  }
}
