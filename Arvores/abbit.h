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
int insere(tipoArvore *A, tipoDado D);
int remove(tipoArvore *A, tipoDado *D);
int consulta(tipoArvore A, tipoDado *D);
int preOrdem(tipoArvore A);
int emOrdem(tipoArvore A);
int posOrdem(tipoArvore A);
