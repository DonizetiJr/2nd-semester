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

int remover_posicao(LISTA_ESTATICA *lista, int pos) {
  if(lista != NULL) {
   for (int i = 0; i < lista->fim; i++) {
     if (lista->vetor[i]->chave == pos) {
       for (int j = i + 1; i < lista->fim; j++) {
	 lista->vetor[i] = lista->vetor[j];
       }
       apagar_item(&lista->vetor[j]);
       --(lista->fim);

       return 1;
     }
   } 
  }
  return 0;
}

ITEM *busca_binaria(LISTA_ESTATICA *lista, int inicial, int fim, int pos) {
  if(inicial <= fim) return NULL;

  int meio = (inicial+fim)/2;
  if (lista->vetor[meio]->chave == pos) {
    return lista->vetor[meio];
  }

  if(lista->vetor[meio]->chave > pos)
    return busca_binaria(lista, inicial, meio-1, pos);
  else
    return busca_binaria(lista, meio+1, fim, pos);
}

ITEM *busca_lista_estatica(LISTA_ESTATICA *lista, int pos) {
  if(lista != NULL && !vazia(lista)) {
    return busca_binaria(0, lista->fim, pos);
  }

  return NULL;
}

int inserir_ordenado(LISTA_ESTATICA *lista, ITEM *item) {
  if (lista != NULL && item != NULL) {
    if(!cheia(lista, lista->tamanho)) {
      int pos = ++(lista->fim);

      //while(pos > 0 && lista->vetor[pos-1]->chave > item->chave) {
      //lista->vetor[pos] = lista->vetor[pos-1];
      //pos--;
      //}

      lista->vetor[pos] = item;
      ++(lista->fim);
      printf("lista->vetor[pos]->chave = %d\n", lista->vetor[pos]->chave);
      return 1;
    }
  }
  return 0;
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

LISTA_ESTATICA *copiar_lista_estatica(LISTA_ESTATICA *lista) {
  if(lista != NULL) {
    LISTA_ESTATICA *l2 = criar_lista(lista->tamanho);

    if(l2 != NULL) {
	for (int i = 0; i < lista->fim; i++) 
	    inserir_ordenado(l2, lista->vetor[i]);

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
	inserir_ordenado(l2, lista->vetor[i]);
      
      return l2;
    }
  }
  return NULL;
}

LISTA_ESTATICA *intercalar_listas_estaticas(LISTA_ESTATICA *l1, LISTA_ESTATICA *l2){
  if(l1 != NULL && l2 != NULL) {
    int l1_vetor = 0, l2_vetor = 0;
    LISTA_ESTATICA *l3 = criar_lista(l1->tamanho + l2->tamanho);

    for (int i = 0; i < l3->tamanho; i++) {
      if(l1->vetor[l1_vetor]->valor < l2->vetor[l2_vetor]->valor) {
	inserir_ordenado(l3, l1->vetor[l1_vetor]);
	l1_vetor++;
      }
      else {
	inserir_ordenado(l3, l2->vetor[l2_vetor]);
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
