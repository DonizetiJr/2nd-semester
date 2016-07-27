// Escreva uma função que receba um número inteiro e retorne seu fatorial.

#include <stdio.h>

int fat(int n) {
   if(n == 0) return 1;
   return n*fat(n-1);
}

int main(int argc, const char *argv[]) {
   int n, result;

   scanf("%d", &n);
   result = fat(n);

   printf("%d", result);

   return 0;
}
