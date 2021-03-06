#include <stdio.h>
#include <stdlib.h>
#include <complexo.h>

int main(int argc, char *argv[]) {
  COMPLEXO* comp1 = create(2,1);
  COMPLEXO* comp2 = create(4,3);

  print(comp1);
  print(comp2);

  COMPLEXO* comp3 = sum(comp1, comp2);
  print(comp3);
  
  COMPLEXO* comp4 = mult(comp1, comp2);
  print(comp4);

  erase(&comp1);
  erase(&comp2);
  erase(&comp3);
  erase(&comp4);
  return 0;
}
