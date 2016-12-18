#include <stdlib.h>
#include <stdio.h>
#include <heap.h>

#define TAM 100

struct heap_estatica {
   NO *vetor[TAM];
   int fim;
};

HEAP_ESTATICA *criar_heap() {
   HEAP_ESTATICA *heap = (HEAP_ESTATICA *)malloc(sizeof(HEAP_ESTATICA));
   if (heap != NULL) {
      heap->fim = -1;
   }

   return heap;
}

void apagar_heap(HEAP_ESTATICA **heap) {
   if (*heap != NULL && heap != NULL) {
      for (int i = 0; i <= (*heap)->fim; i++) {
	 free(&(*heap)->vetor[i]->filhoesq);
	 free(&(*heap)->vetor[i]->filhodir);
	 free(&(*heap)->vetor[i]);
      }

      free(*heap);
      *heap = NULL;
   }
}

int cheia(HEAP_ESTATICA *heap) {
   return (heap->fim == TAM - 1);
}

int vazia(HEAP_ESTATICA *heap) {
   return (heap->fim == -1);
}

void swap(HEAP_ESTATICA *heap, int i, int j) {
   NO *tmp = heap->vetor[i];
   heap->vetor[i] = heap->vetor[j];
   heap->vetor[j] = tmp;
}

void fix_up(HEAP_ESTATICA *heap) {
   int pos = heap->fim;
   int pai = (pos - 1) / 2;
   
   while (pos > 0 &&
	  heap->vetor[pos]->frequencia > heap->vetor[pai]->frequencia) {
      swap(heap, pos, pai);
      pos = pai;
      pai = (pai - 1) / 2;
   }
}

int inserir_heap(HEAP_ESTATICA *heap, NO *no) {
   if (!cheia(heap)) {
      heap->fim++;
      heap->vetor[heap->fim] = no;
      fix_up(heap);
      return 1;
   }

   return 0;
}

void fix_down(HEAP_ESTATICA *heap) {
   int pos = 0;

   while (pos <= heap->fim / 2) {
      int maiorfilho;
      int filhoesq = 2 * pos + 1;
      int filhodir = 2 * pos + 2;
     
      if (filhodir <= heap->fim &&
         heap->vetor[filhoesq]->simbolo < heap->vetor[filhodir]->frequencia) {
         maiorfilho = filhodir;
      } else {
         maiorfilho = filhoesq;
      }

      if (heap->vetor[pos]->frequencia >= heap->vetor[maiorfilho]->frequencia) {
         break;
      }

      swap(heap, pos, maiorfilho);
      pos = maiorfilho;
   }
}

NO *remover_heap(HEAP_ESTATICA *heap) {
   if (!vazia(heap)) {
      NO *no = heap->vetor[0];
      heap->vetor[0] = heap->vetor[heap->fim];
      heap->fim--;
      fix_down(heap);
      return no;
   }

   return NULL;
}

int tamanho_heap(HEAP_ESTATICA *heap) {
  return (heap->fim + 1);
}

void print_heap(HEAP_ESTATICA *heap) {
  if (heap != NULL) {
    for (int i = 0; i < heap->fim; i++) {
      printf("%c\n", (char)heap->vetor[i]->simbolo);
    }
  }
}
