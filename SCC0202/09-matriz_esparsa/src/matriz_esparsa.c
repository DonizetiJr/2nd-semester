#include <stdlib.h>
#include <stdio.h>
#include <matriz_esparsa.h>

typedef struct celula {
  int linha;
  int coluna;
  float valor;
  struct celula *direita;
  struct celula *abaixo;
} CELULA;

struct matriz_esparsa {
  CELULA **linhas;
  CELULA **colunas;
  int nr_linhas;
  int nr_colunas;
};

MATRIZ_ESPARSA *criar_matriz(int linhas, int colunas) {
  MATRIZ_ESPARSA *matriz = (MATRIZ_ESPARSA *)malloc(sizeof(MATRIZ_ESPARSA));
  if (matriz != NULL) {
    int i;
    matriz->nr_linhas = linhas;
    matriz->nr_colunas = colunas;
    matriz->linhas = (CELULA **)malloc(sizeof(CELULA *) * linhas);
    matriz->colunas = (CELULA **)malloc(sizeof(CELULA *) * colunas);

    if (matriz->linhas != NULL && matriz->colunas != NULL) {
      for (i = 0; i < linhas; i++) {
	matriz->linhas[i] = (CELULA *)malloc(sizeof(CELULA));
	matriz->linhas[i]->direita = NULL;
      }

      for (i = 0; i < colunas; i++) {
	matriz->colunas[i] = (CELULA *)malloc(sizeof(CELULA));
	matriz->colunas[i]->abaixo = NULL;
      }
    }
  }

  return matriz;
}


void apagar(MATRIZ_ESPARSA **matriz) {
  if (*matriz != NULL && matriz != NULL) {
    for (int i = 0; i < (*matriz)->nr_linhas; i++) {
      CELULA *paux = (*matriz)->linhas[i]->direita;

      while (paux != NULL) {
	CELULA *prem = paux;
	paux = paux->direita;
	free(prem);
      }

      free((*matriz)->linhas[i]);
    }

    free((*matriz)->linhas);
    free((*matriz)->colunas);
    free((*matriz));
    *matriz = NULL;
  }
}


void set(MATRIZ_ESPARSA *matriz, int linha, int coluna, float valor) {
  if (matriz != NULL && linha < matriz->nr_linhas && coluna < matriz->nr_colunas) {
    CELULA *paux = matriz->linhas[linha];

    while (paux->direita != NULL && paux->direita->coluna <= coluna) {
      paux = paux->direita;
    }

    if (paux->coluna == coluna) {
      paux->valor = valor;
    } else {
      CELULA *pnovo = (CELULA *)malloc(sizeof(CELULA));
      if (pnovo != NULL) {
         pnovo->linha = linha;
      	pnovo->coluna = coluna;
      	pnovo->valor = valor;
      	pnovo->direita = paux->direita;
      	paux->direita = pnovo;

      	paux = matriz->colunas[coluna];
      	while (paux->abaixo != NULL && paux->abaixo->linha <= linha) {
      	  paux = paux->abaixo;
      	}

      	pnovo->abaixo = paux->abaixo;
      	paux->abaixo = pnovo;
      }
    }
  }
}


float get(MATRIZ_ESPARSA *matriz, int linha, int coluna) {
  if (matriz != NULL && linha < matriz->nr_linhas && coluna < matriz->nr_colunas) {
    CELULA *paux = matriz->linhas[linha];
    while (paux->direita != NULL && paux->direita->coluna <= coluna) {
      paux = paux->direita;
    }

    if (paux->coluna == coluna) {
      return paux->valor;
    }
  }
  return 0;
}

void imprimir_matriz(MATRIZ_ESPARSA *matriz) {
  if (matriz != NULL) {
    int i, j;
    CELULA *paux = matriz->linhas[0];

    for (i = 0; i < matriz->nr_linhas; i++) {
      for (j = 0; j < matriz->nr_colunas; j++) {
	if (paux->direita->linha == i && paux->direita->coluna == j) {
	  paux = paux->direita;
	  printf("%.2f\t", paux->valor);
	} else {
	  printf("0\t");
	}
      }
      printf("\n");
      paux = paux->direita->abaixo;
    }
  }
}
