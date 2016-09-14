// include/utils.h

#ifndef UTILS_H
#define UTILS_H

#include <listaligada.h>

void sair_gerenciamento(LISTA_LIGADA **lista);
void cadastro(LISTA_LIGADA *lista, char cpf[], char primeiro_nome[], char ultimo_nome[], char telefone[]);
void buscar_cpf(LISTA_LIGADA *lista, char cpf[]);
void dump(LISTA_LIGADA *lista);
void remover_cpf(LISTA_LIGADA *lista, char cpf[]);

#endif
