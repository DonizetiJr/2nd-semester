#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

int main(int argc, char *argv[]) {
  int aux;
  LISTA_ESTATICA *lista = criar_lista();
  
  for (int i = 1; i < 10; i++) {
    ITEM *item = criar_item(i,i);
    inserir_lista_estatica(lista,item, i);
  }
  remover_elemento(lista, 4);
  
  imprimir_lista(lista);
  
  apagar_lista(&lista);

  return 0;
}
