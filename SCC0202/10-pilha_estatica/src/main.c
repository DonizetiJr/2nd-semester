#include <pilha_estatica.h>

int main(int argc, char *argv[]) {
  PILHA_ESTATICA *pilha = criar_pilha_estatica();
  ITEM *item = criar_item(2,2);

  empilhar(pilha, item);
  imprimir_topo(pilha); 
  desempilhar(pilha);
  
  apagar_pilha_estatica(&pilha);
  
  return 0;
}
