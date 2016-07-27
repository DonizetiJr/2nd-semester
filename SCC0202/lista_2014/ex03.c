// Escreva uma função que calcule a potência de um número inteiro usando multiplicações.

#include <stdio.h>

int main(int argc, const char *argv[]) {
   int x, y, result = 1,  i;

   scanf("%d %d", &x, &y);

   for (i = 0; i < y; i++) result *= x;
   printf("%d", result);

   return 0;
}
