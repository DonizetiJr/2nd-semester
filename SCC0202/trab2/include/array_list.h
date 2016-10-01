/* Donizeti C dos Santos Junior  9393882 */

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <item.h>

typedef struct array_list ARRAY_LIST;

/* Cria a ArrayList e aloca toda memória necessária */
ARRAY_LIST *new_arrayList();

/* Adiciona um item ao arrayList */
int add_arrayList(ARRAY_LIST *arrayList, ITEM *element);

/* Verifica no arraylist se existe um elemento com a chave informada */
int contains_arrayList(ARRAY_LIST *arrayList, int key);

/* Imprime um item na posição informada */
void get_arrayList(ARRAY_LIST *arrayList, int pos);

/* Retorna qual a posiçao do primeiro elemento com a chave informada */
void indexOf_arrayList(ARRAY_LIST *arrayList, int key);

/* Imprime um novo subarray no intervalo [beginIndex, endIndex[ */
void sub_arrayList(ARRAY_LIST *arrayList, int beginIndex, int endIndex);

/* Modifica um elmento do arrayList */
int set_arrayList(ARRAY_LIST *arrayList, int pos, int key, int value);

/* Verifica se o arraylist está vazio */
int isEmpty_arrayList(ARRAY_LIST *arrayList);

/* Retorna o tamanho total do arraylist */
int size_arrayList(ARRAY_LIST *arrayList);

/* Remove um elemento do arrayList */
int remove_arrayList(ARRAY_LIST *arrayList, int pos);
  
/* Desaloca a memória alocada pelo arraylist */
int destroy_arrayList(ARRAY_LIST **arrayList);

/* imprime toda a lista */
void print_arrayList(ARRAY_LIST *arrayList);

#endif
