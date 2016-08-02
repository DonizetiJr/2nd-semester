// Se somarmos os números ímpares consecutivos até que esta soma seja igual a N, o número M de termos 
// somados será igual a raiz quadrada de N. Faça um programa em C que responda se N é quadrado perfeito.

#include <stdio.h>

int is_perfect(int n, int i) {
   printf("n = %d, i = %d\n", n, i);
   if(n == i) return 1;
   if(i > n) return 0;
   return is_perfect(n, i+i+2);
}

int main(int argc, const char *argv[]) {
   int n;
   scanf("%d", &n);

   if(is_perfect(n, 1))
      printf("%d é quadrado perfeito\n", n);
   else
      printf("%d não é quadrado perfeito\n", n);

   return 0;
}
