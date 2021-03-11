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

void criaPilha(tipoPilha *p){
    p->topo = -1;
}

int pilhaCheia(tipoPilha p){
    return (p.topo == maxPilha-1);
}

int pilhaVazia(tipoPilha p){
    return (p.topo == -1);
} 

tipoDado pilhaTopo(tipoPilha p){
    return p.pilha[p.topo];
}

int inserePilha(tipoPilha *p, tipoDado dado){
    if(pilhaCheia(*p)){
        return 0;
    }
    else{
        p->topo++;
        p->pilha[p->topo] = dado;
        return 1;
    }
}

int removePilha(tipoPilha *p, tipoDado *dado){
    if(pilhaVazia(*p)){
        return 0;
    }
    else{
        *dado = p->pilha[p->topo];
        p->topo--;
        return 1;
    }
}