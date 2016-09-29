#include <pilha_dinamica.h>

int main(int argc, char *argv[]) {
  PILHA_DINAMICA *pilha = criar_pilha_dinamica();
  ITEM *item = criar_item(2,2);

  empilhar(pilha, item);
  imprimir_topo(pilha); 
  desempilhar(pilha);
  
  apagar_pilha_dinamica(&pilha);
  
  return 0;
}
