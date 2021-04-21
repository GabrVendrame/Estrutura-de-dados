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

typedef struct tipoArvore{
    tipoPonteiroNo raiz;
    int quant;
} tipoArvore;

int criaArvore(tipoArvore *A);
int vazia(tipoArvore A);
int cheia(tipoArvore A);
int quantA(tipoArvore A);
int insereABB(tipoArvore *A, tipoDado D);
int removeABB(tipoArvore *A, tipoDado *D);
int consulta(tipoArvore A, tipoDado *D);
int consultaPai(tipoArvore A, tipoDado *D);
int consultaAsc(tipoArvore A, tipoDado *D);
void preOrdem(tipoArvore A);
void emOrdem(tipoArvore A);
void posOrdem(tipoArvore A);
void mostraABB(tipoArvore A);