// Escreva um programa que leia uma matriz nxm do usuário e a transforme em um vetor unidimensional
//de n*m posições.

#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int col, int row) {
  int i;
  int **m;

  m = (int **)malloc(sizeof(int *)*row);
  for (i = 0; i < row; i++) 
    m[i] = (int *)malloc(sizeof(int)*col);

  return m;
}

void readMatrix(int **m, int col, int row) {
  int i, j;

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      scanf("%d", &m[i][j]);
    }
  }
}

int *convert_unidim(int **mat, int col, int row) {
  int i, j, counter = 0;
  int *p;

  p = (int *)malloc(sizeof(int)*col*row);

  for (i = 0; i < row; i++) {
    for (j = 0; j < col; j++) {
      p[counter++] = mat[i][j];
    }
  }
  return p;
}

void print(int *p, int len) {
  int i;

  for (i = 0; i < len; i++) 
    printf("%d\n", p[i]);
}

void freeMatrix(int **m, int row) {
  int i;

  for (i = 0; i < row; i++) {
    free(m[i]);
    m[i] = NULL;
  }
  free(m);
}

void erase(int **p) {
  if(*p != NULL) {
    free(*p);
    *p = NULL;
  }
}

int main(int argc, char *argv[]) {
  int col, row, i, j;
  int **mat, *unid;

  printf("Digite a quantidade de colunas:\n");
  scanf("%d", &col);

  printf("Digite a quantidade de linhas:\n");
  scanf("%d\n", &row);

  mat = createMatrix(col, row);
  readMatrix(mat, col, row);
  unid = convert_unidim(mat, col, row);
  print(unid, col*row);
  
  freeMatrix(mat, row);
  erase(&unid);
  
  return 0;
}
