//Donizeti Carlos dos Santos Junior 9393882

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <huffman.h>


int main(int argc, char const *argv[]) {
  int i;
  char *text, *textCompac, *textDescompac;
  text = (char *)malloc(10001 * sizeof(char));
  TABELA_HUFFMAN *tabela = criarTabelaHuffman(); // cria tabela Huffman
  
  // Lê o texto que será compactado
  for (i = 0; (text[i] = getchar()) != '\n' && i < 10000; ++i);
  text[i] = '\0';

  // Compacta o texto e modifica a tabela
  int sizeCompac = compactarHuffman(text, &textCompac, &tabela);
  // Descompacta o texto baseado na tabela criada
  textDescompac = descompactarHuffman(textCompac, sizeCompac, tabela);
  
  // Imprime o tamanho do texto original
  printf("%d\n", (int)strlen(text) - 7);
  // Imprime o tamanho do texto Compactado
  printf("%d\n", sizeCompac);
  // Imprime o texto descompactado
  printf("%s\n", textDescompac);
  
  // Libera a memória alocada para a tabela de Huffman
  liberarTabelaHuffman(&tabela);
  free(text);
  free(textCompac);
  free(textDescompac);

  return 0;
}
