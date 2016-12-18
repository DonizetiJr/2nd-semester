#include <stdlib.h>
#include <stdio.h>

typedef struct mochila {
  int qnt_itens;
  int capacidade;
  int *valor;
  int *peso;
} MOCHILA ;

typedef struct mochilas {
  MOCHILA **mochila;
  int qnt_mochilas;
} MOCHILAS;

// Retorna o máximo de dois inteiros 
int max(int a, int b) {
  return (a > b) ? a : b;
}

// Retorna o máximo valor que pode-se colocar na mochila
int knapsack(int capacidade, int *peso, int *valor, int n) {
  int i, j;
  int aux[n+1][capacidade+1];

  // Construção do vetor aux
  for (i = 0; i <= n; i++) {
    for (j = 0; j <= capacidade; j++) {

      if (i == 0 || j == 0) 
	aux[i][j] = 0;
      else if (peso[i-1] <= j)
	aux[i][j] = max(valor[i-1] + aux[i-1][j-peso[i-1]], aux[i-1][j]);
      else 
	aux[i][j] = aux[i-1][j];
    }
  }

    return aux[n][capacidade];
}

void free_mochilas(MOCHILAS **mochilas) {
  for (int i = 0; i < (*mochilas)->qnt_mochilas; i++) {
    free((*mochilas)->mochila[i]->valor);
    free((*mochilas)->mochila[i]->peso);
    free((*mochilas)->mochila[i]);
  }
  free((*mochilas));
  *mochilas = NULL;
}

int main(int argc, char *argv[]) {
  int qnt_mochilas, qnt_itens, nr_item, capacidade, valor, peso;

  MOCHILAS *mochilas = (MOCHILAS *)malloc(sizeof(MOCHILAS));

  scanf("%d", &qnt_mochilas);
  mochilas->qnt_mochilas = qnt_mochilas;
  mochilas->mochila = (MOCHILA **)malloc(sizeof(MOCHILA *) * qnt_mochilas);

  for (int i; i < qnt_mochilas; i++) {
    mochilas->mochila[i] = (MOCHILA *)malloc(sizeof(MOCHILA));
    scanf("%d", &qnt_itens);
    mochilas->mochila[i]->qnt_itens = qnt_itens;
    mochilas->mochila[i]->valor = (int *)malloc(sizeof(int) * qnt_itens);
    mochilas->mochila[i]->peso = (int *)malloc(sizeof(int) * qnt_itens);

    scanf("%d", &capacidade);
    mochilas->mochila[i]->capacidade = capacidade;
    
    for (int j = 0; j < qnt_itens; j++) {
      scanf("%d %d %d", &nr_item, &valor, &peso);
      mochilas->mochila[i]->valor[j] = valor;
      mochilas->mochila[i]->peso[j] = peso;
    }
  }
  
  for (int i = 0; i < qnt_mochilas; i++) {
    printf("%d\n", knapsack(mochilas->mochila[i]->capacidade, mochilas->mochila[i]->peso,
			    mochilas->mochila[i]->valor, mochilas->mochila[i]->qnt_itens));
  }

  free_mochilas(&mochilas);
  
  return 0;
}
