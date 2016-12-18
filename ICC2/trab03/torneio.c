#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ENTER 10
#define VITORIA 3
#define DERROTA 0
#define EMPATE  1

typedef struct time {
  char *nome;
  int num_jogos;
  int vitorias;
  int empates;
  int derrotas;
  int gols_marcados;
  int gols_sofridos;
  int pontuacao;

} TIME;

typedef struct torneio {
  TIME **times;
  char *torneio_nome;
  int num_times;
  
  struct torneio *proximo;
} TORNEIO;

typedef struct torneios {
  TORNEIO *inicio;
  TORNEIO *fim;
  int tamanho;
} TORNEIOS;

TORNEIOS *criar_lista(int tamanho) {
  TORNEIOS *torneios = (TORNEIOS *)malloc(sizeof(TORNEIOS));

  if (torneios != NULL) {
    torneios->inicio = NULL;
    torneios->fim = NULL;
    torneios->tamanho = tamanho;

    TORNEIO *torneio_inicio = (TORNEIO *)malloc(sizeof(TORNEIO));

    if (torneio_inicio != NULL) {
      TORNEIO *paux = torneio_inicio;
      torneios->inicio = torneio_inicio; 
    
      for (int i = 0; i < tamanho - 1; i++) {
	TORNEIO *torneio = (TORNEIO *)malloc(sizeof(TORNEIO));
	paux->proximo = torneio;
	paux = torneio;
      }

      paux->proximo = NULL;
      torneios->fim = paux;
    }
  }

  return torneios;
}

void apagar_torneio(TORNEIO **torneio) {
  for (int i = 0; i < (*torneio)->num_times; i++) {
    free((*torneio)->times[i]->nome);
    free((*torneio)->times[i]);
  }
  
  free((*torneio)->torneio_nome);
  free(*torneio);
  *torneio = NULL;
}

void apagar_lista(TORNEIOS **torneios) {
  if (*torneios != NULL && torneios != NULL) {
    TORNEIO *prem = (*torneios)->inicio;
    TORNEIO *paux = NULL;

    for (int i = 0; i < (*torneios)->tamanho; i++) {
      paux = prem->proximo;
      apagar_torneio(&prem);
      prem = paux;
    }

    free(*torneios);
    *torneios = NULL;
  }
}


char *readLine(char limit) {
  int counter = 0;
  char c;
  char *string = NULL;

  do {
    c = fgetc(stdin);

    if (c != '\r') {
      string = (char *)realloc(string, sizeof(char)*(counter + 1));
      string[counter++] = c;
    }
   } while (c != ENTER && c != EOF && c != limit);
  
  string[counter - 1] = '\0';
  return string;
  
}

void insere_times(int num, TORNEIO *torneio) {
  if (torneio != NULL) {
    torneio->num_times = num;
    
    torneio->times = (TIME **)malloc(sizeof(TIME *) * num);

    for (int i = 0; i < num; i++) {	
      torneio->times[i] = (TIME *)malloc(sizeof(TIME));
      torneio->times[i]->nome = readLine('\n');
      torneio->times[i]->num_jogos = 0;
      torneio->times[i]->vitorias = 0;
      torneio->times[i]->derrotas = 0;
      torneio->times[i]->empates = 0;
      torneio->times[i]->pontuacao = 0;
    }
  }
}

void atribuicao_pontos(TORNEIO *torneio, char *time, int gols, int gols_adv) {
  if (torneio != NULL) {
    int i = 0;
    TIME *paux = torneio->times[i];

    while (i != torneio->num_times &&
	   strcmp(time, paux->nome) != 0) {

      paux = torneio->times[++i];
    }

    paux->num_jogos++;
    paux->gols_marcados += gols;
    paux->gols_sofridos += gols_adv;

    if (gols > gols_adv) {
      paux->vitorias++;
      paux->pontuacao += VITORIA;
      
    } else if (gols < gols_adv) {
      paux->derrotas++;
      
    } else {
      paux->empates++;
      paux->pontuacao += EMPATE;
    }
  }
}

void pontuacoes(int num, TORNEIO *torneio) {
  if (torneio != NULL) {
    char *time1, *time2;
    int gols1, gols2;

    for (int i = 0; i < num; i++) {
      time1 = readLine('#');
      gols1 = atoi(readLine('@'));
      
      gols2 = atoi(readLine('#'));
      time2 = readLine('\n');

      atribuicao_pontos(torneio, time1, gols1, gols2);
      atribuicao_pontos(torneio, time2, gols2, gols1);
    }
  }
}

// Retorna 1 se nome1 for menor e 0 se maior ou igual
int comparacao_nomes(char *nome1, char *nome2) {
  int i;
  char c1, c2;

  if (strlen(nome1) >= strlen(nome2)) {
    i = strlen(nome1);
  } else {
    i = strlen(nome2);
  }

  for (int j = 0; j < i; j++) {
    if (nome1[j] > 64 && nome1[j] < 97) {
      c1 = nome1[j] + 32;
    } else {
      c1 = nome1[j];
    }
    if (nome2[j] > 64 && nome2[j] < 97) {
      c2 = nome2[j] + 32;
    } else {
      c2 = nome2[j];
    }
    if (c1 < c2) return 1;
    if (c1 > c2) return 0;
  }

  return 0;
}

int atual_maior(TIME *time1, TIME *time2) {
  if (time1 != NULL && time2 != NULL) {

    if (time1->pontuacao > time2->pontuacao) return 1;
    else if (time1->pontuacao == time2->pontuacao) {

      if (time1->vitorias > time2->vitorias) return 1;
      else if (time1->vitorias == time2->vitorias) {

	if ((time1->gols_marcados - time1->gols_sofridos) >
	     (time2->gols_marcados - time2->gols_sofridos)) return 1;
	else if ((time1->gols_marcados - time1->gols_sofridos) ==
	        (time2->gols_marcados - time2->gols_sofridos)) {

	  if (time1->gols_marcados > time2->gols_marcados) return 1;
	  else if (time1->gols_marcados == time2->gols_marcados) {

	    if (time1->num_jogos < time2->num_jogos) return 1;
	    else if (time1->num_jogos == time2->num_jogos) {

	      if (comparacao_nomes(time1->nome, time2->nome)) {
		return 1;
	      }
	    }
	  }
	}
      }
    }
  }
  return 0;
}

// Inverte a colocação entre times
void swap(TORNEIO *torneio, int left, int right) {
  TIME *aux = torneio->times[left];
  torneio->times[left] = torneio->times[right];
  torneio->times[right] = aux;
}

// Quicksort Lomuto
int partition(TORNEIO *torneio, int lo, int hi) {
  TIME *pivot = torneio->times[hi];
  int i = lo;

  
  for (int j = lo; j < hi; j++) {
    if (atual_maior(torneio->times[j], pivot)) {
      swap(torneio, i, j);
      i++;
    }
  }

  swap(torneio, i, hi);
  return i;
}

void quicksort(TORNEIO *torneio, int lo, int hi) {
  if (lo < hi) {
    int i = partition(torneio, lo, hi);
    quicksort(torneio, lo, i - 1);
    quicksort(torneio, i + 1, hi);
  }
}

void print_resultados(TORNEIOS *torneios) {
  if (torneios != NULL) {
    int diferenca_gols, i = 1;
    TORNEIO *torneio = torneios->inicio;

    while (torneio != NULL) {
      printf("%s\n", torneio->torneio_nome);

      for (int j = 0; j < torneio->num_times; j++) {
	
	diferenca_gols = torneio->times[j]->gols_marcados -
	                 torneio->times[j]->gols_sofridos;
	
	printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
	       i, torneio->times[j]->nome, torneio->times[j]->pontuacao,
	       torneio->times[j]->num_jogos, torneio->times[j]->vitorias,
	       torneio->times[j]->empates, torneio->times[j]->derrotas,
	       diferenca_gols, torneio->times[j]->gols_marcados, torneio->times[j]->gols_sofridos);

	i++;
      }

      if (torneio != torneios->fim) printf("\n");
      i = 1;
      torneio = torneio->proximo;
    }
  }
}


int main(int argc, char *argv[]) {
  int num_torneios, num_times, num_jogos;
  char *name;
  
  scanf("%d\n", &num_torneios);
  TORNEIOS *torneios = criar_lista(num_torneios);
  TORNEIO *torneio = torneios->inicio;
  
  for (int i = 0; i < num_torneios; i++) {
    // Lẽ o nome do campeonato
    name = readLine('\n');
    torneio->torneio_nome = name;
     
    // Lê a quantidade de times e seus nomes
    scanf("%d\n", &num_times);
    insere_times(num_times, torneio);
    
    // Lê a quantidade de jogos e seus resultados
    scanf("%d\n", &num_jogos);
    pontuacoes(num_jogos, torneio);

    torneio = torneio->proximo;
  }
  
  torneio = torneios->inicio;
  for (int i = 0; i < num_torneios; i++) {
    
    // Ordena o atual torneio
    quicksort(torneio, 0, torneio->num_times - 1);
    torneio = torneio->proximo;
  }
  
  print_resultados(torneios);
  
  apagar_lista(&torneios);
  
  return 0;
}
