#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

typedef struct tipoArvore{
    tipoPonteiroNo raiz;
    int quant;
} tipoArvore;

int criaArvore(tipoArvore *A){
    A->quant = 0;
    A->raiz = NULL;
}

int vazia(tipoArvore A){
    return A.raiz == NULL;
}

int cheia(tipoArvore A){
    return 0;
}

int quantA(tipoArvore A){
    return A.quant;
}

int insere(tipoArvore *A, tipoDado D){
    tipoPonteiroNo ant, prox, auxno;
    int sentido;
    if(cheia(*A)){
        return 0;
    } else{
        auxno = malloc(sizeof(tipoNo));
        if(vazia(*A)){
            A->raiz = auxno;
        } else{
            ant = NULL;
            prox = A->raiz;
            while(prox != NULL){
                ant = prox;
                if(strcmp(prox->dado.nome, D.nome) < 0){
                    sentido = 1;
                    prox = prox->dir;
                } else if(strcmp(prox->dado.nome, D.nome) > 0){
                    sentido = -1;
                    prox = prox->esq;
                } else{
                    free(auxno);
                    return 0;
                }
            }
            if(sentido == 1){
                ant->dir = auxno;
            } else{
                ant->esq = auxno;
            }
        }
        auxno->dado = D;
        auxno->dir = NULL;
        auxno->esq = NULL;
        return 1;
    }
}

int remove(tipoArvore *A, tipoDado *D){

}

int consulta(tipoArvore A, tipoDado *D){
    tipoPonteiroNo ant, prox;
    if(vazia(A)){
        return 0;
    } else{
        ant = NULL;
        prox = A.raiz;
        while(prox != NULL){
            if(strcmp(prox->dado.nome, D->nome) < 0){
                prox = prox->dir;
            } else if(strcmp(prox->dado.nome, D->nome) > 0){
                prox = prox->esq;
            } else{
                *D = prox->dado;
                return 1;
            }
        }
        return 0;
    }
}

int preOrdem(tipoArvore A){

}

int emOrdem(tipoArvore A){
    tipoPilha auxp;
    tipoPonteiroNo auxno;
    int acabou = 0;
    if(vazia(A)){
        return 0;
    } else{
        auxno = A.raiz;
        criaPilha(&auxp);
        do{
            if(auxno->esq != NULL){
                empilha(&auxp, auxno);
                auxno = auxno->esq;
            } else{
                printf("\nNOME: %s\tRG: %d\tIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                if(auxno->dado != NULL){
                    auxno = auxno->dir;
                } else{
                    acabou = (desempilha(&auxp, &auxno == 0));
                    while(!acabou && auxno->dir == NULL){
                        printf("\nNOME: %s\tRG: %d\tIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                        acabou = (desempilha(&auxp, &auxno == 0));
                    }
                    if(!acabou){
                        printf("\nNOME: %s\tRG: %d\tIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                        auxno = auxno->dir;
                    }
                }
            }
        } while(!acabou);
        return 1;
    }
}

int posOrdem(tipoArvore A){

}

