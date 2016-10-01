/* Donizeti C dos Santos Junior  9393882 */

#include <stdlib.h>
#include <stdio.h>
#include <array_list.h>

typedef struct node {
  ITEM **list;        // vetor de ponteiros para itens
  int last;           // quantidade de elementos ocupados do vetor
  int size;           // tamanho do vetor
  int bigger_key;     // maior chave contida no nó

  // lista duplamente ligada
  struct node *next;
  struct node *back; 
} NODE;

struct array_list {
  NODE *head;
  NODE *end;
};

/* Cria um nó para ser colocado no arrayList e atribui todas as suas propriedades */
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

/* Libera da memória o espaço alocado pelos itens do vetor e pelo nó */
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
    arrayList->head = create_node(arrayList, create_item(-1,-1), 5, NULL, NULL);

    // Atribuição paraa lista circular
    arrayList->head->next = arrayList->head; 
    arrayList->head->back = arrayList->head;

    arrayList->end = arrayList->head;
}

  return arrayList;
}

/* Insere o item no nó e ordena a partir de sua posição */
void insert_ordered(ARRAY_LIST *arrayList, NODE *node, ITEM *element) {
  if (node != NULL && element != NULL) {
    NODE *paux = arrayList->end;
    int index = paux->last;

    /* shifta os itens para a direita  */

    // O nó está cheio
    if (paux->last == paux->size-1) { 
      paux->next = create_node (arrayList, element, 2*(node->size), arrayList->head, paux);
      arrayList->end = paux->next;
      arrayList->head->back = paux->next;

      // Troca o último item do nó com o primeiro do próximo
      if (paux->next->list[0] < paux->list[index]) {
	ITEM *swap = paux->next->list[0];
	paux->next->list[0] = paux->list[index];
	paux->list[index] = swap;
      }

      return;
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

    // Ordenação dentro do nó
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
    NODE *paux = arrayList->head->next;

    // Encontra o item na posição digitada
    if (paux == arrayList->head) {
      paux = create_node (arrayList, element, 2*(arrayList->end->size), arrayList->head,
		   arrayList->head);
      arrayList->head->next = paux;
      arrayList->head->back = paux;
      arrayList->end = paux;
      
    } else {
      while (paux->next != arrayList->head && paux->bigger_key < element->value) {
	paux = paux->next;
      }

      if (paux == arrayList->head) {
	insert_ordered(arrayList, paux->back, element);
      } else {
	insert_ordered(arrayList, paux, element);
      }

      // Atualiza a maior chave do vetor
      if (element->key > paux->bigger_key) {
	paux->bigger_key = element->key;
      }
    }  
    
    return 1;
  }

  return 0;
}

/* Algoritmo de busca binária */
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
    NODE *paux = arrayList->head->next;

    while (paux != arrayList->head) {
      if (binary_search(paux, key)) return 1; 
      else paux = paux->next;
    }

  }

  return 0;
}

/* Recupera um item na posição informada */
void get_arrayList(ARRAY_LIST *arrayList, int pos) {
  if (arrayList != NULL) {
    NODE *paux = arrayList->head->next;
    int counter = 0, aux = paux->size;

    while (paux->next != arrayList->head && pos >= aux) {
      counter += paux->size;
      paux = paux->next;
      aux += paux->size;
    }

    print_item(paux->list[pos -  counter]);
  }
}

/* Retorna qual a posição do primeiro elemento com a chave informada */
void indexOf_arrayList(ARRAY_LIST *arrayList, int key) {
  if (arrayList != NULL) {
    int counter = 0;
    NODE *paux = arrayList->head->next;

    while (paux != arrayList->head) {
      if (binary_search(paux, key)) {
	for (int i = 0; i <= paux->last; i++) {
	  if (paux->list[i]->key == key) {
	    printf("%d\n", i+counter);
	    return;
	  }
	}
      } else {
	paux = paux->next;
	counter += paux->back->size;
      }
    }
  }
}

/* Imprime um novo subarray no intervalo [beginIndex, endIndex[ */
void sub_arrayList(ARRAY_LIST *arrayList, int beginIndex, int endIndex) {
  if (arrayList != NULL) {
    ARRAY_LIST *sub_arrayList = new_arrayList();
    NODE *paux = arrayList->head->next;
    int index, counter = 0, aux = paux->size;

    while (paux->next != arrayList->head && beginIndex>= aux) {
      counter += paux->size;
      paux = paux->next;
      aux += paux->size;
    }   

    index = beginIndex - counter;

    // Adiciona os itens do intervalo no sub arrayList
    for (int i = 0; i < endIndex - beginIndex; i++) {
      add_arrayList(sub_arrayList, create_item(paux->list[index]->key,
					       paux->list[index]->value));
      index++;

      // Se o nó estiver cheio
      if (index == paux->last+1) {
	index = 0;
	paux = paux->next;
      }
    }

    print_arrayList(sub_arrayList);
  }
}

/* Modifica um elemento do arrayList */
int set_arrayList(ARRAY_LIST *arrayList, int pos, int key, int value) {
  if (arrayList != NULL && pos < size_arrayList(arrayList)-1) {
    ITEM *swap;
    NODE *paux = arrayList->head->next;
    int index, counter = 0, aux = paux->size;

      // Encontrando o item na posição informada
      while (paux->next != arrayList->head && pos >= aux) {
	counter += paux->size;
	paux = paux->next;
        aux += paux->size;
      }

      // Atribui chave e valor ao item
      index = pos - counter;
      paux->list[index]->key = key;
      paux->list[index]->value = value;

      while (paux != arrayList->head) {

	// Não está no começo do vetor
	if (index != 0) {
	  if (paux->list[index]->key < paux->list[index-1]->key) {
	    swap = paux->list[index-1];
	    paux->list[index-1] = paux->list[index];
	    paux->list[index] = swap;

	    index--;

	    //Não é o ultimo do vetor e é maior que o próximo item
	  } else if (index != paux->last &&
	             paux->list[index]->key > paux->list[index+1]->key) {

            swap = paux->list[index+1];
            paux->list[index+1] = paux->list[index];
            paux->list[index] = swap;

            index++;

          } else {

	    // Não está no último nó e é maior que o primeiro item no próximo nó
            if (paux->next != arrayList->head &&
	        paux->list[index]->key > paux->next->list[0]->key) {

	      swap = paux->next->list[0];
	      paux->next->list[0] = paux->list[index];
	      paux->list[index] = swap;

	      index = 0;
	      paux = paux->next;
	    } else {
	      return 1;
	    }
	  }

	// É o primeiro item do vetor
	} else {

	  //Não é o único item do nó e é maior que o próximo item
           if (index != paux->last &&
	       paux->list[index]->key > paux->list[index+1]->key) {

	    swap = paux->list[index+1];
	    paux->list[index+1] = paux->list[index];
  	    paux->list[index] = swap;
 
	    index++;

	    // Não está no primeiro nó e é menor que o último item do nó anterior
	   } else if (paux->back != arrayList->head &&
	           paux->list[index]->key < paux->back->list[paux->back->last]->key) {

	     swap = paux->back->list[paux->back->last];
	     paux->back->list[paux->back->last] = paux->list[index];
	     paux->list[index] = swap;

             paux = paux->back;
             index = paux->last;
 
	   } else {
             paux = paux->back;
           }
        }
      }
    	

    return 1;
  } 
      
  return 0;
}

/* Verifica se o arraylist está vazio */
int isEmpty_arrayList(ARRAY_LIST *arrayList) {
  return (arrayList->head->next == arrayList->head); 
}

/* Retorna o tamanho total do arraylist */
int size_arrayList(ARRAY_LIST *arrayList) {
  if (arrayList != NULL) {
    int size = 0;
    NODE *paux = arrayList->head->next;

    while (paux != arrayList->head) {
      size += paux->last+1;
      paux = paux->next;
    }

    return size;
  }

  return -1;
}

/* Remove um elemento do arrayList */
int remove_arrayList(ARRAY_LIST *arrayList, int pos) {
  if (arrayList != NULL && pos < size_arrayList(arrayList)) {
    NODE *paux = arrayList->head->next;
    int index, counter = 0, aux = paux->size;
    
    while (paux->next != arrayList->head && pos >= aux) {
      counter += paux->size;
      paux = paux->next;
      aux += paux->size;
    }
    
    index = pos-counter;
    
    if (paux->next == arrayList->head && index >= paux->last) {
      paux->last--;
      return 1;
    }

    while (paux != arrayList->head) {

      if (index == paux->last) {
	if (paux->next == arrayList->head) {
	  paux->last--;
	  return 1;
	}
	paux->list[index] = paux->next->list[0];
	paux = paux->next;
	index = 0;

	if (paux->last == 0) {
	  delete_node((&paux));
	  return 1;
	}
      } else {
        paux->list[index] = paux->list[index+1];
	index++;
      }
    }

    paux->last--;
    return 1;
  }
  
  return 0;
}

/* Desaloca a memória alocada pelo arraylist */
int destroy_arrayList(ARRAY_LIST **arrayList) {
  if (arrayList != NULL && *arrayList != NULL) {
    NODE *prem = (*arrayList)->head->next;
    NODE *paux = prem;

    while (paux != (*arrayList)->head) {
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
    NODE *paux = arrayList->head->next;

    while (paux != arrayList->head) {
      for (int i = 0; i <= paux->last; i++) {
	print_item(paux->list[i]);
      }

      printf("\n\n");
      paux = paux->next;
    }
  }
}


