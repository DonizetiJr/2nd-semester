#include <stdlib.h>
#include <stdio.h>
#include <listaestatica.h>
#include <item.h>

int main(int argc, char *argv[]) {
  LISTA_ESTATICA *l1 = criar_lista(10);

  for (int i = 0; i < 10; i++) {
    printf("inserir: %d\n", i); 
    ITEM *item = criar_item(i,i);
    inserir_ordenado(l1,item);
  }

  imprimir_lista(l1);
  
  apagar_lista(&l1);
  
  return 0;
}
