#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>
#include <item.h>

int main(int argc, char *argv[]) {
  LISTA_LIGADA *lista = criar_lista();
  ITEM *item = criar_item(1,1);
  ITEM *item2 = criar_item(2,2);
  ITEM *item3 = criar_item(3,3);
  ITEM *item4 = criar_item(4,4);
  ITEM *item5 = criar_item(5,5);

  inserir_item(lista, item);
  inserir_item(lista, item2);
  inserir_item(lista, item3);
  inserir_item(lista, item4);
  inserir_item(lista, item5);
  imprimir_lista(lista);

  printf("\n");
  remover_item(lista, 2);

  imprimir_lista(lista);

  /* Exercício de revisão: */
  LISTA_LIGADA *l2 = criar_lista();
  l2 = separa(lista, 3);
  printf("\nPrimeira lista:\n");
  imprimir_lista(lista);
  printf("\nSegunda Lista:\n");
  imprimir_lista(l2);
  inserir_item(l2, item3);
  imprimir_lista(l2)
  
  apagar_lista(&lista);
  apagar_lista(&l2);
  
  return 0;  
}
