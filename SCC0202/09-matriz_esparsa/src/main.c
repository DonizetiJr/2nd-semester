#include <stdio.h>
#include <matriz_esparsa.h>

int main(int argc, char *argv[]) {
  MATRIZ_ESPARSA *m = criar_matriz(3,4);

  //set(m, 1, 1, 5);

  //  imprimir_matriz(m);
  
  apagar(&m);
  
  return 0;
}
