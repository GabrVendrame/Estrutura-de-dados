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

void criaPilha(tipoPilha *p){
    *p = NULL;
}

int pilhaVazia(tipoPilha p){
    return p == NULL;
}

int pilhaCheia(tipoPilha p){
    return 0;
}

int pilhaTopo(tipoPilha p, tipoDado *topo){
    if(pilhaVazia(p)){
        return 0;
    } else{
        *topo = p->dado;
        return 1;
    }
}

int inserePilha(tipoPilha *p, tipoDado dado){
    tipoE *aux;
    aux = malloc(sizeof(tipoE));
    aux->dado = dado;
    aux->prox = *p;
    *p = aux;
    return 1;
}

int removePilha(tipoPilha *p, tipoDado *dado){
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
