#include <stdio.h>
#include <stdlib.h>
#include <racional.h>

int main(int argc, char *argv[]) {
  RACIONAL* r1 = create(2,3);
  RACIONAL* r2 = create(3,3);
  print(r1);
  print(r2);

  RACIONAL* r3 = sum(r1, r2);
  print(r3);

  erase(&r1);
  erase(&r2);
  erase(&r3);
  
  return 0;
}

