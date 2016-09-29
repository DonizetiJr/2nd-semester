/* Donizeti C dos Santos Junior  9393882 */

#include <stdlib.h>
#include <stdio.h>
#include <array_list.h>

typedef struct node {
  ITEM **list;        // vetor de ponteiros para itens
  int last;           // quantidade de elementos ocupados do vetor
  int size;           // tamanho do vetor
  int bigger_key;     // maior chave contida no nó
  struct node *next;
  struct node *back;  // lista duplamente ligada
} NODE;

struct array_list {
  NODE *sentinel;
  NODE *end;
  int arrayList_size;
};

NODE *create_node (ARRAY_LIST *arrayList, ITEM *item, int size, NODE *next, NODE *back) {
  NODE *new = (NODE *)malloc(sizeof(NODE));

  if (new != NULL) {
    new->list = (ITEM **)malloc(sizeof(ITEM *) * size);
    new->list[0] = item;
    new->last = 0;
    new->size = size;
    new->next = next;
    new->back = back;
    new->bigger_key = item->key;

    arrayList->end = new;

    return new;
  }

  return NULL;
}

void delete_node(NODE **node) {
  if (node != NULL && *node) {
    for (int i = 0; i < (*node)->last; i++) {
      delete_item(&((*node)->list[i]));
    }

    free((*node)->list);
    free(*node);
    *node = NULL;
  }
}

/* Cria a ArrayList e aloca toda memória necessária */
ARRAY_LIST *new_arrayList() {
  ARRAY_LIST *arrayList = (ARRAY_LIST *)malloc(sizeof(ARRAY_LIST));

  if (arrayList != NULL) {
    arrayList->sentinel = create_node(arrayList, create_item(-1,-1), 5, NULL, NULL);
    arrayList->sentinel->next = arrayList->sentinel; 
    arrayList->sentinel->back = arrayList->sentinel;

    arrayList->end = arrayList->sentinel;
    arrayList->arrayList_size = 5;
}

  return arrayList;
}

/* Insere o item no nó e ordena a partir de sua posição */
void insert_ordered(ARRAY_LIST *arrayList, NODE *node, ITEM *element) {
  if (node != NULL && element != NULL) {
    NODE *paux = arrayList->end;
    int index = paux->last;

    // shifta os itens para a direita
    if (paux->last == paux->size-1) {
      paux->next = create_node (arrayList, node->list[node->last], 2*(node->size), arrayList->sentinel, paux);
      arrayList->end = paux->next;
      arrayList->sentinel->back = paux->next;
      index--;
    }
    
    while (paux != node) {
      while(index > 0) {
	paux->list[index+1] = paux->list[index];
      }

      paux->list[index] = paux->back->list[paux->back->last];
      paux = paux->next;
      index = paux->last;
    }

    if (paux->last+1 == paux->size) paux->list[paux->last] = element;
    else paux->list[++(paux->last)] = element;
    
    index = paux->last;
    while (index > 0 && paux->list[index-1]->key > paux->list[index]->key) {
      ITEM *swap = paux->list[index-1];
      paux->list[index-1] = paux->list[index];
      paux->list[index] = swap;
      index--;
    }
  }  
}

/*  Adiciona um item ao arrayList */
int add_arrayList(ARRAY_LIST *arrayList, ITEM *element) {
  if (arrayList != NULL && element != NULL) {
    NODE *paux = arrayList->sentinel->next;
    
    if (paux == arrayList->sentinel) {
      paux = create_node (arrayList, element, 2*(arrayList->end->size), arrayList->sentinel,
		   arrayList->sentinel);
      arrayList->sentinel->next = paux;
      arrayList->sentinel->back = paux;
      arrayList->end = paux;
      
    } else {
      while (paux->next != arrayList->sentinel && paux->bigger_key < element->value) {
	paux = paux->next;
      }

      if (paux == arrayList->sentinel) {
	insert_ordered(arrayList, paux->back, element);
      } else {
	insert_ordered(arrayList, paux, element);
      }

      if (element->key > paux->bigger_key) {
	paux->bigger_key = element->key;
      }

    }  
    
    return 1;
  }

  return 0;
}

int binary_search(NODE *node, int key) {
  if (node != NULL) {
    int left = 0;
    int right = node->last;

    while(left <= right) {
      int middle = (left + right) / 2;

      if (node->list[middle]->key == key) {
	return 1;
      }

      if (node->list[middle]->key > key) {
	right = middle - 1;
      } else {
	left = middle + 1;
      }
    }
  }

  return 0;
}

/* Verifica no arraylist se existe um elemento com a chave informada */
int contains_arrayList(ARRAY_LIST *arrayList, int key) {
  if (arrayList != NULL) {
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      if (binary_search(paux, key)) return 1; 
      else paux = paux->next;
    }

    return 0;
  }

  return -1;
}

/* Recupera um item na posição informada */
ITEM *get_arrayList(ARRAY_LIST *arrayList, int pos) {
  if (arrayList != NULL) {
    int aux = 0;
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      if (paux->next->size > pos) {
	return paux->list[pos - aux];
      } else {
	aux += paux->next->size;
	paux = paux->next;
      }
    }
  }

  return NULL;
}

/* Retorna qual a posição do primeiro elemento com a chave informada */
int indexOf_arrayList(ARRAY_LIST *arrayList, int key) {
  if (arrayList != NULL) {
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      if (binary_search(paux, key)) {
	for (int i = 0; i <= paux->last; i++) {
	  if (paux->list[i]->key == key) return i;
	}
      } else {
	paux = paux->next;
      }
    }
  }

  return -1;
}

/* Imprime um novo subarray no intervalo [beginIndex, endIndex[ */
void sub_arrayList(ARRAY_LIST *arrayList, int beginIndex, int endIndex) {
  if (arrayList != NULL) {
    ARRAY_LIST *sub_arrayList = new_arrayList();
    NODE *paux = arrayList->sentinel->next;
    int index, counter = 0;

    while (paux->next != arrayList->sentinel && paux->next->size < beginIndex) {
      counter += paux->next->size;
      paux = paux->next;
    }   

    index = beginIndex - counter;
    
    for (int i = 0; i < endIndex - beginIndex; i++) {
      add_arrayList(sub_arrayList, create_item(paux->list[index]->key,
					       paux->list[index]->value));
      index++;
      if (index == paux->last) {
	index = 0;
	paux = paux->next;
      }
    }

    print_arrayList(sub_arrayList);
  }
}

/* Modifica um elemento do arrayList */
int set_arrayList(ARRAY_LIST *arrayList, int pos, int key, int value) {
  if (arrayList != NULL) {
    int index, aux = 0;
    ITEM *swap;
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      if (paux->next->size < pos) {
	aux += paux->next->size;
	paux = paux->next;

      } else {
	index = pos - aux;
	paux->list[index]->key = key;
	paux->list[index]->value = value;

	while (paux != arrayList->sentinel) {
	  if (index != 0) {
	    if (paux->list[index]->key < paux->list[index-1]->key) {
	      swap = paux->list[index-1];
	      paux->list[index-1] = paux->list[index];
	      paux->list[index] = swap;

	      index--;
	    } else if (index != paux->last) {
	      swap = paux->list[index+1];
	      paux->list[index+1] = paux->list[index];
	      paux->list[index] = swap;

	      index++;
	    } else {
	      if (paux->next != arrayList->sentinel &&
		  paux->list[index]->key > paux->next->list[0]->key) {

		swap = paux->next->list[0];
		paux->next->list[0] = paux->list[index];
		paux->list[index] = swap;

		index = 0;
		paux = paux->next;
	      }
	    }
	    
	  } else {
	    if (paux->back != arrayList->sentinel &&
		paux->list[index]->key < paux->back->list[paux->last]->key) {

	      swap = paux->back->list[paux->last];
	      paux->back->list[paux->last] = paux->list[index];
	      paux->list[index] = swap;

	      paux = paux->back;
	      index = paux->last;
	    } else if (index != paux->last &&
		       paux->list[index]->key > paux->list[index+1]->key) {

	      swap = paux->list[index+1];
	      paux->list[index+1] = paux->list[index];
	      paux->list[index] = swap;

	      index++;
	    }
	  }
	}
	

	return 1;
      }
    }
    
    return 0;
  }

  return -1;
}

/* Verifica se o arraylist está vazio */
int isEmpty_arrayList(ARRAY_LIST *arrayList) {
  return (arrayList->sentinel->next == arrayList->sentinel); 
}

/* Retorna o tamanho total do arraylist */
int size_arrayList(ARRAY_LIST *arrayList) {
  if (arrayList != NULL) {
    int size = 0;
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      size += paux->last+1;
      paux = paux->next;
    }

    return size;
  }

  return -1;
}

/* Desaloca a memória alocada pelo arraylist */
int destroy_arrayList(ARRAY_LIST **arrayList) {
  if (arrayList != NULL && *arrayList != NULL) {
    NODE *prem = (*arrayList)->sentinel->next;
    NODE *paux = prem;

    while (paux != (*arrayList)->sentinel) {
      prem = paux;
      paux = paux->next;
      delete_node(&prem);
    }
  }

  free(*arrayList);
  *arrayList = NULL;
}

/* imprime toda a lista */
void print_arrayList(ARRAY_LIST *arrayList) {
  if (arrayList != NULL) {
    NODE *paux = arrayList->sentinel->next;

    while (paux != arrayList->sentinel) {
      for (int i = 0; i <= paux->size; i++) {
	print_item(paux->list[i]);
      }

      paux = paux->next;
    }
  }
}


