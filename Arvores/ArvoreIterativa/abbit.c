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

void preOrdem(tipoArvore A){
    tipoPilha pilha;
    tipoPonteiroNo auxno;
    int acabou = 0;
    auxno = A.raiz;
    criaPilha(&pilha);
    do{
        if(auxno != NULL){
            printf("\nNOME: %sRG: %d\nIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
            empilha(&pilha, auxno);
            auxno = auxno->esq;
        } else{
            acabou = (desempilha(&pilha, &auxno) == 0);
            while(!acabou && auxno->dir == NULL){
                acabou = (desempilha(&pilha, &auxno) == 0);
            }
            if(!acabou){
                auxno = auxno->dir;
            }
        }
    } while(!acabou);
}

void emOrdem(tipoArvore A){
    tipoPilha pilha;
    tipoPonteiroNo auxno;
    auxno = A.raiz;
    int acabou = 0;
    criaPilha(&pilha);
    do{
        if(auxno->esq != NULL){
            empilha(&pilha, auxno);
            auxno = auxno->esq;
        } else{
            printf("\nNOME: %sRG: %d\nIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
            if(auxno->dir != NULL){
                auxno = auxno->dir;
            } else{
                acabou = (desempilha(&pilha, &auxno) == 0);
                while(!acabou && auxno->dir == NULL){
                    printf("\nNOME: %sRG: %d\nIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    acabou = (desempilha(&pilha, &auxno) == 0);
                }
                if(!acabou){
                    printf("\nNOME: %sRG: %d\nIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
                    auxno = auxno->dir;
                }
            }
        }
    } while(!acabou);
}

void posOrdem(tipoArvore A){
    tipoPilha pilha, pilha2;
    tipoPonteiroNo auxno, auxno2;
    auxno = A.raiz;
    int acabou = 0;
    criaPilha(&pilha);
    criaPilha(&pilha2);
    do{
        while(auxno != NULL){
            if (auxno->dir != NULL){
                empilha(&pilha, auxno->dir);
            }
            empilha(&pilha, auxno);
            auxno = auxno->esq;
        }  
        acabou = (desempilha(&pilha, &auxno) == 0);
        pilhaTopo(pilha, &auxno2);
        if (auxno->dir && auxno2 == auxno->dir){
            acabou = (desempilha(&pilha, &auxno2) == 0);
            empilha(&pilha, auxno);
            auxno = auxno->dir;
        } else {
            printf("\nNOME: %sRG: %d\nIDADE: %d\n", auxno->dado.nome, auxno->dado.rg, auxno->dado.idade);
            if(auxno == A.raiz){
                acabou = (desempilha(&pilha, &auxno) == 0);
            }
            auxno = NULL;
        }
    } while (!acabou);
}

void mostraABB(tipoArvore A){
    tipoPilha pilha1, pilha2;
    tipoPonteiroNo auxno;
    criaPilha(&pilha1);
    criaPilha(&pilha2);
    empilha(&pilha1, A.raiz);
    do{
        desempilha(&pilha1, &auxno);
        if(auxno != NULL){
            printf("%s ", auxno->dado.nome);
            empilha(&pilha2, auxno->esq);
            empilha(&pilha2, auxno->dir);
        } else{
            printf("\nNULL");
        }
        if(pilhaVazia(pilha1)){
            while(!pilhaVazia(pilha2)){
                desempilha(&pilha2, &auxno);
                empilha(&pilha1, auxno);
            }
            printf("\n");
        }
    }while(!pilhaVazia(pilha1));
}