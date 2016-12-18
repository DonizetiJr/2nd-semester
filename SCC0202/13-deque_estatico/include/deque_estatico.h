#ifndef FILA_ESTATICA_H
#define FILA_ESTATICA_H

typedef struct fila_estatica FILA_ESTATICA;

FILA_ESTATICA *criar_fila();
void apagar_fila_estatica(FILA_ESTATICA *fila);

int enfileirar(FILA_ESTATICA *fila, ITEM *item);
ITEM *desenfileirar(FILA_ESTATICA *fila);

int fila_estatica_cheia(FILA_ESTATICA *fila);
int fila_estatica_vazia(FILA_ESTATICA *fila);
int tamanho_fila_estatica(FILA_ESTATICA *fila);

#endif
