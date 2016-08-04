// Faça uma função que calcule todos os divisores de um número

#include <stdio.h>

void print_div(int n, int aux) {
  if(n >= aux) {
    if((n % aux) == 0)
      printf("%d\n", aux);
    print_div(n, aux+1);
  }
  return;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  printf("Divisores:\n");
  print_div(n, 1);
  
  return 0;
}
