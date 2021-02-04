#include <stdio.h>
#include <stdlib.h>

#define maxPilha 100

typedef struct tipoPilha{
    int pilha[maxPilha];
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

int pilhaTopo(tipoPilha p){
    return p.pilha[p.topo];
}

int inserePilha(tipoPilha *p, int x){
    if(pilhaCheia(*p)){
        return 0;
    }
    else{
        p->topo++;
        p->pilha[p->topo] = x;
        return 1;
    }
}

int removePilha(tipoPilha *p, int *x){
    if(pilhaVazia(*p)){
        return 0;
    }
    else{
        *x = p->pilha[p->topo];
        p->topo--;
        return 1;
    }
}

void mostraPilha(tipoPilha p){
}




