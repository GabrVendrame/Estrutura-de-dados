#include <stdio.h>
#include <stdlib.h>

#define maxPilha 100

typedef struct tipoPilha{
    int pilha[maxPilha];
    int topo;
}tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaCheia(tipoPilha p);

int pilhaVazia(tipoPilha p);

int pilhaTopo(tipoPilha p);

int inserePilha(tipoPilha *p, int x);

int removePilha(tipoPilha *p, int *x);

void mostraPilha(tipoPilha p);



