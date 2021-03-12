#include <stdio.h>
#include <stdlib.h>

#define maxFila 100

typedef struct tipoFila{
    int fila[maxFila];
    int prim, ult, quant;
} tipoFila;

void criaFila(tipoFila *f){
    f->quant = 0;
    f->ult = -1;
    f->prim = 0;
}

int filaVazia(tipoFila f){
    return f.quant == 0;
}

int filaCheia(tipoFila f){
    return f.quant == maxFila;
}

int primeiroF(tipoFila f, int *dado){
    if(filaVazia(f)){
        return 0;
    } else{
        *dado = f.fila[f.prim];
        return 1;
    }
}

int enfileira(tipoFila *f, int dado){
    if(filaCheia(*f)){
        return 0;
    } else{
        f->ult = (f->ult + 1) % maxFila;
        f->fila[f->ult] = dado;
        f->quant++;
        return 1;
    }
}

int desenfileira(tipoFila *f, int *dado){
    if(filaVazia(*f)){
        return 0;
    } else{
        *dado = f->fila[f->prim];
        f->prim = (f->prim+1) % maxFila;
        f->quant--;
        return 1;
    }
}