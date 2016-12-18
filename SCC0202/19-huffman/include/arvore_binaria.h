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
/*NO *inserir_filho(int filho, NO *no, NO *item);

int inserir(ARVORE_BINARIA *arvore, NO *item);
NO *busca(ARVORE_BINARIA *arvore, int chave);
int remove_abb(ARVORE_BINARIA *arv, int chave);
int arvore_vazia(ARVORE_BINARIA *arvore);

int qnt_nos(ARVORE_BINARIA *arvore);
int altura_arvore(ARVORE_BINARIA *arvore);
int maior_elemento(ARVORE_BINARIA *arvore)
*/
#endif
