// DOnizeti Carlos dos Santos Junior 9393882

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <huffman.h>

#define NR_SIMBOLOS 500
#define TAM 500

struct huffman {
  ARVORE_BINARIA *arvore;
  char codigo[NR_SIMBOLOS][TAM];
  int qnt_bits;
  int tamanho_original;
};


char *strrev(char *str){
  char *p1, *p2;

  if (! str || ! *str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
    *p1 ^= *p2;
    *p2 ^= *p1;
    *p1 ^= *p2;
  }
  return str;
}

char *dec2bin(int n) {
  char *binary = (char *)malloc(sizeof(char) * 9);
  int index = 0;

  while (n != 0) {
    binary[index] = (n % 2) + '0';
    n /= 2;
    index++;
  }
  binary[index] = '\0';

  // Inverter o valor binário encontrado
  strrev(binary);
  return binary;
}

int bin2dec(char *bin) {
  int i, resultado = 0, aux = 1;
  int size = strlen(bin);

  for (i = size - 1; i >= 0; i--) {
    if (bin[i] == '1') {
      resultado += aux;
    }

    aux *= 2;
  }

  return resultado;
}

TABELA_HUFFMAN *criarTabelaHuffman() {
  TABELA_HUFFMAN *huffman = (TABELA_HUFFMAN *)malloc(sizeof(TABELA_HUFFMAN));
  int i;

  if (huffman != NULL) {
    for (i = 0; i < TAM; i++) {
      huffman->codigo[i][0] = '\0';
    }

    huffman->arvore = criar_arvore();
    huffman->qnt_bits = 0;
  }

  return huffman;
}

void liberarTabelaHuffman(TABELA_HUFFMAN **huffman) {
  apagar_arvore(&((*huffman)->arvore));
  free(*huffman);
  *huffman = NULL;
}

void criar_codigo_aux(TABELA_HUFFMAN *huffman, NO *no, char *codigo, int fim, char *textCompac) {
  if (huffman != NULL && no != NULL) {
    if (no ->filhoesq == NULL && no->filhodir == NULL) {
      int i;
      for (i = 0; i <= fim; i++) {
	huffman->codigo[(int) no->simbolo][i] = codigo[i];
	huffman->qnt_bits += no->frequencia;
      }
      huffman->codigo[(int) no->simbolo][fim + 1] = '\0';

    } else {
      if (no->filhoesq != NULL) {
	codigo[fim + 1] = '0';
	criar_codigo_aux(huffman, no->filhoesq, codigo, fim + 1, textCompac);
      }

      if (no->filhodir != NULL) {
	codigo[fim+1] = '1';
	criar_codigo_aux(huffman, no->filhodir, codigo, fim + 1, textCompac);
      }
    }
  }
}

void criar_codigo(TABELA_HUFFMAN *huffman, char *textCompac) {
  char codigo[TAM];
  criar_codigo_aux(huffman, huffman->arvore->raiz, codigo, -1, textCompac);
}

void codificar(TABELA_HUFFMAN *huffman, char *msg, char *codigo) {
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

void preenchimento(char *textCompac) {
  int size = strlen(textCompac);
  int aux = 8 - (size % 8);
  int index = 0;
  char *bits_restantes;

  if (aux == 8) aux = 0; // Número exato de bits
  
  if (aux != 0) {
    for (int i = 0; i < aux; i++) {
      textCompac[size + i] = '0';
    }
  }

  bits_restantes = dec2bin(aux);
  
  for (int i = 0; i < 8; i++) {
    if (i < 8 - strlen(bits_restantes)) {
      textCompac[size + aux + i] = '0';
    }
    else {
      textCompac[size + aux + i] = bits_restantes[index++];
    }
  }
  textCompac[size + aux + 8] = '\0';
}

int compactarHuffman(char *msg, char **textCompac , TABELA_HUFFMAN **huffman) {
  //void criar_arvore_huffman(TABELA_HUFFMAN *huffman, char *msg) {
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
  (*huffman)->arvore->raiz = criar_raiz((*huffman)->arvore, remover_heap(heap));
   
  apagar_heap(&heap);
  criar_codigo(*huffman, *textCompac);

  (*huffman)->tamanho_original = (int)strlen(msg);
  (*huffman)->qnt_bits += (8 - (*huffman)->qnt_bits % 8) + 8;
  if ((*huffman)->qnt_bits % 8 == 0) (*huffman)->qnt_bits -= 8;

  *textCompac = (char *)malloc(sizeof(char) * (*huffman)->qnt_bits + 9);
  codificar(*huffman, msg, *textCompac);

  int auxx = strlen(*textCompac);

  preenchimento(*textCompac);
  
  return (strlen((*textCompac)) / 8);
}


char *descompactarHuffman(char *textCompac, int sizeCompac, TABELA_HUFFMAN *huffman){
  //int descompactarHuffman(TABELA_HUFFMAN *huffman, char *codigo, char *msg) {
  int i, decod_fim, bits_aux, limite;
  char *aux;
  char *msg = (char *)malloc(sizeof(char) * huffman->tamanho_original);
  decod_fim = -1;

  // Descobrir onde deve-se para a leitura do textCompac
  for (i = 0; i < 8; i++) {
    aux[i] = textCompac[(sizeCompac * 8) - 7 + i];
  }
  bits_aux = bin2dec(aux);
  
  NO *pno = huffman->arvore->raiz;

  if (bits_aux == 0)  limite = 0;
  else limite = bits_aux;

  for (i = 0; i < ((sizeCompac * 8) - limite - 8); i++) {
    if (textCompac[i] == '0') {
      pno = pno->filhoesq;
    } else if (textCompac[i] == '1') {
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
  return msg;
}
