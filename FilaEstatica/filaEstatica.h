#include <stdio.h>
#include <stdlib.h>

#define maxFila 100

typedef struct tipoFila
{
    int fila[maxFila];
    int primeiro, ultimo, quant;
} tipoFila;

void criaFila(tipoFila *f);
int filaVazia(tipoFila f);
int filaCheia(tipoFila f);
int primeiroFila(tipoFila f, int *dado);
int enfileira(tipoFila *f, int dado);
int desenfileira(tipoFila *f, int *dado);
