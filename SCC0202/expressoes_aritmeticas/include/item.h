#ifndef ITEM_H
#define ITEM_H

#define TIPO_CHAR 0
#define TIPO_INT 1

typedef struct {
  int tipo_union;
  union {
    int vint;
    char vchar;
  };
}ITEM;

ITEM *criar_item(int tipo_union, int valor);
void apagar_item(ITEM **item);
void imprimir_item(ITEM *item);

#endif
