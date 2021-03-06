//Calcular a soma dos elementos de uma matriz numerica quadrada qualquer dada, que estão acima da
// diagonal principal

#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int dim) {
  int i;
  int **mat;

  mat = (int **)malloc(sizeof(int *)*dim);
  
  for (i = 0; i < dim; i++) 
    mat[i] = (int *)malloc(sizeof(int)*dim);

  return mat;
}

void readMatrix(int **mat, int dim) {
  int i, j;

  for (i = 0; i < dim; i++) {
    for (j = 0; j < dim; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
}

int sum_elements(int **mat, int dim) {
  int i, j, sum = 0;

  for (i = 0; i < dim; i++) {
    for (j = 0; j < i; j++) {
      sum += mat[j][i];
      
    }
  }
  
  return sum;
}

void freeMatrix(int **mat, int dim) {
  int i;

  for (i = 0; i < dim; i++) {
    free(mat[i]);
    mat[i] = NULL;
  }
  free(mat);
  mat = NULL;
}
 
int main(int argc, char *argv[]) {
  int dim, sum;
  int **mat;
  printf("Digite a dimensão da matriz quadrada:\n");
  scanf("%d", &dim);

  mat = createMatrix(dim);
  readMatrix(mat, dim);
  sum = sum_elements(mat, dim);

  printf("A soma é: %d\n", sum);

  freeMatrix(mat, dim);
  
  return 0;
}
