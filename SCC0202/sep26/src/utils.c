#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <item.h>
#include <pilha_dinamica.h>
#include <utils.h>

char *separador(char *str) {
  int size = strlen(str), i, counter = 0;
  char *newstr = NULL;

  for (i = 0; i < size; i++) {
    if (str[i] >= 39 && str[i] <= 43 || str[i] > 96 && str[i] <= 112 || str[i] == 46) {
      newstr = (char *)realloc(newstr, sizeof(char) * counter+1);
      newstr[counter++] = str[i];
    }
  }

  return newstr;
}

void *infixa_para_posfixa() {
  int j = 0;
  char infix_expr[] = "(a+b)";
  ITEM *op;
  PILHA_DINAMICA *pilha = criar_pilha_dinamica();
  char *posfix_expr = (char *)malloc(sizeof(char) * strlen(infix_expr));

  for (int i = 0; i < strlen(infix_expr); i++) {
    if (isalpha(infix_expr[i]) != 0) {
      posfix_expr[j++] = infix_expr[i];
    } else if (infix_expr[i] == '(') {
      empilhar(pilha, criar_item(TIPO_CHAR, infix_expr[i]));
    } else if (infix_expr[i] == ')') {
      while (!pilha_vazia(pilha) && topo(pilha)->vchar != '(') {
	op = desempilhar(pilha);
	posfix_expr[j++] = op->vchar;
	apagar_item(&op);
      }

      op = desempilhar(pilha);
      apagar_item(&op);
    } else {
      empilhar(pilha, criar_item(TIPO_CHAR, infix_expr[i]));
    } 
  }

  while (!pilha_vazia(pilha)) {
    op = desempilhar(pilha);
    posfix_expr[j++] =  op->vchar;
    apagar_item(&op);
  }

  posfix_expr[j] = '\0';

  apagar_pilha_dinamica(&pilha);

  printf("%s\n", posfix_expr);

  //return posfix_expr;
}

