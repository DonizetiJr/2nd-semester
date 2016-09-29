#include <stdlib.h>
#include <stdio.h>
#include <item.h>

ITEM *criar_item(int tipo_union, int valor) {
  ITEM *item = (ITEM *)malloc(sizeof(ITEM));

  if (tipo_union == TIPO_CHAR) {
    item->vchar = valor; 
  } else {
    item->vint = valor;
  }

  item->tipo_union = tipo_union;
  return item;
}

void apagar_item(ITEM **item) {
  if(item != NULL && *item != NULL) {
    free(*item);
    *item = NULL;
  }
}

void imprimir_item(ITEM *item) {
  if(item != NULL) {
    if (item->tipo_union = TIPO_CHAR) {
      printf("%c\n", item->vchar);
    } else {
      printf("%d\n", item->vint);
    }
  }
}
