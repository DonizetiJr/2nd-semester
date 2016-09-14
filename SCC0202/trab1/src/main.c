/* Sistema de Gerenciamento de Dados */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <listaligada.h>
#include <utils.h>

int main(int argc, char *argv[]) {
  char primeiro_nome[15], ultimo_nome[15], cpf[15], telefone[20];
  char *comando = (char *)malloc(32*sizeof(char));
  int sair = 0;

  /* Criação do Sistema de Gerenciamento de Dados. */
  LISTA_LIGADA *lista = criar_lista();

  do {
    /* Lê-se o comando digitado pelo usuário. */
    scanf("%s", comando);
    if (strcmp(comando, "sair") == 0) {
      sair = 1;
    } else if (strcmp(comando, "cadastrar") == 0) {
      /* Para cadastrar um novo usuário deve-se receber todas as informações necessárias. */
      scanf("%s", primeiro_nome);
      scanf("%s", ultimo_nome);
      scanf("%s", cpf);
      scanf("%s", telefone);
      cadastro(lista, cpf, primeiro_nome, ultimo_nome, telefone);
    } else if(strcmp(comando, "buscar") == 0) {
      scanf("%s", cpf);
      buscar_cpf(lista, cpf);
    } else if (strcmp(comando, "remover") == 0) {
      scanf("%s", cpf);
      remover_cpf(lista, cpf);
    } else if (strcmp(comando, "dump") == 0) {
      dump(lista);
    }
  } while (!sair);

  /* Ao sair do sistema, deve-se liberar toda a memória alocada. */
  sair_gerenciamento(&lista);
  free(comando);
  
  return 0;
}

