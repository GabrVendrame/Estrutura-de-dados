#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define maxNome 80

typedef struct tipoDado{
    char nome[maxNome];
    int rg, idade;
} tipoDado;

typedef struct tipoNo{
    tipoDado dado;
    struct tipoNo *esq, *dir;
} tipoNo;

typedef tipoNo *tipoArvore;

int criaABB(tipoArvore *A){
    *A = NULL;
}

int vazia(tipoArvore A){
    return A == NULL;
}

int cheia(tipoArvore A){
    return 0;
}

int quantA(tipoArvore A){
    return -1;
}

int insere(tipoArvore *A, tipoDado D){
    int res;
    if(vazia(*A)){
        *A = malloc(sizeof(tipoNo));
        (*A)->dado = D;
        (*A)->esq = NULL;
        (*A)->dir = NULL;
        res = 1;
    } else{
        if(strcmp(((*A)->dado.nome), D.nome) < 0){
            res = insere(&((*A)->dir), D);
        } else if(strcmp(((*A)->dado.nome), D.nome) > 0){
            res = insere(&((*A)->esq), D);
        } else{
            res = 0;
        }
    }
    return res;
}

tipoDado maiorDosMenores(tipoArvore *esq){
    tipoArvore aux;
    tipoDado auxd;
    aux = *esq;
    if((*esq)->dir == NULL){
        auxd = aux->dado;
        *esq = aux->esq;
        free(aux);
    } else{
        auxd = maiorDosMenores(&((aux)->dir));
    }
    return auxd;
}

int remove(tipoArvore *A, tipoDado *D){
    tipoArvore aux;
    int res;
    if(vazia(*A)){
        res = 0;
    } else{
        if(strcmp(&(*A)->dado.nome, D->nome) < 0){
            res = remove(&((*A)->dir), D);
        } else if(strcmp(&(*A)->dado.nome, D->nome) > 0){
            res = remove(&((*A)->esq), D);
        } else{
            *D = (*A)->dado;
            aux = *A;
            if((*A)->esq == NULL){
                *A = aux->dir;
                free(aux);
            } else if((*A)->dir == NULL){
                *A = aux->esq;
                free(aux);
            } else{
                (*A)->dado = maiorDosMenores(&((*A)->esq));
            }
            res = 1;
        }
    }
    return res;
}

int consulta(tipoArvore A, tipoDado *D){
    int res;
    if(vazia(A)){
        res = 0;
    } else{
        if(strcmp(A->dado.nome, D->nome) < 0){
            res = consulta(A->dir, D);
        } else if(strcmp(A->dado.nome, D->nome) > 0){
            res = consulta(A->esq, D);
        } else{
            *D = A->dado;
            res = 1;
        }
    }
    return res;
}

void preOrdem(tipoArvore A){

}

void emOrdem(tipoArvore A){
    if(!vazia(A)){
        emOrdem(A->esq);
        printf("\nNome: %s\tRG: %d\tIdade: %d", A->dado.nome, A->dado.rg, A->dado.idade);
        emOrdem(A->dir);
    }
}

void posOrdem(tipoArvore A){

}