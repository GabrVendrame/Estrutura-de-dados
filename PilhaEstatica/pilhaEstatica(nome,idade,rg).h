#include <stdio.h>
#include <stdlib.h>

#define maxPilha 100
#define maxNome 80

typedef struct tipoDado{
    char nome[maxNome];
    int idade, rg;
} tipoDado;

typedef struct tipoPilha{
    tipoDado pilha[maxPilha];
    int topo;
}tipoPilha;

void criaPilha(tipoPilha *p);

int pilhaCheia(tipoPilha p);

int pilhaVazia(tipoPilha p);

tipoDado pilhaTopo(tipoPilha p);

int inserePilha(tipoPilha *p, tipoDado dado);

int removePilha(tipoPilha *p, tipoDado *dado);