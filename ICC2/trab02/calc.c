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
   c = fgetc(stdin);

    if (c != ' ') {
      if (c == '-' && (counter == 0 || expressao[counter-1] == '(')) {
        expressao = (char *)realloc(expressao, sizeof(char) * (counter+3));
      	expressao[counter++] = '(';
      	expressao[counter++] = '0';
      	expressao[counter++] = c;

        c = fgetc(stdin);
        while (c == '.' || (c > 47 && c < 57)) {
          expressao = (char *)realloc(expressao, sizeof(char) * (counter+1));
      	  expressao[counter++] = c;
          c = fgetc(stdin);
        }
        expressao[counter++] = ')';
      }
	    expressao = (char *)realloc(expressao, sizeof(char) * (counter+1));
	    expressao[counter++] = c;
    }
  } while (c != EOF && c != ENTER);

  expressao[counter] = '\0';

  return expressao;
}

double char2num(char *expressao, double a, double b) {
  int i, counter = 0;
  double inteiro = 0.0, decimal = 0.0;

  for (i = a; i <= b; i++) {
    double n = expressao[i] - '0';

    if (expressao[i] != '.') {
      if (n < 0 || n > 9) return -1;
      if (counter > 0) {
        decimal = 10 * decimal + n;
        counter++;
      } else {
        inteiro = 10 * inteiro + n;
      }
    } else {
      counter++;
    }
  }

  for (i = 0; i < counter - 1; i++) {
    decimal /= 10;
  }
  double result = inteiro + decimal;
  return result;
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

double calc (int op, double a, double b) {
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
    char c = expressao[i];

    if (c == '(') {
      parentesis_aberto++;
    } else if (c == ')') {
      if (parentesis_aberto == 0) {
	       exit(1);
      }

      parentesis_aberto--;
    } else if (parentesis_aberto == 0) {
      int n = prioridade(c);

      if (n && (meio < 0 || n <= prioridade((int)expressao[meio]))) {
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

    printf("%lf %c %lf = %lf\n", a, expressao[meio], b, res);
    return res;

  } else {
    if (expressao[inicio] == '(' && expressao[fim] == ')') {
      return calc_recursion(expressao, inicio + 1, fim -1);
    }

    // Pega o primeiro numero
    double res = char2num(expressao, inicio, fim);
    if (res < 0) {
      exit(1);
    } else {
      return res;
    }
  }

  return 0;
}

void print_sem_zeros(double num) {
  int tamanho, counter = 0, i;
  char s[50];
  sprintf(s, "%lf", num);

  tamanho = strlen(s);
  i = tamanho - 1;

  while (s[i] == '0') {
    counter++;
    i--;
  }

  for (i = 0; i < tamanho - counter; i++) {
    if (i == (tamanho - counter - 1) && s[i] == '.') break;
    printf("%c", s[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  char *expressao = separador();

  double result = calc_recursion(expressao, 0, strlen(expressao)-2);

  print_sem_zeros(result);

  free(expressao);

  return 0;
}
