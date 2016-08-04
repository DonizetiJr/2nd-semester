//Escreva uma função que receba três valores inteiros e retorne 0 se esses não formam um triangulo, 1
//se o triangulo é equilátero, 2 se é isóceles e 3 se é escaleno.

#include <stdio.h>

void triang_class(int a, int b, int c) {
   if((a > b + c)|| (b > a + c) || c > a + c) {
      printf("Não formam um triângulo.\n");
      return;
   }

   if (a == b && a == c) 
      printf("O triangulo é equilatero\n");
   else if(a == b || a == c || b == c)
      printf("O triangulo é isoceles.\n");
   else
      printf("O triangulo é escaleno\n");
   return;

}

int main(int argc, const char *argv[]) {
   int a, b, c;

   printf("Digite os lados do triangulo:\n");
   scanf("%d %d %d", &a, &b, &c);

   triang_class(a, b, c);

   return 0;
}
