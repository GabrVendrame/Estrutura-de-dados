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

int criaABB(tipoArvore *A);
int vazia(tipoArvore A);
int cheia(tipoArvore A);
int quantA(tipoArvore A);
int insere(tipoArvore *A, tipoDado D);
int remove(tipoArvore *A, tipoDado *D);
int consulta(tipoArvore A, tipoDado *D);
void preOrdem(tipoArvore A);
void emOrdem(tipoArvore A);
void posOrdem(tipoArvore A);