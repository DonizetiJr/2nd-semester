#include <stdlib.h>
#include <stdio.h>
#include <listaligada.h>
#include <item.h>

int main(int argc, char *argv[]) {
  LISTA_LIGADA *lista = criar_lista();
  ITEM *item = criar_item(1,1);
  ITEM *item2 = criar_item(2,2);
  ITEM *item3 = criar_item(3,3);

  if(inserir_item_inicio(lista, item))
    imprimir_lista(lista);
  if(inserir_item_inicio(lista, item2))
    imprimir_lista(lista);
  if(inserir_item_fim(lista, item3))
    imprimir_lista(lista);
  
  if(remover_item(lista, 3))
    printf("Funfou!!!\n");

  imprimir_lista(lista);

  apagar_lista(&lista);
  
  return 0;  
}
