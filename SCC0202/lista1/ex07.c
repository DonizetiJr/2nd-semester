// Escreva uma função que receba uma string e retorne 1 se essa for um palíndromo e 0 caso contrário.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENTER 10

typedef enum {
   FALSE,
   TRUE
} bool;

char *readLine() {
   char c;
   int counter = 0;
   char *str = NULL;

   do {
      c = fgetc(stdin);
      str = (char *)realloc(str, sizeof(char)*(counter + 1));
      str[counter++] = c;

   } while (c != ENTER);
   str[counter-1] = '\0';
   
   return str;
}

bool isPalindrome(char *str) {
  int len, i;

  len = strlen(str);
  
  for (i = 0; i < len/2; i++) {
     if(str[i] != str[len-i-1])
       return FALSE;
  }
   return TRUE;
}

int main(int argc, const char *argv[]) {
   char *str;

   str = readLine();
   printf("%d\n",isPalindrome(str));

   free(str);

   return 0;
}
