#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

struct lista_estatica {
  ITEM **vetor;
  int fim;
  int tamanho;
};

LISTA_ESTATICA *criar_lista(int tamanho) {
  LISTA_ESTATICA *lista = (LISTA_ESTATICA *)malloc(sizeof(LISTA_ESTATICA));

  if(lista != NULL) {
    lista->vetor = (ITEM **)malloc(sizeof(ITEM *)*tamanho);

    if (lista->vetor != NULL) {
      lista->fim = -1;
      lista->tamanho = tamanho;
    } else {
      free(lista);
      lista = NULL;
    }
  }

  return lista;
}

void apagar_lista(LISTA_ESTATICA **lista) {
  if(lista != NULL && *lista != NULL) {
     for (int i = 0; i <= (*lista)->fim; i++) {
       apagar_item(&((*lista)->vetor[i]));
     }
     free((*lista)->vetor);
     free(*lista);
     *lista = NULL;
  }
}

int cheia(LISTA_ESTATICA *lista, int tamanho) {
  return (lista != NULL && lista->fim == lista->tamanho - 1);
}

int vazia(LISTA_ESTATICA *lista){
  return lista->fim == -1;
}

int tamanho(LISTA_ESTATICA *lista){
  if(lista != NULL) {
    return ++(lista->fim);
  }
  return 0;
}

int inserir_lista_estatica(LISTA_ESTATICA *lista, ITEM *item) {
  if (lista != NULL && item != NULL) {
    if(!cheia(lista, lista->tamanho)) {
      ++lista->fim;
      lista->vetor[lista->fim] = item;
      return 1;
    }
  }
  return 0;
}

ITEM *buscar_lista_estatica(LISTA_ESTATICA *lista, int target) {
  if(lista != NULL && vazia(lista)) {
    for (int i = 0; i <= lista->fim ; i++) {
      if (lista->vetor[i]->chave == target) {
	return lista->vetor[i];
      }
    }
  }
  return NULL;
}

LISTA_ESTATICA *copiar_lista_estatica(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    LISTA_ESTATICA *l2 = criar_lista(lista->tamanho);

    if(l2 != NULL) {
	for (int i = 0; i < lista->fim; i++) 
	    inserir_lista_estatica(l2, lista->vetor[i]);

	return l2;
    }
  }
  return NULL;
}

void inverter_lista(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    ITEM *aux = criar_item(0,0);

    for (int i = 0; i < (lista->fim + 1)/2; i++) {
      aux = lista->vetor[lista->fim - i];
      lista->vetor[lista->fim - i] = lista->vetor[i];
      lista->vetor[i] = aux;
    }
  }
}

LISTA_ESTATICA *inverter_em_nova_lista(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    LISTA_ESTATICA *l2 = criar_lista(lista->tamanho);

    if(l2 != NULL) {
      for (int i = lista->fim; i >= 0; i--) 
	inserir_lista_estatica(l2, lista->vetor[i]);
      
      return l2;
    }
  }
  return NULL;
}

int lista_estatica_crescente(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    int menor = lista->vetor[0]->valor;
    for (int i = 1; i < lista->tamanho; i++) {
      if(lista->vetor[i]->valor <= menor) return 0;
      menor = lista->vetor[i]->valor;
    }
    return 1;
  }
  return 0;
}

int lista_estatica_decrescente(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    int maior = lista->vetor[0]->valor;

    for (int i = 1; i <lista->tamanho; i++) {
      if(lista->vetor[i]->valor >= maior) return 0;
      maior = lista->vetor[i]->valor;
    }
    return 1;
  }
  return 0;
}

LISTA_ESTATICA *intercalar_listas_estaticas(LISTA_ESTATICA *l1, LISTA_ESTATICA *l2){
  if(l1 != NULL && l2 != NULL) {
    int l1_vetor = 0, l2_vetor = 0;
    LISTA_ESTATICA *l3 = criar_lista(l1->tamanho + l2->tamanho);

    for (int i = 0; i < l3->tamanho; i++) {
      if(l1->vetor[l1_vetor]->valor < l2->vetor[l2_vetor]->valor) {
	inserir_lista_estatica(l3, l1->vetor[l1_vetor]);
	l1_vetor++;
      }
      else {
	inserir_lista_estatica(l3, l2->vetor[l2_vetor]);
	l2_vetor++;
      }
    }
    return l3;
  }
  return NULL;
}


void imprimir_lista(LISTA_ESTATICA *lista){
  if(lista != NULL && !vazia(lista)) {
    for (int i = 0; i <= lista->fim; i++) 
      imprimir_item(lista->vetor[i]);
  }
}
