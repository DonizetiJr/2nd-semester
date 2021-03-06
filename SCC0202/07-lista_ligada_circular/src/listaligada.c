#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>
#include <item.h>

typedef struct NO {
  ITEM *item;
  struct NO *proximo;
} NO;
  
struct lista_ligada {
  NO *sentinela;
  NO *fim;
  int tamanho;
};

NO *criar_no(ITEM *item, NO *proximo) {
  NO *novo = (NO *)malloc(sizeof(NO));

  novo->item = item;
  novo->proximo = proximo;

  return novo;
}

void apagar_no(NO *no) {
  apagar_item(&(no->item));
  free(no);
}

LISTA_LIGADA *criar_lista() {
  LISTA_LIGADA *lista = (LISTA_LIGADA *)malloc(sizeof(LISTA_LIGADA));

  if(lista != NULL) {
    lista->sentinela = criar_no(criar_item(-1,-1), NULL);
  
    printf("Debug criação de lista->sentinela\n");
    
    lista->sentinela->proximo = lista->sentinela;
    lista->fim = lista->sentinela;
    lista->tamanho = 0;
  }
  
  return lista;
}

void apagar_lista(LISTA_LIGADA **lista) {
  if(lista != NULL && *lista != NULL) {
    NO *prem = (*lista)->sentinela->proximo;
    NO *paux = NULL;

    while(paux != (*lista)->sentinela) {
      paux = prem->proximo;
      apagar_no(prem);
      prem = paux;
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
      
      lista->fim->proximo = pnovo;
      pnovo->proximo = lista->sentinela;
      lista->fim = pnovo;
      lista->tamanho++;
      return 1;
    } else {
      return 0;
    }
  }
}

int remover_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL) {
    if(!vazia(lista)) {
      NO *paux = lista->sentinela;

      while(paux->proximo->item->chave != chave) {
	paux = paux->proximo;
      }

      if(paux != lista->sentinela) {
	NO *prem = paux->proximo;
	paux->proximo = prem->proximo;

	if(prem == lista->fim) lista->fim = paux;

	apagar_no(prem);
	lista->tamanho--;
	return 1;
      }
    }
  }
  return 0;
}

ITEM *recuperar_item(LISTA_LIGADA *lista, int chave) {
  if(lista != NULL) {
    lista->sentinela->item->chave = chave;
    NO *paux = lista->sentinela;

    do {
      paux = paux->proximo;
    } while (paux->item->chave != chave);

    return (paux != lista->sentinela) ? paux->item : NULL;
  }
  return NULL;
}

int cheia(LISTA_LIGADA *lista) {
  return (lista == NULL);
}

int vazia(LISTA_LIGADA *lista){
  return (lista->sentinela == lista->fim);
}

int tamanho(LISTA_LIGADA *lista){
  if(lista != NULL) {
    return (lista->tamanho);
  }
  return 0;
}

void imprimir_lista(LISTA_LIGADA *lista){
  if(lista != NULL && !vazia(lista)) {
    NO *paux = lista->sentinela->proximo;

    while(paux != lista->sentinela) {
      imprimir_item(paux->item);
      paux = paux->proximo;
    }   
  }
}
