// Donizeti C dos Santos Junior 9393882

#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct matriz_esparsa MATRIZ_ESPARSA;

MATRIZ_ESPARSA *criar_matriz(int nr_linhas, int nr_colunas);
void apagar_matriz(MATRIZ_ESPARSA **matriz);

int set_matriz(MATRIZ_ESPARSA *matriz, int linha, int coluna, int valor);
int get_matriz(MATRIZ_ESPARSA *matriz, int linha, int coluna);

MATRIZ_ESPARSA *multiplicar_matriz(MATRIZ_ESPARSA *A, MATRIZ_ESPARSA *B);
MATRIZ_ESPARSA *somar_matriz(MATRIZ_ESPARSA *A, MATRIZ_ESPARSA *B);

void imprimir_matriz(MATRIZ_ESPARSA *matriz);

#endif
