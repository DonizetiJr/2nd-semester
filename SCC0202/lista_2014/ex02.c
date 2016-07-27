// Escreva uma função que faça a divisão de dois números inteiros usando somas e subtrações.

#include <stdio.h>

double div(double n1, double n2) {
   if(n1 < n2) return 0;
   return div(n1-n2, n2) + 1;
}

int main(int argc, const char *argv[]) {
   double den, quoc, result;

   scanf("%lf %lf", &den, &quoc);
   
   result = div(den, quoc);
   printf("O resultado é %.2lf\n",result);

   return 0;
}
