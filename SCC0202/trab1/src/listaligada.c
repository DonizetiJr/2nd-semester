/* src/listaligada.c
   Operações essenciais de listas duplamente ligadas, circulares e com sentinela. */

#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>

/* Cria um nó que será colocado na lista. */
NO *criar_no(ITEM *item, NO *proximo, NO *anterior) {
  NO *novo = (NO *)malloc(sizeof(NO));

  /* Atribui os dados necessários para o estabelecimento do nó. */
  if(novo != NULL) {
    novo->item = item;
    novo->proximo = proximo;
    novo->anterior = anterior;

    return novo;
  }
  
  return NULL;
}

/* Libera a memória ocupada pelo nó. */
void apagar_no(NO *no) {
  apagar_item(&(no->item));
  free(no);
}

/* Aloca o nó representado pelo sentinela, atribuindo valores inválidos. */
void criar_sentinela(LISTA_LIGADA *lista) {
  if(lista != NULL) {
    char cpf[] = {-1};
    char primeiro_nome[] = {-1};
    char ultimo_nome[] = {-1};
    char telefone[] = {-1};
    
    lista->sentinela = criar_no(criar_item(cpf, primeiro_nome, ultimo_nome, telefone), NULL, NULL);

    /* Por ser lista circular, os nós anterior e posterior serão o próprio sentinela. */
    lista->sentinela->proximo = lista->sentinela;
    lista->sentinela->anterior = lista->sentinela;
  }
}

/* Cria uma lista duplamente ligada, circular, com sentinela incialmente vazia. */
LISTA_LIGADA *criar_lista() {
  LISTA_LIGADA *lista = (LISTA_LIGADA *)malloc(sizeof(LISTA_LIGADA));

  if(lista != NULL){
    criar_sentinela(lista);
    lista->fim = NULL;
    lista->tamanho = 0;
  }
  
  return lista;
}

/* Verifica se a lista está cheia, ie, não há mais memória disponível para alocar. */
int cheia(LISTA_LIGADA *lista) {
  return (lista == NULL);
}

/* Verifica se a lista está vazia. */
int vazia(LISTA_LIGADA *lista){
  return (lista->sentinela->proximo == lista->sentinela);
}

/* Retorna o número de nós presentes na lista. */
int tamanho(LISTA_LIGADA *lista){
  if(lista != NULL) {
    return (lista->tamanho);
  }
  return 0;
}
