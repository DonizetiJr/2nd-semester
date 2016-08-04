// Escreva uma função que receba um número positivo e imprima sua representação binária.

#include <stdio.h>
#include <stdlib.h>

void dec2bin(int n) {
   int r, q;
   int *result = NULL;
   int counter = 0;

   while (n >= 2) {
      q = n / 2;
      r = n - (2*q);

      result = (int *)realloc(result, sizeof(int)*(counter+1));
      result[counter++] = r;

      n = q;
   }

   result = (int *)realloc(result, sizeof(int)*(counter+1));
   result[counter++] = q;

   printf("O número digitado em binário é:\n");

   while(--counter >= 0) {
      printf("%d", result[counter]);
   }
   printf("\n");

   free(result);
   result = NULL;
}

int main(int argc, const char *argv[]) {
   int n;

   printf("Digite um número:\n");
   scanf("%d", &n);

   dec2bin(n);

   return 0;
}
