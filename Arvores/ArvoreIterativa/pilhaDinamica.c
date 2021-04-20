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

void criaPilha(tipoPilha *p){
    *p = NULL;
}

int pilhaVazia(tipoPilha p){
    return p == NULL;
}

int pilhaCheia(tipoPilha p){
    return 0;
}

int pilhaTopo(tipoPilha p, tipoPonteiroNo *topo){
    if(pilhaVazia(p)){
        return 0;
    } else{
        *topo = p->dado;
        return 1;
    }
}

int empilha(tipoPilha *p, tipoPonteiroNo dado){
    tipoE *aux;
    aux = malloc(sizeof(tipoE));
    aux->dado = dado;
    aux->prox = *p;
    *p = aux;
    return 1;
}

int desempilha(tipoPilha *p, tipoPonteiroNo *dado){
    tipoE *aux;
    if(pilhaVazia(*p)){
        return 0;
    } 
    else{
    *dado = (*p)->dado;
    aux = *p;
    *p = aux->prox;
    free(aux);
    return 1;
    }
}