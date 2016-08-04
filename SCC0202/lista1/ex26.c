// Escreva uma função recursiva que retorne a representação binária de um número inteiro.

#include <stdio.h>

int dec2bin(int n) {
   if(n == 0) return 0;
   else return (n % 2 + 10 * dec2bin(n/2));
}


int main(int argc, const char *argv[]) {
   int n, binary;
   scanf("%d", &n);

   binary = dec2bin(n);
   printf("O número %d em binário é %d.\n", n,  binary);

   return 0;
}
