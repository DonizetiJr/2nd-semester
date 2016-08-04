// Escreva uma função que dado um ângulo em graus, retorne seu seno usando as séries de MacLaurin.

#include <stdio.h>
#include <math.h>

double deg2rad(int angle) {
   double rad;
   rad = (angle*3.1415)/180;

   return rad;
}

double fat(int n) {
   if(n == 0) return 1;
   return n*fat(n-1);
}

void print_sin(double ang) {
   int i, sig = 1;
   double aux, result = 0;

   for (i = 1; i < 10; i += 2) {
      aux = pow(ang, i)/fat(i);
      result += sig*aux;
      sig = -sig;
   }

   printf("%lf\n", result);
}

int main(int argc, const char *argv[]) {
   int angle;
   double rad;
   scanf("%d", &angle);

   rad = deg2rad(angle);
   print_sin(rad);

   return 0;
}
