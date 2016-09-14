#ifndef MATRIZ_ESPARSA_H
#define MATRIZ_ESPARSA_H

typedef struct matriz_esparsa MATRIZ_ESPARSA;

MATRIZ_ESPARSA *criar_matriz(int linhas, int colunas);
void apagar(MATRIZ_ESPARSA **matriz);

void set(MATRIZ_ESPARSA *matriz, int linha, int coluna, float valor);
float get(MATRIZ_ESPARSA *matriz, int linha, int coluna);

float somar_matriz(MATRIZ_ESPARSA *m1, MATRIZ_ESPARSA *m2, MATRIZ_ESPARSA *resultado);
float multiplicar_matriz(MATRIZ_ESPARSA *m1, MATRIZ_ESPARSA *m2, MATRIZ_ESPARSA *resultado);
float somar_coluna(MATRIZ_ESPARSA *matriz, float constante, int coluna);
float somar_linha(MATRIZ_ESPARSA *matriz, float constante, int linha);

void imprimir_matriz(MATRIZ_ESPARSA *matriz);

#endif
