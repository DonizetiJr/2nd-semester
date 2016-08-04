#include <stdio.h>
#include <utils.h>

int main(int argc, char *argv[]) {
  int debug;
  char *s1, *s2, *s3;

  s1 = readLine();
  s2 = readLine();

  debug = letter_qnt(s1);
  printf("s1 size = %d\n", debug);
  debug = letter_qnt(s2);
  printf("s2 size = %d\n", debug);

  debug = strfind(s1, s2);
  printf("S1 is found? %d\n", debug);

  debug = strcmp(s1, s2);
  printf("Comparison: %d\n", debug);

  s3 = strcat(s1, s2);
  debug = letter_qnt(s3);
  printf("New string: %s\nNew string size: %d\n", s3, debug);
  
  erase(s1);
  erase(s2);
  erase(s3);
  
  return 0;
}
