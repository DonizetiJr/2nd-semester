// Donizeti C dos Santos Júnior 9393882

#include <stdio.h>
#include <stdlib.h>
#include <matriz_esparsa.h>

int main(int argc, char const *argv[]) {
   char op;
   int nr_linhas, nr_colunas, valor;

   // Definindo a operação
   scanf("%c", &op);

   //Lendo a matriz a
   scanf("%d %d %d", &valor, &nr_linhas, &nr_colunas);
   MATRIZ_ESPARSA *A = criar_matriz(nr_linhas, nr_colunas);

   while (scanf("%d %d %d", &nr_linhas, &nr_colunas, &valor) && nr_linhas != EOF) {
      set_matriz(A, nr_linhas, nr_colunas, valor);
   }

   // Lendo a matriz b
   MATRIZ_ESPARSA *B = criar_matriz(nr_colunas, valor);
   while (scanf("%d %d %d", &nr_linhas, &nr_colunas, &valor) != EOF) {
      set_matriz(B, nr_linhas, nr_colunas, valor);
   }

   // Realização da operação informada
   MATRIZ_ESPARSA *C = NULL;
   if (op == 'M') {
      C = multiplicar_matriz(A, B);
   } else if (op == 'A') {
      C = somar_matriz(A, B);
   }

   imprimir_matriz(C);

   apagar_matriz(&A);
   apagar_matriz(&B);
   apagar_matriz(&C);

   return 0;
}
