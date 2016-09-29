/* Donizeti C dos Santos Junior  9393882 */

#ifndef ITEM_H
#define ITEM_H

typedef struct {
  int key;
  int value;
}ITEM;

ITEM *create_item(int key, int value);
void delete_item(ITEM **item);
void print_item(ITEM *item);

#endif
