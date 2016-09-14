#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

int main(int argc, char *argv[]) {
  LISTA_ESTATICA *l1 = criar_lista(5);
  LISTA_ESTATICA *l2 = criar_lista(5);

  for (int i = 0; i < 10; i += 2) {
    ITEM *item = criar_item(i,i);
    inserir_lista_estatica(l1,item);
  }

  for (int i = 1; i < 10; i += 2) {
    ITEM *item = criar_item(i,i);
    inserir_lista_estatica(l2,item);
  }
  LISTA_ESTATICA *l3 = intercalar_listas_estaticas(l1, l2);

  imprimir_lista(l3);
  
  apagar_lista(&l1);
  apagar_lista(&l2);
  apagar_lista(&l3);

  return 0;
}
