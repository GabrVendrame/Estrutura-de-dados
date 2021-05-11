#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

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
        case 11:
            int *aux_select, *aux_insert, *aux_bubble;
            printf("\nEXECUCAO CONJUNTA!");
            printf("\nDIGITE O TAMANHO DO VETOR: ");
            scanf("%d", &tam);
            geraVetor(vet, tam);
            printf("\nSELECTION SORT");
            aux_select = vet;
            printVet(vet, tam);
            rd = selectionSort(aux_select, tam);
            printVet(aux_select, tam);
            printf("\nINSERTION SORT");
            aux_insert = vet;
            printVet(vet, tam);
            rd = insertionSort(aux_insert, tam);
            printVet(aux_insert, tam);            
            printf("\nBUBBLE SORT");
            aux_bubble = vet;
            printVet(vet, tam);
            rd = bubbleSort(aux_bubble, tam);
            printVet(aux_bubble, tam);
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