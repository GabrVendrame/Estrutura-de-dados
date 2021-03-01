#include <stdio.h>
#include <stdlib.h>

struct tipoElem
{
    int dado;
    struct tipoElem *prox;
};

typedef struct tipoElem tipoElem;

typedef tipoElem *tipoFila;

void criaFila(tipoFila *f)
{
    *f = NULL;
}

int filaCheia(tipoFila f)
{
    return (0);
}

int filaVazia(tipoFila f)
{
    return (f==NULL);
}

int primeiroFila(tipoFila f, int *dado)
{   tipoElem *pri;

    if (filaVazia(f))
    {
        return (0);
    }
    else
    {
        pri=f;

        while (pri->prox!=NULL)
        {
            pri=pri->prox;
        }

        *dado=pri->dado;

        return (1);

    }
}

int enfileira(tipoFila *f, int dado)
{   tipoElem *aux;

    aux=malloc(sizeof(tipoElem));
    aux->dado=dado;
    aux->prox=*f;
    *f=aux;
    return (1);
}

int desenfileira(tipoFila *f, int *dado)
{   tipoElem *pri, *seg;

    if (filaVazia(*f))
    {
        return (0);
    }
    else
    {
        pri=*f;
        seg=NULL;

        while (pri->prox!=NULL)
        {   seg=pri;
            pri=pri->prox;
        }

        *dado=pri->dado;

        if (seg==NULL)
        {
            *f=NULL;
        }
        else seg->prox=NULL;

        free(pri);

        return (1);

    }
}


