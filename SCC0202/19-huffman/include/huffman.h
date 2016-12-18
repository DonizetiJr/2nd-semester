#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <arvore_binaria.h>
#include <heap.h>

typedef struct huffman HUFFMAN;

HUFFMAN *criar_huffman();
void apagar_huffman(HUFFMAN **huffman);

void criar_arvore_huffman(HUFFMAN *huffman, char *msg);
void criar_codigo(HUFFMAN *huffman);
void codificar(HUFFMAN *huffman, char *msg, char *codigo);
int descodificar(HUFFMAN *huffman, char *codigo, char *msg);

#endif
