/* Donizeti C dos Santos Junior   9393882 */

#include <stdlib.h>
#include <stdio.h>
#include <item.h>
#include <array_list.h>

int main(int argc, char *argv[]) {
  ARRAY_LIST *arrayList = new_arrayList();
  ITEM *item = create_item(3,3);
  ITEM *item2 = create_item(5,5);
  ITEM *item3 = create_item(1,1);
  ITEM *item4 = create_item(2,2);
  ITEM *item5 = create_item(7,7);

  add_arrayList(arrayList, item);
  add_arrayList(arrayList, item2);
  add_arrayList(arrayList, item3);
  add_arrayList(arrayList, item4);
  add_arrayList(arrayList, item5);
 
  printf("Tamanho total: %d\n", size_arrayList(arrayList));
  
  print_arrayList(arrayList);
  
  printf("Sub array [1,3[\n");
  sub_arrayList(arrayList, 2, 4);
  /*
 
  if (contains_arrayList(arrayList, 3)) {
    printf("Busca ok!\n");
  }
  
  printf("Index do item 1: %d\n", indexOf_arrayList(arrayList, 1));

  print_item(get_arrayList(arrayList, 0));
   
  printf("\nSubstituições \n");
  ITEM *item_sub = create_item(0,0);
  set_arrayList(arrayList, 1, item_sub);

  ITEM *item4 = create_item(2,2);
  add_arrayList(arrayList, item4);
  
  print_arrayList(arrayList);
  */
  destroy_arrayList(&arrayList);

  return 0;
}
