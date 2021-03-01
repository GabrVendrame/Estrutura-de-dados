#include <stdio.h>
#include <stdlib.h>

struct tipoElem
{
    int dado;
    struct tipoElem *prox;
};

typedef struct tipoElem tipoElem;

typedef tipoElem *tipoFila;

void criaFila(tipoFila *f);

int filaCheia(tipoFila f);

int filaVazia(tipoFila f);

int primeiroFila(tipoFila f, int *dado);

int enfileira(tipoFila *f, int dado);

int desenfileira(tipoFila *f, int *dado);
