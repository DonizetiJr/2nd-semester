#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>
#include <item.h>

typedef struct NO {
  ITEM *item;
  struct NO *proximo;
} NO;
  
struct lista_ligada {
  NO *cabeca;
  NO *fim;
  int tamanho;
};

LISTA_LIGADA *criar_lista() {
  LISTA_LIGADA *lista = (LISTA_LIGADA *)malloc(sizeof(LISTA_LIGADA));

  if(lista != NULL) {
    lista->cabeca = (NO *)malloc(sizeof (NO));
    lista->cabeca->item = NULL;
    lista->cabeca->proximo = NULL;
    
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
    NO *paux = (*lista)->cabeca;
    NO *prem = paux->proximo;
    
    while (paux->proximo != NULL) {
      NO *prem = paux->proximo;
      paux->proximo = prem->proximo;

      apagar_no(prem);
    }
    
    free(*lista);
    *lista = NULL;
  }
}

int inserir_item(LISTA_LIGADA *lista, ITEM *item) {
  if(lista != NULL) {
    NO *pnovo = (NO *)malloc(sizeof (NO));

    if(pnovo != NULL) {
      pnovo->item = item;
      pnovo->proximo = NULL;
      if(lista->cabeca->proximo == NULL) {
	lista->cabeca->proximo = pnovo;
      } else {
	lista->fim->proximo = pnovo;
      }

      lista->fim = pnovo;
      lista->tamanho++;
      return 1;
    } else {
      return 0;
    }
  }
}

void remover_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL) {
    if (lista->cabeca->proximo != NULL) {
      NO *paux = lista->cabeca;

      while (paux->proximo != NULL &&
	     paux->proximo->item->chave != chave) {
	paux = paux->proximo;
      }

      if (paux->proximo != NULL) {
	NO *prem = paux->proximo;
	paux->proximo = prem->proximo;

	if (prem == lista->fim) {
	  lista->fim = paux;
	}
	apagar_no(prem);
	lista->tamanho--;
      }
    }
  }
}

ITEM *recuperar_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL) {
    NO *paux = lista->cabeca->proximo;

    while(paux != NULL) {
      if(paux->item->chave == chave) {
	return paux->item;
      }
      paux = paux->proximo;
    }
  }
  return NULL;
}

LISTA_LIGADA *separa(LISTA_LIGADA *lista, int chave) {
  if (lista != NULL) {
    LISTA_LIGADA *l2 = criar_lista();

    if(l2 != NULL) {
      NO *paux = lista->cabeca->proximo;

      while (paux != NULL &&
	     paux->item->chave != chave) {
	paux = paux->proximo;
      }

      NO *ptemp = paux;
      while (paux->proximo != NULL) {
	paux = paux->proximo;
	ITEM *item = criar_item(paux->item->chave, paux->item->valor);
	inserir_item(l2, item);
      }

      ptemp->proximo = NULL;
      lista->fim = ptemp;
    
      return l2;
    }
  }
  return NULL;
}

int cheia(LISTA_LIGADA *lista) {
  return (lista == NULL);
}

int vazia(LISTA_LIGADA *lista){
  return (lista->cabeca->proximo == NULL);
}

int tamanho(LISTA_LIGADA *lista){
  if(lista != NULL) {
    return (lista->tamanho);
  }
  return 0;
}

void imprimir_lista(LISTA_LIGADA *lista){
  if(lista != NULL && !vazia(lista)) {
    NO *paux = lista->cabeca->proximo;

    while(paux != NULL) {
      imprimir_item(paux->item);
      paux = paux->proximo;
    }   
  }
}
