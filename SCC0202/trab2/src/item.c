/* Donizeti C dos Santos Junior  9393882 */

#include <stdlib.h>
#include <stdio.h>
#include <item.h>

ITEM *create_item(int key, int value) {
  ITEM *item = (ITEM *)malloc(sizeof(ITEM));

  if(item != NULL) {
    item->key = key;
    item->value = value;
  }

  return item;
}

void delete_item(ITEM **item) {
  if(item != NULL && *item != NULL) {
    free(*item);
    *item = NULL;
  }
}

void print_item(ITEM *item) {
  if(item != NULL) {
    printf("%d/%d\n", item->key, item->value);
  }
}
