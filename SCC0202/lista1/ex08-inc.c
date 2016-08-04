// Escreva uma função que imprima todos os anagramas de uma palavra que contenhas letras não repetidas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTER 10

char *readLine() {
   int counter = 0;
   char c;
   char *str = NULL;

   do {
      c = fgetc(stdin);
      str = (char *)realloc(str, sizeof(char)*(counter+1));
      str[counter++] = c;
   } while (c != ENTER);
   str[counter - 1] = '\0';
   
   return str;
}

void swap(char *x, char *y) {
   char *aux = x;
   x = y;
   y = aux;
}

void anagrams(char *str, int l, int r) {
   int i;
   if(l == r) {
      printf("%s\n", str);
      return;
   }
   else {
      for (i = 0; i <=  r; i++) {
         swap((str+l),(str+i));
         anagrams(str, l+1, r);
         swap((str+i),(str+l)); //backtracking
      }
   }
}

int main(int argc, const char *argv[]) {
   int n;
   char *string;

   string = readLine();
   n = strlen(string);

   printf("%s", string);
   anagrams(string, 0, n-1); 

   free(string);

   return 0;
}
