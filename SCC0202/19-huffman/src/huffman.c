#include <stdlib.h>
#include <stdio.h>

#include <huffman.h>

#define NR_SIMBOLOS 500
#define TAM 500

struct huffman {
  ARVORE_BINARIA *arvore;
  char codigo[NR_SIMBOLOS][TAM];
};

HUFFMAN *criar_huffman() {
  HUFFMAN *huffman = (HUFFMAN *)malloc(sizeof(HUFFMAN));
  int i;

  if (huffman != NULL) {
    for (i = 0; i < TAM; i++) {
      huffman->codigo[i][0] = '\0';
    }

    huffman->arvore = criar_arvore();
  }

  return huffman;
}

void apagar_huffman(HUFFMAN **huffman) {
  apagar_arvore(&((*huffman)->arvore));
  free(*huffman);
  *huffman = NULL;
}

void criar_arvore_huffman(HUFFMAN *huffman, char *msg) {
  int i, freq[TAM];
  for (i = 0; i < TAM; i++) freq[i] = 0;
  for (i = 0; msg[i] != '\0'; i++) freq[(int) msg[i]]++;

  HEAP_ESTATICA *heap = criar_heap();

  // COloca cada caracter na heap com sua frequencia
   for (i = 0; i < TAM; i++) {
    if (freq[i] > 0) {
      NO *pno = (NO *)malloc(sizeof(NO));
      pno->simbolo = i;
      pno->frequencia = freq[i];
      pno->filhodir = NULL;
      pno->filhoesq = NULL;
      inserir_heap(heap, pno);
    }
  }
  // Criação do nó que será colocado na árvore
  while (tamanho_heap(heap) > 1) {
    NO *pno = (NO *)malloc(sizeof(NO));
    pno->simbolo = '#';
    pno->filhoesq = remover_heap(heap);
    pno->filhodir = remover_heap(heap);
    pno->frequencia = pno->filhoesq->frequencia + pno->filhodir->frequencia;
    inserir_heap(heap, pno);
  }
 
  // O nó restante da heap é colocado na árvore
  huffman->arvore->raiz = criar_raiz(huffman->arvore, remover_heap(heap));
  apagar_heap(&heap);
}

void criar_codigo_aux(HUFFMAN *huffman, NO *no, char *codigo, int fim) {
  if (huffman != NULL && no != NULL) {
    if (no ->filhoesq == NULL && no->filhodir == NULL) {
      int i;
      for (i = 0; i <= fim; i++) {
	huffman->codigo[(int) no->simbolo][i] = codigo[i];
      }

      huffman->codigo[(int) no->simbolo][fim + 1] = '\0';
    } else {
      if (no->filhoesq != NULL) {
	codigo[fim + 1] = '0';
	criar_codigo_aux(huffman, no->filhoesq, codigo, fim + 1);
      }

      if (no->filhodir != NULL) {
	codigo[fim+1] = '1';
	criar_codigo_aux(huffman, no->filhodir, codigo, fim + 1);
      }
    }
  }
}

void criar_codigo(HUFFMAN *huffman) {
  char codigo[TAM];
  criar_codigo_aux(huffman, huffman->arvore->raiz, codigo, -1);
}

void codificar(HUFFMAN *huffman, char *msg, char *codigo) {
  int i, j, cod_fim;
  cod_fim = -1;

  for (i = 0; msg[i] != '\0'; i++) {
    char *pcod = huffman->codigo[(int) msg[i]];

    for (j = 0; j < pcod[j] != '\0'; j++) {
      cod_fim++;
      codigo[cod_fim] = pcod[j];
    }
  }

  codigo[cod_fim + 1] = '\0';
}

int descodificar(HUFFMAN *huffman, char *codigo, char *msg) {
  int i, decod_fim;
  decod_fim = -1;

  NO *pno = huffman->arvore->raiz;

  for (i = 0; codigo[i] != '\0'; i++) {
    if (codigo[i] == '0') {
      pno = pno->filhoesq;
    } else if (codigo[i] == '1') {
      pno = pno->filhodir;
    } else {
      return 0;
    }

    if (pno->filhoesq == NULL && pno->filhodir == NULL) {
      msg[++decod_fim] = pno->simbolo;
      pno = huffman->arvore->raiz;
    }
  }

  msg[decod_fim + 1] = '\0';
  return 1;
}
