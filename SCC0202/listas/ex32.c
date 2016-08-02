// Escreva uma tabela de graus Celsius em função de graus Farenheit, variando um a um de 50 a 150 graus
// Farenheit.

#include <stdio.h>

int celsius2far(int n) {
   int result;
   result = (n*9/5)+32;

   return result;
}

int main(int argc, const char *argv[]) {
   int i, result;
   
   printf("Celsius\tFarenheit\n");

   for (i = 50; i < 151; i++) {
      result = celsius2far(i);
      printf("%d\t%d\n", i, result);
   }

   return 0;
}
