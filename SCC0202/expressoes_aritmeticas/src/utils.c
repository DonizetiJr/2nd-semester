#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <item.h>
#include <pilha_dinamica.h>
#include <utils.h>

void avalia_posfixa() {
  ITEM *op1, *op2, *res;
  PILHA_DINAMICA *pilha = criar_pilha_dinamica();
  char str[] = "6 2 / 3 4 * + 3 -";

  char *token = strtok(str, " ");
  while (token != NULL) {
     if (isdigit(token[0])) {
      empilhar(pilha, criar_item(TIPO_INT, atoi(token)));
    } else {
       op2 = desempilhar(pilha);
       op1 = desempilhar(pilha);

       res = criar_item(TIPO_INT, 0);
       switch (token[0]) {
         case '+': res->vint = op1->vint + op2->vint; break;
         case '-': res->vint = op1->vint - op2->vint; break;
         case '*': res->vint = op1->vint * op2->vint; break;
         case '/': res->vint = op1->vint / op2->vint; break;
       }

      apagar_item(&op1);
      apagar_item(&op2);
      empilhar(pilha, res);
      }
     
     token = strtok(NULL, " ");
  }

  res = desempilhar(pilha);
  int resultado = res->vint;
  apagar_item(&res);
  apagar_pilha_dinamica(&pilha);

  printf("Resultado: %d\n", resultado);
} 
