// Escreva uma função que receba dois números doubleeiros e retorne o número de combinações de n objetos 
// tomados r de cada vez.

#include <stdio.h>

double fat(double n) {
   if(n == 0) return 1;
   return n*(n-1);
}

int main(int argc, const char *argv[]) {
   double n, r, result;
   scanf("%lf %lf", &n, &r);

   printf("%lf", fat(8));
   result = fat(n)/(fat(r)*fat(n-r));

   printf("O número de combinações é: %lf", result);
   
   return 0;
}
