// Escreva uma função que receba um número inteiro positivo x e retorne a soma de todos os inteiros 
// positivos entre 1 e x.

#include <stdio.h>

int main(int argc, const char *argv[]) {
   int n, i, sum;
   scanf("%d", &n);

   for(i = 2; i < n; i++) sum += i;
   
   printf("%d\n", sum);
   
   return 0;
}
