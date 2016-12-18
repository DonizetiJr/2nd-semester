#include <heap.h>
#include <item.h>
#include <stdlib.h>
#include <stdio.h>

#define PAI(pos)       ((pos-1)/2)
#define FILHO_ESQ(pos) (pos*2+1)
#define FILHO_DIR(pos) (pos*2+2)
#define TAM 100

struct heap_estatica {
   ITEM *vetor[TAM];
   int fim;
}

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
         apagar_item(&(*heap)->vetor[i]);
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

int enfileirar(HEAP_ESTATICA *heap, ITEM *item) {
   if (!cheia(heap)) {
      heap->fim++;
      heap->vetor[heap->fim] = item;
      fix_up(heap);
      return 1;
   }

   return 0;
}

void swap(HEAP_ESTATICA *heap, int i, int j) {
   ITEM *tmp = heap->vetor[i];
   heap->vetor[i] = heap->vetor[j];
   heap->vetor[j] = tmp;
}

void fix_up(HEAP_ESTATICA *heap) {
   int pos = heap->fim;

   while (pos > 0 && heap->vetor[pos]->chave > heap->vetor[PAI(pos)]->chave) {
      swap(heap, pos, PAI(pos));
      pos = PAI(pos);
      PAI(pos) = PAI(PAI(pos));
   }
}

ITEM *desenfileirar(HEAP_ESTATICA *heap) {
   if (!vazia(heap)) {
      ITEM *item = heap->vetor[0];
      heap->vetor[0] = heap->vetor[heap->fim];
      heap->fim--;
      fix_down(heap);
      return item;
   }

   return NULL;
}

void fix_down(HEAP_ESTATICA *heap) {
   int pos = 0;

   while (pos <= heap->fim / 2) {
      int maiorfilho;
      if (FILHO_DIR(pos) <= heap->fim &&
         heap->vetor[FILHO_ESQ(pos)]->chave < heap->vetor[FILHO_DIR]->chave) {
         maiorfilho = FILHO_DIR(pos);
      } else {
         maiorfilho = FILHO_ESQ;
      }

      if (heap->vetor[pos]->chave >= heap->vetor[maiorfilho]->chave) {
         break;
      }

      swap(heap, pos, maiorfilho);
      pos = maiorfilho;
   }
}
