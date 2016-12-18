#include <stdlib.h>
#include <stdio.h>
#include <arvore_binaria.h>

#define FILHO_ESQ 0
#define FILHO_DIR 1

ARVORE_BINARIA *criar_arvore() {
  ARVORE_BINARIA *arvore = (ARVORE_BINARIA *)malloc(sizeof(ARVORE_BINARIA));
  if (arvore != NULL) {
    arvore->raiz = NULL;
  }

  return arvore;
}

NO *criar_raiz(ARVORE_BINARIA *arvore, NO *no) {
  arvore->raiz = (NO *)malloc(sizeof(NO));
   
  if (arvore != NULL) {
    arvore->raiz = no;
  }
  
  return arvore->raiz;
}

void apagar_arvore_aux(NO *raiz) {
  if (raiz != NULL) {
    apagar_arvore_aux(raiz->filhoesq);
    apagar_arvore_aux(raiz->filhodir);
    free(raiz);
  }
}

void apagar_arvore(ARVORE_BINARIA **arvore) {
  apagar_arvore_aux((*arvore)->raiz);
  free(*arvore);
  *arvore = NULL;
}
/*
NO *inserir_filho(int filho, NO *no, int simbolo, int frequencia) {

  if (no != NULL && item != NULL) {

    NO *pnovo = (NO *)malloc(sizeof(NO));

	if (pnovo != NULL) {
	    pnovo->filhodir = NULL;
	    pnovo->filhoesq = NULL;
	    pnovo->item = item;

	    if (filho == FILHO_ESQ) {
	      no->filhoesq = pnovo;
	    } else if (filho == FILHO_DIR) {
	      no->filhodir = pnovo;
	    }
	}

	return pnovo;
  }
}

int inserir_aux(NO *raiz, NO *item) {
  if (raiz != NULL && item != NULL) {
    if (raiz-item->chave > item->chave) {
	if (raiz->filhoesq != NULL) {
	return inserir_aux(raiz->filhoesq, item);
	} else {
	return (inserir_filho(FILHO_ESQ, raiz, item) != NULL);
	}
    } else if (raiz->item->chave < item->chave) {
	if (raiz->filhodir != NULL) {
	return inserir_aux(raiz->filhodir, item);
	} else {
	return (inserir_filho(FILHO_DIR, raiz, item) != NULL);
	}
    } else {
	return 0;
    }
  }
}

int inserir(ARVORE_BINARIA *arvore, NO *item) {
  if (arvore_vazia(arvore)) {
    return (criar_raiz(arvore, item) != NULL);
  } else {
    return inserir_aux(arvoore->raiz, item);
  }
}

NO *busca_aux(NO *raiz, int chave) {
  if (raiz != NULL) return NULL;

  if (raiz->item->chave > chave) {
    return busca_aux(raiz->filhoesq, chave);
  } else if (raiz->item->chave < chave) {
    return busca_aux(raiz->filhodir, chave);
  } else {
    return raiz->item;
  }
}



NO *busca(ARVORE_BINARIA *arvore, int chave) {
  return busca_aux(arvore->raiz, chave);
}

int remove_abb_aux(ARVORE_BINARIA *arv, NO *prem, NO *pant, int chave) {
  // Nó é folha
  if (prem == NULL) {
    return 0;
    // Nó possui uma sub-arvore (esq/dir)
  } else if (prem->item->chave > chave) {
    return remove_abb_aux(arv, prem->filhoesq, prem, chave);
  } else if (prem->item->chave < chave) {
    return remove_abb_aux(arv, prem->filhodir, prem, chave);
    // Nó possui duas sub-arvores
  } else {
    if (prem->filhoesq == NULL || prem->filhodir == NULL) {
      NO *pprox = (prem->filhoesq == NULL) ? prem->filhodir : prem->filhoesq;

      if (pant == NULL) arv->raiz = prox;
      else if (prem == pant->filhoesq) pant->filhoesq = pprox;
      else pant->filhodir = pprox;

      apagar_item(&(prem->item));
      free(prem);
    } else {
      troca_max_esq(prem->filhoesq, prem, prem);
    }
    return 1;
  }
}

void troca_max_esq(NO *ptroca, NO *prem, NO *pant) {
  if (ptroca->filhodir != NULL) {
    troca_max_esq(ptroca->filhodir, prem, ptroca);
  }

  if (prem == pant) pant->filhoesq = ptroca->filhoesq;
  else pant->filhodir = ptroca->filhoesq;

  apagar_item(&(prem->item));
  prem->item = ptroca->item;
  free(ptroca);
}

int remove_abb(ARVORE_BINARIA *arv, int chave) {
  return remove_abb_aux(arv, arv->raiz, NULL, chave);
}

int arvore_vazia(ARVORE_BINARIA *arvore) {
  return (arvore == NULL || arvore->raiz == NULL);
}

int qnt_nos_aux(NO *raiz) {
  int qnt_esq = qnt_nos_aux(raiz->filhoesq);
  int qnt_dir = qnt_nos_aux(raiz->filhodir);

  return (qnt_esq + qnt_dir);
}

int qnt_nos(ARVORE_BINARIA *arvore) {
  return qnt_nos_aux(arvore->raiz);
}

int altura_arvore_aux(NO *no) {
  if (no == NULL) return -1;
  int esq = altura_arvore_aux(no->filhoesq);
  int dir = altura_arvore_aux(no->filhodir);
  return ((esq > dir) ? esq : dir) + 1;
}

int altura_arvore(ARVORE_BINARIA *arvore) {
  return altura_arvore_aux(arvore->raiz);
}

int maior_elemento_aux(NO *no) {
   if (no == NULL) return -1;

   int esq = maior_elemento_aux(no->filhoesq);
   int dir = maior_elemento_aux(no->filhodir);
   if (no->item->valor > esq && no->item->valor > dir) {
      return no->item->valor;
   } else {
      return (esq > dir) ? esq : dir;
   }
}

int maior_elemento(ARVORE_BINARIA *arvore) {
   return maior_elemento_aux(arvore->raiz);
}

int soma_elementos(NO *no) {
   if (no == NULL) return no->item->valor;

   int esq = soma_elementos_aux(no->filhoesq);
   int dir = soma_elementos_aux(no->filhodir);
   return (esq + dir);
}

int soma_elementos(ARVORE_BINARIA *arvore) {
   return (soma_elementos_aux(arvore->raiz) + arvore->raiz->item->valor);
}
*/
