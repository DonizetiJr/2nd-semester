//Donizeti Carlos dos Santos Junior 9393882

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <arvore_binaria.h>
#include <heap.h>

typedef struct huffman TABELA_HUFFMAN;

TABELA_HUFFMAN *criarTabelaHuffman();
void liberarTabelaHuffman(TABELA_HUFFMAN **huffman);

int compactarHuffman(char *msg, char **textCompac , TABELA_HUFFMAN **huffman);

char *descompactarHuffman(char *textCompac, int sizeCompac, TABELA_HUFFMAN *huffman);

#endif
