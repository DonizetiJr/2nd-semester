#ifndef HEAP_H
#define HEAP_H

   typedef struct heap_estatica HEAP_ESTATICA;

   HEAP_ESTATICA *criar_heap();
   void apagar_heap(HEAP_ESTATICA **heap);

   int cheia(HEAP_ESTATICA *heap);
   int vazia(HEAP_ESTATICA *heap);

   int enfileirar(HEAP_ESTATICA *heap, ITEM *item);
   void swap(HEAP_ESTATICA *heap, int i, int j);
   void fix_up(HEAP_ESTATICA *heap);
   ITEM *desenfileirar(HEAP_ESTATICA *heap);
   void fix_down(HEAP_ESTATICA *heap);

#endif
