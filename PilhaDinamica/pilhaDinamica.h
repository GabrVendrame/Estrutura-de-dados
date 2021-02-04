#include <stdio.h>
#include <stdlib.h>

typedef struct tipoE{
    int dado;
    struct tipoE *prox;
} tipoE;

typedef tipoE *tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaVazia(tipoPilha p);

int pilhaCheia(tipoPilha p);

int pilhaTopo(tipoPilha p, int *topo);

int inserePilha(tipoPilha *p, int dado);

int removePilha(tipoPilha *p, int *dado);
