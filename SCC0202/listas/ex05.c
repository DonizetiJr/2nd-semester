//Escreva uma função que receba um número inteiro e retorne 1 se esse for primo e 0 caso contrário.

#include <stdio.h>
#include <math.h>

typedef enum {
   FALSE,
   TRUE
} bool;

bool isPrime(int n) {
   int i;

   for (i = 2; i < sqrt(n); i++)
      if(n%i == 0) return FALSE;
   
   return TRUE;

}

int main(int argc, const char *argv[]) {
   int n;

   scanf("%d", &n);   
   printf("%d", isPrime(n));

   return 0;
}
