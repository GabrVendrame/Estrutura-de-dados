#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaDinamica.h"

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

int insereABB(tipoArvore *A, tipoDado D){
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
                    sentido = +1;
                    prox = prox->dir;
                } else if(strcmp(prox->dado.nome, D.nome) > 0){
                    sentido = -1;
                    prox = prox->esq;
                } else{
                    free(auxno);
                    return 0;
                }
            }
            if(sentido == +1){
                ant->dir = auxno;
            } else{
                ant->esq = auxno;
            }
        }
        auxno->dado = D;
        auxno->dir = NULL;
        auxno->esq = NULL;
        A->quant++;
        return 1;
    }
}

tipoDado maiorDosMenores(tipoPonteiroNo *esq){
    tipoPonteiroNo ant, prox;
    tipoDado dadoaux;
    ant = NULL;
    prox = *esq;
    while(prox->dir != NULL){
        ant = prox;
        prox = prox->dir;
    }
    if(ant == NULL){
        *esq = prox->esq;
    } else{
        ant->dir = prox->esq;
    }
    dadoaux = prox->dado;
    free(prox);
    return dadoaux;
}

int removeABB(tipoArvore *A, tipoDado *D){
    tipoPonteiroNo ant, prox;
    int sentido;
    if(vazia(*A)){
        return 0;
    } else{
        ant = NULL;
        prox = A->raiz;
        while(prox != NULL){
            if(strcmp(prox->dado.nome, D->nome) < 0){
                sentido = +1;
                prox = prox->dir;
            } else if(strcmp(prox->dado.nome, D->nome) > 0){
                sentido = -1;
                prox = prox->esq;
            } else{
                *D = prox->dado;
                if(prox->esq == NULL){
                    if(ant == NULL){
                        A->raiz = prox->dir;
                    } else{
                        if(sentido == +1){
                            ant->dir = prox->dir;
                        } else{
                            ant->esq = prox->dir;
                        }
                        free(prox);
                    }
                } else if(prox->dir == NULL){
                    if(ant == NULL){
                        A->raiz = prox->esq;
                    } else{
                        if(sentido == -1){
                            ant->dir = prox->esq;
                        } else{
                            ant->esq = prox->esq;
                        }
                        free(prox);
                    }
                } else{
                    prox->dado = maiorDosMenores(&(prox->esq));
                }
                A->quant--;
                return 1;
            }
        }
        return 0;
    }
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
    tipoPilha auxp;
    tipoPonteiroNo auxno;
    int acabou = 0;
    do{
        printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
        if(auxno->esq != NULL){
            empilha(&auxp, auxno);
            auxno = auxno->esq;
        } else{
            if(auxno->dir != NULL){
                auxno = auxno->dir;
            } else{
                acabou = (desempilha(&auxp, &auxno) == 0);
                while(!acabou && auxno->dir == NULL){
                    printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    acabou = (desempilha(&auxp, &auxno) == 0);
                }
                if(!acabou){
                    printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    auxno = auxno->dir;
                }
            }
        }
    }while(!acabou);
}

void emOrdem(tipoArvore A){
    tipoPilha auxp;
    tipoPonteiroNo auxno;
    int acabou = 0;
    auxno = A.raiz;
    criaPilha(&auxp);
    do{
        if(auxno->esq != NULL){
            empilha(&auxp, auxno);
            auxno = auxno->esq;
        } else{
            printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
            if(auxno->dir != NULL){
                auxno = auxno->dir;
            } else{
                acabou = (desempilha(&auxp, &auxno) == 0);
                while(!acabou && auxno->dir == NULL){
                    printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    acabou = (desempilha(&auxp, &auxno) == 0);
                }
                if(!acabou){
                    printf("\nNOME: %s  RG: %d  IDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    auxno = auxno->dir;
                }
            }
        }
        } while(!acabou);
}

int posOrdem(tipoArvore A){

}

