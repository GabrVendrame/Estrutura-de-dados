#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ord.h"

tipoVet vet;

int menuOpcao(){
    int opt;
    printf("\n|        Menu        |");
    printf("\n|1 - SELECTION SORT  |");
    printf("\n|2 - INSERTION SORT  |");
    printf("\n|3 - BUBBLE SORT     |");
    printf("\n|4 - SHELL SORT      |");
    printf("\n|5 - MERGE SORT      |");
    printf("\n|6 - HEAP SORT       |");
    printf("\n|7 - QUICK SORT      |");
    printf("\n|8 - COUNTING SORT   |");
    printf("\n|9 - BUCKET SORT     |");
    printf("\n|10 - RADIX SORT     |");
    printf("\n|11 - TODOS JUNTOS   |");
    printf("\n|12 - SAIR           |\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&opt);
    return opt;
}

void mostraTodos(){
    int tam;
    printf("\nEXECUCAO CONJUNTA!");
    printf("\nDIGITE O TAMANHO DO VETOR: ");
    scanf("%d", &tam);
    int vet[tam], vaux[tam];
    geraVetor(vet, tam);
    memcpy(vaux, vet, sizeof(vet));
    printf("\nSELECTION SORT\n");
    printVet(vet, tam);
    selectionSort(vaux, tam);
    printVet(vaux, tam);
    memcpy(vaux, vet, sizeof(vet));
    printf("\nINSERTION SORT\n");
    printVet(vet, tam);
    insertionSort(vaux, tam);
    printVet(vaux, tam);
    memcpy(vaux, vet, sizeof(vet));
    printf("\nBUBBLE SORT\n");
    printVet(vet, tam);
    bubbleSort(vaux, tam);
    printVet(vaux, tam);
}

void trataOpcao(int opt){
    int tam;
    tipoD rd;
    switch(opt){
        case 0:
        case 1:
            printf("\nORDENACAO SELECTION SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = selectionSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 2:
            printf("\nORDENACAO INSERTION SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = insertionSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 3:
            printf("\nORDENACAO BUBBLE SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = bubbleSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 4:
            printf("\nORDENACAO SHELL SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = shellSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 5:
            printf("\nORDENACAO MERGE SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = mergeSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 6:
            printf("\nORDENACAO HEAP SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = heapSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 7:
            printf("\nORDENACAO QUICK SORT");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nVETOR PRE-ORDENACAO\n");
            printVet(vet, tam);
            rd = quickSort(vet, tam);
            printf("\nVETOR POS-ORDENACAO\n");
            printVet(vet, tam);
            printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 8:
            // printf("\nORDENACAO COUNTING SORT");
            // printf("\nDIGITE O TAMANHO DO VETOR: ");
            // scanf("%d", &tam);
            // geraVetor(vet, tam);
            // printf("\nVETOR PRE-ORDENACAO\n");
            // printVet(vet, tam);
            // rd = countingSort(vet, tam);
            // printf("\nVETOR POS-ORDENACAO\n");
            // printVet(vet, tam);
            // printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 9:
            // printf("\nORDENACAO BUCKET SORT");
            // printf("\nDIGITE O TAMANHO DO VETOR: ");
            // scanf("%d", &tam);
            // geraVetor(vet, tam);
            // printf("\nVETOR PRE-ORDENACAO\n");
            // printVet(vet, tam);
            // rd = bucketSort(vet, tam);
            // printf("\nVETOR POS-ORDENACAO\n");
            // printVet(vet, tam);
            // printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 10:
            // printf("\nORDENACAO RADIX SORT");
            // printf("\nDIGITE O TAMANHO DO VETOR: ");
            // scanf("%d", &tam);
            // geraVetor(vet, tam);
            // printf("\nVETOR PRE-ORDENACAO\n");
            // printVet(vet, tam);
            // rd = radixSort(vet, tam);
            // printf("\nVETOR POS-ORDENACAO\n");
            // printVet(vet, tam);
            // printf("\nTEMPO= %ld segundos\nCOMPARACOES= %.2lf\nOPERACOES= %.2lf\nCOMPARACOES + OPERACOES= %.2lf\n", rd.tempo, rd.nCmp, rd.nOps, rd.nCmp + rd.nOps);
            break;
        case 11:
            mostraTodos();
            break;
    }
}

void main(void){
    int opcao;
    do{
        opcao=menuOpcao();
        trataOpcao(opcao);
    } while (opcao!=12);
}