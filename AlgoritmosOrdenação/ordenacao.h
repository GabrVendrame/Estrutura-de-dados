#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamVet 100000

typedef int tipoVet[tamVet];

typedef struct tipoD{
    long int tempo;
    double nCmp, nOps;
} tipoD;

void geraVetor(tipoVet V, int tam);
void printVet(tipoVet V, int tam);
tipoD selectionSort(tipoVet V, int tam);
tipoD insertionSort(tipoVet V, int tam);
tipoD bubbleSort(tipoVet, int tam);
