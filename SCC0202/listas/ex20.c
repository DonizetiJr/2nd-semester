// Escreva uma função que receba duas matrizes e seus respectivos tamanhos de linhas e colunas e 
// imprima, quando possivel, o resultado da multiplicação dessas.

#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int row, int col) {
   int i, j;
   int **mat;

   mat = (int **)malloc(col*sizeof(int));
   for (i = 0; i < row; i++) {
      mat[i] = (int *)malloc(col*sizeof(int));
      for (j = 0; j < col; j++) scanf("%d", &mat[i][j]);
   }
   return mat;
}

void multMatrix(int col1, int col2, int row1, int row2, int **matrix1, int **matrix2) {
   int i, j, k;
   int sum;
   int **matrixR;

   for (i = 0; i < row1; i++) {
      for(j = 0; j < col2; j++) {
         sum = 0;
         for(k = 0; k < col1; k++)
            sum += matrix1[i][k] * matrix2[k][j];
         printf("%d", sum);
      }
      printf("\n");
   }
}

void matrixFree(int **mat, int row) {
   int i;
   for (i = 0; i < row; i++) {
      free(mat[i]);
      mat[i] = NULL;
   }
   free(mat);
   mat = NULL;
}

int main(int argc, const char *argv[]) {
   int row1, row2, col1, col2;
   int **mat1, **mat2;

   printf("Digite a quantidade de linhas e colunas da matriz 1:");
   scanf("%d %d", &row1, &col1);
   mat1 = create_matrix(row1, col1);

   printf("Digite a quantidade de linhas e colunas da matriz 2:");
   scanf("%d %d", &row2, &col2);
   mat2 = create_matrix(row2, col2);

   multMatrix(col1, col2, row1, row2, mat1, mat2);

   matrixFree(mat1, row1);
   matrixFree(mat2, row2);

   return 0;
}
