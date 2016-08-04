// Escreva uma função que receba dois números x e y, com x < y, e imprima quais números nesse intervalo
// que divididos por 13 dão um resto igual a 5.

#include <stdio.h>

int main(int argc, const char *argv[]) {
   int x, y, i, start;
   scanf("%d %d", &x, &y);

   if(y < 13) {
      printf("Nenhum número no intervalo satisfaz o problema.\n");
   } else {
      if (x > 13) start = x-(x%13)+5;
      else start = 18;
      
      printf("Os números são:\n");
      for (i = start; i < y; i += 13)
         printf("%d\n", i);
   }

   return 0;
}
