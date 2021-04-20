#include <stdio.h>
#include <stdlib.h>

#define maxNome 100

typedef struct tipoDado{
    char nome[maxNome];
    int rg, idade;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *esq, *dir;
} tipoNo;

typedef tipoNo *tipoPonteiroNo;

typedef struct tipoE{
    tipoPonteiroNo dado;
    struct tipoE *prox;
} tipoE;

typedef tipoE *tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaVazia(tipoPilha p);

int pilhaCheia(tipoPilha p);

int pilhaTopo(tipoPilha p, tipoPonteiroNo *topo);

int empilha(tipoPilha *p, tipoPonteiroNo dado);

int desempilha(tipoPilha *p, tipoPonteiroNo *dado);