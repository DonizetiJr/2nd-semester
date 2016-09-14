#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

int main(int argc, char *argv[]) {
  int aux;
  LISTA_ESTATICA *lista = criar_lista();

  for (int i = 0; i < 10; i++) {
    ITEM *item = criar_item(i,i);
    inserir_lista_estatica(lista,item);
  }

  imprimir_item(buscar_item_estatica(lista, 5));
  imprimir_lista(lista);
  
  apagar_lista(&lista);

  return 0;
}
