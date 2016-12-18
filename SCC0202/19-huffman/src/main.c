#include <stdio.h>
#include <huffman.h>


int main(int argc, char const *argv[]) {

  char msg[] = {"SUSIE SAYS ITS EASY"};
  char codigo[256];
  printf("Original: %s\n", msg);

  HUFFMAN *huffman = criar_huffman();

  criar_arvore_huffman(huffman, msg);
  criar_codigo(huffman);
  
  codificar(huffman, msg, codigo);

  descodificar(huffman, codigo, msg);
  printf("Descompactada %s\n", msg);
  
  apagar_huffman(&huffman);

  
  return 0;
}
