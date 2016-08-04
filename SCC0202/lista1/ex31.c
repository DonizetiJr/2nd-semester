// Crie uma função que faça a ordenação de um vetor

#include <stdio.h>

void bubble_sort(int *vector, int len) {
   int i, j, aux;

   for (j = 0; j < len; j++) {
      for (i = 0; i < len-j; i++) {
         if (vector[i] > vector[i+1]) {
            aux = vector[j];
            vector[i] = vector[i+1];
            vector[i+1] = aux;
         }
      }
   }
   return;
}

int main(int argc, const char *argv[]) {
   

   return 0;
}
