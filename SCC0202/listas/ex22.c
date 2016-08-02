// Escreva uma função que receba um número e retorne o menor inteiro positivo cujo quadrado é superior
// ao valor dado.

#include <stdio.h>
#include <math.h>

int main(int argc, const char *argv[]) {
   int num, result;
   scanf("%d", &num);

   result = ceil(sqrt(num));
  
   if(pow(result, 2) != num)
      printf("O menor inteiro positivo é: %d.\n", result);
   else
      printf("O menor inteiro positivo é: %d.\n", result+1);

   return 0;
}
