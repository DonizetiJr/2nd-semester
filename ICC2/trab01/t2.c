#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bin2dec_iterative(int n) {
  int decimal = 0, i = 0, aux;

  while (n != 0) {
    aux = n%10;
    decimal += aux*pow(2,i);
    n /= 10;
    ++i;
  }
  return decimal;
}

int bin2dec_recursive(int n) {
  if(!(n/10)) return n;
  return (n % 10 + bin2dec_recursive(n/10)*2);
}

int main(int argc, const char *argv[]) {
  int n;
  
  scanf("%d", &n);
  printf("%d\n%d\n", bin2dec_iterative(n), bin2dec_recursive(n));

  return 0;
}
