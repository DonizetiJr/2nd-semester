/* Donizeti C dos Santos Junior   9393882 */

#include <stdlib.h>
#include <stdio.h>
#include <item.h>
#include <string.h>
#include <array_list.h>

int main(int argc, char *argv[]) {
  char *comando = (char *)malloc(32*sizeof(char));
  int sair = 0;

  /* Criação do arrayList */
  ARRAY_LIST *arrayList = new_arrayList();

    do {
    /* Lê-se o comando digitado pelo usuário */
    scanf("%s", comando);
    if (strcmp(comando, "sair") == 0) {
      sair = 1; 

    } else if (strcmp(comando, "tamanho") == 0) {
      printf("%d\n", size_arrayList(arrayList));
      

    } else if (strcmp(comando, "add") == 0) {
      int chave, valor;
      scanf("%d %d", &chave, &valor);
      add_arrayList(arrayList, create_item(chave, valor));
      

    } else if (strcmp(comando, "sub") == 0) {
      int pos1, pos2;
      scanf("%d %d", &pos1, &pos2);
      sub_arrayList(arrayList, pos1, pos2);
      

    } else if (strcmp(comando, "set") == 0) {
      int pos, chave, valor;
      scanf("%d %d %d", &pos, &chave, &valor);
      set_arrayList(arrayList, pos, chave, valor);
      

    } else if (strcmp(comando, "print") == 0) {
      print_arrayList(arrayList);
      

    } else if (strcmp(comando, "contem") == 0) {
      int chave;
      scanf("%d", &chave);
      printf("%d\n", contains_arrayList(arrayList, chave));
      
    } else if (strcmp(comando, "indice") == 0) {
      int chave;
      scanf("%d", &chave);
      indexOf_arrayList(arrayList, chave);
      
    } else if (strcmp(comando, "vazia") == 0) {
      printf("%d\n", isEmpty_arrayList(arrayList));
      
    } else if (strcmp(comando, "remover") == 0) {
      int pos;
      scanf("%d", &pos);
      remove_arrayList(arrayList, pos);
      
    } else if (strcmp(comando, "get") == 0) {
      int pos;
      scanf("%d", &pos);
      get_arrayList(arrayList, pos);
    }
   
  } while (!sair);

  /* Ao sair do sistema, deve-se liberar toda a memória alocada */
  destroy_arrayList(&arrayList);
  free(comando);

  return 0;
}
