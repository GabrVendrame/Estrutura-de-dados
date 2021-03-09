#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNome 75

typedef struct tipoDataNasc{
    int dia, mes, ano;
}tipoDataNasc;

typedef struct tipoDado{
    char nome[maxNome];
    // char profissao[maxNome];
    tipoDataNasc data;
    // float salario;
    int rg;
}tipoDado;

typedef struct tipoE{
    tipoDado dado;
    struct tipoeE *prox;
}tipoE;

typedef struct tipoLista{
    tipoE *lista;
    int quant;
}tipoLista;

typedef tipoE *tipoPonteiro;

void criaLista(tipoLista *l);

int cheia(tipoLista l);

int vazia(tipoLista l);

int quantF(tipoLista l);

int insereLista(tipoLista *l, tipoDado dado);

int consultaNome(tipoLista l, tipoDado *dado);

int consultaPos(tipoLista l, int pos, tipoDado *dado);

int removeLista(tipoLista *l, tipoDado *dado);

int atualizaLista(tipoLista *l, tipoDado *dado);

