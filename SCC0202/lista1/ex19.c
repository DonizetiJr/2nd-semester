// Escreva uma função que receba um número positivo e imprima sua representação binária.

#include <stdio.h>
#include <stdlib.h>

void dec2bin_iterative(int n) {
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

   while(--counter >= 0) {
      printf("%d", result[counter]);
   }
   printf("\n");

   free(result);
   result = NULL;
}

void dec2bin_recursive(int n) {
  if(n == 0) return;

  dec2bin_recursive(n/2);
  printf("%d", n % 2);

}

int main(int argc, const char *argv[]) {
   int n;

   scanf("%d", &n);

   dec2bin_iterative(n);
   
   dec2bin_recursive(n);
   printf("\n");

   return 0;
}
