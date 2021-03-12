#include <stdio.h>
#include <stdlib.h>

#define maxNome 80

typedef struct tipoDado{
    char nome[maxNome];
    int idade, rg;
} tipoDado;

typedef struct tipoE{
    tipoDado dado;
    struct tipoE *prox;
} tipoE;

typedef tipoE *tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaVazia(tipoPilha p);

int pilhaCheia(tipoPilha p);

int pilhaTopo(tipoPilha p, int *topo);

int inserePilha(tipoPilha *p, tipoDado dado);

int removePilha(tipoPilha *p, tipoDado *dado);
