#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

char *readLine() {
  int counter = 0;
  char c;
  char *string = NULL;

  do {
    c = fgetc(stdin);

    string = (char *)realloc(string, sizeof(char)*(counter+1));
    string[counter++] = c;
    
  } while (c != '\n');
  string[counter-1] = '\0';

  return string;
  
}

void erase(char *s) {
  if(s != NULL) {
    free(s);
    s = NULL;
  }
}

// Calculates the length of the string pointed to, excluding the terminating null byte ('\0).
int letter_qnt(char *s) {
  int i = 0, counter = 0;
  char c;
  
  while(s[i] != '\0') {
    counter++;
    i++;
  }
  return counter;
}

// Return 1 if s1 is found in s2 and return 0 if s1 is not found.
int strfind(char *s1, char *s2) {
  int len1, len2;
  int i, counter = 0;

  len1 = letter_qnt(s1);
  len2 = letter_qnt(s2);
  
  for (i = 0; i < len2; i++) {
    if(s2[i] == s1[counter]) {
      counter++;
      if(counter == len1) return 1;
    }
  }
  return 0;
}

// Compares two strings, returning 1 if they are icos and 0 if they are differents.
int strcmp(char *s1, char *s2) {
  int len1, len2, i;

  len1 = letter_qnt(s1);
  len2 = letter_qnt(s2);

  if(len1 != len2) return 0;

  for (i = 0; i < len1; i++)
    if(s1[i] != s2[i]) return 0;

  return 1;
}

// Appends the src string to the dest string, overwriting the terminating null bite and the adds
//a terminating null byte.
char *strcat(char *src, char *dest) {
  int len1, len2;
  int i, counter = 0;
  char *s = NULL;

  len1 = letter_qnt(src);
  len2 = letter_qnt(dest);

  for (i = 0; i < len2; i++) {
    s = (char *)realloc(s, sizeof(char)*(i+1));
    s[i] = dest[i];
  }
  
  for (i = 0; i < len1; i++) {
    s = (char *)realloc(s, sizeof(char)*(len2+i+1));
    s[len2+i] = src[i];
  }
  s[len2+i] = '\0';
  return s;
}

