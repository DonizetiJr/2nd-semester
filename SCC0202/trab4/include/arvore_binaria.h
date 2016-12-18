//Donizeti Carlos dos Santos Junior 9393882

#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H


typedef struct no {
  int simbolo;
  int frequencia;

  struct no *filhoesq;
  struct no *filhodir;
} NO;

typedef struct arvore_binaria {
  NO *raiz;
} ARVORE_BINARIA;



ARVORE_BINARIA *criar_arvore();
void apagar_arvore(ARVORE_BINARIA **arvore);

NO *criar_raiz(ARVORE_BINARIA *arvore, NO *no);

#endif
