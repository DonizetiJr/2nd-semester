#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ENTER 10

char *separador () {
  char c;
  int counter = 0;
  char *expressao = NULL;

  do {
    scanf("%c", &c);
    
    if (c != ' ') {
      if (c == '-' && (counter == 0 || expressao[counter-1] == '(')) {
	scanf("%c", &c);
        expressao = (char *)realloc(expressao, sizeof(char) * (counter+5));
	expressao[counter++] = '(';
	expressao[counter++] = '0';
	expressao[counter++] = '-';
	expressao[counter++] = c;
	expressao[counter++] = ')';
      } else {
	expressao = (char *)realloc(expressao, sizeof(char) * (counter+1));
	expressao[counter++] = c;
      }
    }
    
  } while (c != ENTER);

  expressao[counter] = '\0';

  return expressao;
}

double char2num(char *expressao, double a, double b) {
  int i;
  double num = 0.0;

  for (i = a; i <= b; i++) {
    double n = expressao[i] - '0';

    if (n < 0 || n > 9) return -1; 
    num = 10 * num + n;
  }

  return num;
}

int prioridade (char op) {
  switch (op) {
    case '-':
    case '+': return 1;
    case '/':
    case '*': return 2;
  }

  return 0;
}

int calc (int op, int a, int b) {
  switch (op) {
  case '+': return a + b;
  case '-': return a - b;
  case '*': return a * b;
  case '/':
    if (b == 0) exit(1);
    return a / b;
  }

  return 0;
}

double calc_recursion(char *expressao, int inicio, int fim) {
  int i, meio = -1, parentesis_aberto = 0;

  if (inicio > fim) return 0; 
    
  for (i = inicio; i <= fim; i++) {
    double c = expressao[i];

    if (c == '(') {
      parentesis_aberto++;
    } else if (c == ')') {
      if (parentesis_aberto == 0) {
	exit(1);
      }

      parentesis_aberto--;
    } else if (parentesis_aberto == 0) {
      int n = prioridade(c);

      if (n && (meio < 0 || n < prioridade((int)expressao[meio]))) {
	meio = i;
      }
    }
  }

  if (parentesis_aberto > 0) {
    exit(1);
  }

  if (meio >= 0) {
    double a = calc_recursion(expressao, inicio, meio - 1);
    double b = calc_recursion(expressao, meio+1, fim);
    double res = calc(expressao[meio], a, b);

    printf("%lf %c %lf == %lf\n", a, expressao[meio], b, res);
    return res;
    
  } else {
    if (expressao[inicio] == '(' && expressao[fim] == ')') {
      return calc_recursion(expressao, inicio + 1, fim -1);
    }

    double res = char2num(expressao, inicio, fim);
    if (res < 0) {
      exit(1);
    } else {
      return res;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  char *expressao;
  expressao = separador(expressao);
  printf("%s", expressao);
  double result = calc_recursion(expressao, 0, strlen(expressao)-2);

  printf("%lf\n", result);

  free(expressao);
  
  return 0;
}
