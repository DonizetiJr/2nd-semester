// Escreva uma função que receba um úmero inteiro e retorne o inverso desse número.
// Por exemplo, se a função receber 123456 deve restornar 654321.

#include <stdio.h>

int main(int argc, const char *argv[]) {
   int n, aux;

   scanf("%d", &n);

   while(n >= 10) {
      aux = n;
      aux %= 10;
      n /= 10;
      printf("%d", aux);
   }
   printf("%d", n);
   
   return 0;
}
