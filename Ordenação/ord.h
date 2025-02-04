#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamVet 100000
#define maxBuckets 10

typedef int tipoVet[tamVet];

typedef struct tipoBucket{
    tipoVet local;
    int pos, tam;
} tipoBucket;

typedef tipoVet Buckets[maxBuckets];

typedef struct tipoD{
    long int tempo;
    double nCmp, nOps;
} tipoD;

void geraVetor(tipoVet V, int tam);
void printVet(tipoVet V, int tam);
tipoD selectionSort(tipoVet V, int tam);
tipoD insertionSort(tipoVet V, int tam);
tipoD bubbleSort(tipoVet V, int tam);
tipoD shellSort(tipoVet V, int tam);
tipoD mergeSort(tipoVet V, int tam);
tipoD heapSort(tipoVet V, int tam);
tipoD quickSort(tipoVet V, int tam);
tipoD countingSort(tipoVet V, int tam);
tipoD radixSort(tipoVet V, int tam);
tipoD bucketSort(tipoVet V, int tam);