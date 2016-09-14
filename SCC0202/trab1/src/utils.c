/*  src/utils.h
    Operações necessárias para um Sistema de Gerenciamento de Cadastro. */

#include <stdlib.h>
#include <stdio.h>
#include <utils.h>
#include <listaligada.h>
#include <item.h>
#include <string.h>

/* Libera toda a memória possivelmente alocada pelo sistema. */
void sair_gerenciamento(LISTA_LIGADA **lista) {
  if (lista != NULL && *lista != NULL) {
    if(!vazia(*lista)) {
      NO *prem = (*lista)->sentinela->proximo;
      NO *paux = prem;

      while (paux != (*lista)->sentinela) {
	prem = paux;
	paux = paux->proximo;
	apagar_no(prem);
      }
    }
    free(*lista);
    *lista = NULL;
  }
}

/* Cria um novo usuário com todas as informações fornecidas. */
void cadastro(LISTA_LIGADA *lista, char cpf[], char primeiro_nome[],
	      char ultimo_nome[], char telefone[]) {
  if(lista != NULL) {
    ITEM *item = criar_item(cpf, primeiro_nome, ultimo_nome, telefone);

    if (lista != NULL) {
      NO *pnovo = (NO *)malloc(sizeof(NO));

      if (pnovo != NULL) {
	pnovo->item = item;
	pnovo->proximo = lista->sentinela;

	if (lista->sentinela->proximo == lista->sentinela) {
	  /* Caso a lista esteja vazia. */
	  lista->sentinela->proximo = pnovo;
	  pnovo->anterior = lista->sentinela;
	} else {
	  /* Os novos usuários sempre serão armazenados no final da lista */
          pnovo->anterior = lista->fim;
          lista->fim->proximo = pnovo;
	}

	lista->fim = pnovo;
	lista->tamanho++;
      }
    }
  }
}

/* Busca o usuário na lista de acordo com o CPF e ao encontrar imprime seus dados. */
void buscar_cpf(LISTA_LIGADA *lista, char cpf[]){
  if (lista != NULL) {
    strcpy(lista->sentinela->item->cpf,cpf);
    NO *paux = lista->sentinela->proximo;
    
    while (strcmp(paux->item->cpf, cpf)){
      paux = paux->proximo;
    }

    /* Caso o nó encontrado não seja o prório sentinela */
    if(paux != lista->sentinela) {
      imprimir_item(paux->item);
    }
  }
}

/* Imprime na tela os dados de todos os usuários na ordem com que foram inseridos. */
void dump(LISTA_LIGADA *lista){
  if(lista != NULL && !vazia(lista)) {
    NO *paux = lista->sentinela->proximo;

    while (paux != lista->sentinela) {
      imprimir_item(paux->item);
      paux = paux->proximo;
    }
  }
}

/* Invalida os dados do usuário de acordo com o CPF, ie, libera a memória ocupada por ele. */
void remover_cpf(LISTA_LIGADA *lista, char cpf[]){
  if(lista != NULL) {
    strcpy(lista->sentinela->item->cpf,cpf);
    NO *prem = lista->sentinela->proximo;

    while (strcmp(prem->item->cpf, cpf)){
      prem = prem->proximo;
    }

    if (prem != lista->sentinela) {
      if (prem == lista->fim) {
	/* Caso o usuário seja o último da lista. */
	prem->anterior->proximo = lista->sentinela;
	lista->fim = prem->anterior;
      } else {
	prem->anterior->proximo = prem->proximo;
	prem->proximo->anterior = prem->anterior;
      }
    }
    
    lista->tamanho--;
    apagar_no(prem);
  }
}
