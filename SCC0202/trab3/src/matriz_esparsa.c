// Donizeti C dos Santos Junior 9393882

#include <matriz_esparsa.h>

#include <stdlib.h>
#include <stdio.h>

typedef struct CELULA {
   int linha, coluna, valor;
   struct CELULA *direita, *abaixo;
} CELULA;

struct matriz_esparsa {
   CELULA *inicio;
   CELULA *ultima_celula; // Última célula colocada
   int nr_linhas, nr_colunas;
};

// Cria uma célula da matriz
CELULA *cria_celula(int linha, int coluna, int valor, CELULA *direita, CELULA *abaixo) {
   CELULA *celula = (CELULA *)malloc(sizeof(CELULA));

   if (celula != NULL) {
      celula->linha = linha;
      celula->coluna = coluna;
      celula->valor = valor;

      celula->direita = direita;
      celula->abaixo = abaixo;
   }

   return celula;
}

//Cria a matriz com as dimensões especificadas
MATRIZ_ESPARSA *criar_matriz(int nr_linhas, int nr_colunas) {
   MATRIZ_ESPARSA *matriz = (MATRIZ_ESPARSA *)malloc(sizeof(MATRIZ_ESPARSA));

   if (matriz != NULL) {
      CELULA *paux;

      matriz->nr_linhas = nr_linhas;
      matriz->nr_colunas = nr_colunas;

      matriz->inicio = cria_celula(-1, -1, -1, NULL, NULL);
      matriz->inicio->direita = matriz->inicio;
      matriz->inicio->abaixo = matriz->inicio;

      matriz->ultima_celula = matriz->inicio;

      //Criação dos nós cabeça verticais
      paux = matriz->inicio;
      for (int i = 0; i < nr_linhas; i++) {
         paux->abaixo = cria_celula(i, -1, -1, NULL, matriz->inicio);
         paux = paux->abaixo;
         paux->direita = paux;
      }
      //Criação dos nós cabeça horizontais
      paux = matriz->inicio;
      for (int i = 0; i < nr_colunas; i++) {
         paux->direita = cria_celula(-1, i, -1, matriz->inicio, NULL);
         paux = paux->direita;
         paux->abaixo = paux;
      }
   }

   return matriz;
}

// Apaga toda a memória alocada pelas células da matriz
void apagar_matriz(MATRIZ_ESPARSA **matriz) {
   if (*matriz != NULL && matriz != NULL) {
      CELULA *paux = (*matriz)->inicio;
      CELULA *prem = NULL;

      // Apaga os itens da matriz andando pelas colunas
      for (int i = 0; i <= (*matriz)->nr_colunas; i++) {
         paux = paux->abaixo;
         while (paux->linha != -1) {
            prem = paux;
            paux = paux->abaixo;
            free(prem);
         }
         prem = paux;
         paux = paux->direita;
         free(prem);
      }

      free(*matriz);
      *matriz = NULL;
   }
}

// Insere uma célula nas posições e com o valor indicado
int set_matriz(MATRIZ_ESPARSA *matriz, int linha, int coluna, int valor) {
   if (matriz != NULL && linha < matriz->nr_linhas && coluna < matriz->nr_colunas) {
      int i;
      // Declaração de células temporárias
      CELULA *paux_linha = matriz->ultima_celula;
      CELULA *paux_coluna = matriz->inicio->direita;
      CELULA *paux = (CELULA *)malloc(sizeof(CELULA));

      if (paux != NULL) {
         paux->linha = linha;
         paux->coluna = coluna;
         paux->valor = valor;

         while (paux_linha->coluna != -1) {
            paux_linha = paux_linha->direita;
         }

         // Coloca-se a celula na posição correta da linha
         for (i = paux_linha->linha; i < linha; i++) {
            paux_linha = paux_linha->abaixo;
         }

         while (paux_linha->direita->coluna != -1) {
            paux_linha = paux_linha->direita;
         }
         paux->direita = paux_linha->direita;
         paux_linha->direita = paux;

         //Coloca-se a celula na posição correta da coluna
         for (i = 0; i < coluna; i++) {
            paux_coluna = paux_coluna->direita;
         }

         while(paux_coluna->abaixo->linha != -1) {
            paux_coluna = paux_coluna->abaixo;
         }
         paux->abaixo = paux_coluna->abaixo;
         paux_coluna->abaixo = paux;

         matriz->ultima_celula = paux;
         return 1;
      }
   }

   return 0;
}

// Retorna o valor da célula na posição indicada
int get_matriz(MATRIZ_ESPARSA *matriz, int linha, int coluna) {
   if (matriz != NULL) {
      int i = 0;
      CELULA *paux;

      paux = matriz->inicio->direita;

      // Alcança a coluna desejada
      for (i = 0; i < coluna; i++) {
         paux = paux->direita;
      }

      do {
         paux = paux->abaixo;
         if (paux->linha == linha) {
            return paux->valor;
         }
      } while (paux->linha != -1);
   }

   return 0;
}

// Realiza a operação de multiplicação de matrizes
MATRIZ_ESPARSA *multiplicar_matriz(MATRIZ_ESPARSA *A, MATRIZ_ESPARSA *B) {
   // Condição para multiplicação de matrizes
   if (A != NULL && B != NULL && A->nr_colunas == B->nr_linhas) {
      int i = 0, j = 0, k = 0;
      int total;
      // Nós auxiliares para percorrerem as matrizes
      CELULA *pauxA = A->inicio->abaixo->direita;
      CELULA *pauxB = B->inicio->direita->abaixo;

      // A matriz resultante possui a qnt de linhas de A e colunas de B
      MATRIZ_ESPARSA *C = criar_matriz(A->nr_linhas, B->nr_colunas);

      for (i = 0; i < A->nr_linhas; i++) {
         // Copia a atual linha da matriz A no vetor
         int *vetor_aux = (int *)calloc(A->nr_colunas, sizeof(int));
         while(pauxA->coluna != -1) {
            vetor_aux[pauxA->coluna] = pauxA->valor;
            pauxA = pauxA->direita;
         }

         for (j = 0; j < B->nr_colunas; j++) {
            total = 0;
            // Multiplica os números de B com os números de A que estão na coluna de A com mesmo valor
            while(pauxB->linha != -1) {
               total += (pauxB->valor * vetor_aux[pauxB->linha]);
               pauxB = pauxB->abaixo;
            }

            if (total) {
               set_matriz(C, i, j, total);
            }
            pauxB = pauxB->direita->abaixo;
         }

         pauxA = pauxA->abaixo->direita;
         pauxB = B->inicio->direita->abaixo;
         free(vetor_aux);
      }

      return C;
   }

   return NULL;
}

// Realiza a operação de soma de matrizes
MATRIZ_ESPARSA *somar_matriz(MATRIZ_ESPARSA *A, MATRIZ_ESPARSA *B) {
   // Condição para soma de matrizes
   if (A != NULL && B != NULL && A->nr_linhas == B->nr_linhas &&
       A->nr_colunas == B->nr_colunas) {
      int i, j;

      // Nós auxiliares para percorrerem as matrizes
      CELULA *pauxA = A->inicio;
      CELULA *pauxB = B->inicio;

      // A matriz resultante possui a qnt de linhas de A e colunas de B
      MATRIZ_ESPARSA *C = criar_matriz(A->nr_linhas, B->nr_colunas);

      for (i = 0; i < A->nr_linhas; i++) {

         pauxA = pauxA->abaixo->direita;
         pauxB = pauxB->abaixo->direita;

         // Copia a atual linha da matriz A no vetor
         int *vetor_aux = (int *)calloc(A->nr_colunas, sizeof(int));
         while(pauxA->coluna != -1) {
            vetor_aux[pauxA->coluna] = pauxA->valor;
            pauxA = pauxA->direita;
         }
         // Soma os elementos de B com os elementos do vetor
         while(pauxB->coluna != -1) {
            vetor_aux[pauxB->coluna] += pauxB->valor;
            pauxB = pauxB->direita;
         }

         for (j = 0; j < A->nr_colunas; j++) {
            if (vetor_aux[j] != 0) {
               set_matriz(C, i, j, vetor_aux[j]);
            }
         }
         free(vetor_aux);
      }
      return C;
   }

   return NULL;
}

// Imprime as células inseridas na matriz
void imprimir_matriz(MATRIZ_ESPARSA *matriz) {
   if (matriz != NULL) {
      int i, j;
      CELULA *paux = matriz->inicio->abaixo;

      // Dimensões da matriz
      printf("-1 %d %d\n", matriz->nr_linhas, matriz->nr_colunas);

      for (i = 0; i < matriz->nr_linhas; i++) {
         for (j = 0; j < matriz->nr_colunas; j++) {
	   // Se a posição for válida
            if (paux->direita->linha == i && paux->direita->coluna == j) {
               paux = paux->direita;
               printf("%d %d %d\n", paux->linha, paux->coluna, paux->valor);
            }
         }
         paux = paux->direita->abaixo;
      }
   }
}
