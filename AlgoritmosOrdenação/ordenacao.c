#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tamVet 100000

typedef int tipoVet[tamVet];

typedef struct tipoD{
    long int tempo;
    double nCmp, nOps;
} tipoD;

void geraVetor(tipoVet V, int tam){
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        V[i] = rand() % 100;
    }
}

void printVet(tipoVet V, int tam){
    if(tam <= 1000){
        for(int i = 0; i < tam; i++){
            printf("%d ", V[i]);
        }
        printf("\n");
    } else{
        printf("\nTAMANHO DO VETOR ALTO! IMPRESSAO OMITIDA!\n");
    }
    printf("\n");
}

tipoD selectionSort(tipoVet V, int tam){
    int pos_ord, i, menor, pos_menor, aux;
    long int tempo_inicial, tempo_final, tempo_total;
    double nCmp = 0, nOps = 0;
    tipoD td;
    tempo_inicial = (long int)time(NULL);
    nCmp++;
    nOps++;
    for(pos_ord = 0; pos_ord < tam - 1; pos_ord++){
        menor = V[pos_ord];
        pos_menor = pos_ord;
        nCmp++;
        for(i = pos_ord + 1; i < tam; i++){
            if(V[i] < menor){
                menor = V[i];
                pos_menor = i;
                nOps+= 2;
            }
            nCmp+= 2;
            nOps++;
        }
        aux = V[pos_ord];
        V[pos_ord] = menor;
        V[pos_menor] = aux;
        nCmp+= 2;
        nOps+= 8;
    }
    tempo_final = (long int)time(NULL);
    tempo_total = tempo_final - tempo_inicial;
    td.tempo = tempo_total;
    td.nCmp = nCmp;
    td.nOps = nOps;
    return td;
}

tipoD insertionSort(tipoVet V, int tam){
    int ult_ord, ant, aux;
    long int tempo_inicial, tempo_final, tempo_total;
    double nCmp = 0, nOps = 0;
    tipoD td;
    tempo_inicial = (long int)time(NULL);
    nCmp++;
    nOps++;
    for(ult_ord = 0; ult_ord < tam - 1; ult_ord++){
        aux = V[ult_ord +1];
        ant = ult_ord;
        nCmp+= 2;
        while(ant >= 0 && aux < V[ant]){
            V[ant + 1] = V[ant];
            ant--;
            nCmp+= 2;
            nOps+= 4;
        }
        V[ant + 1] = aux;
        nCmp++;
        nOps+= 8;
    }
    tempo_final = (long int)time(NULL);
    tempo_total = tempo_final - tempo_inicial;
    td.tempo = tempo_total;
    td.nCmp = nCmp;
    td.nOps = nOps;
    return td;
}

tipoD bubbleSort(tipoVet V, int tam){
    int pos_ord, prox, aux;
    long int tempo_inicial, tempo_final, tempo_total;
    double nCmp = 0, nOps = 0;
    tipoD td;
    tempo_inicial = (long int)time(NULL);
    nCmp++;
    for(pos_ord = tam-1; pos_ord > 0; pos_ord--){
        nCmp++;
        for(prox = 0; prox < pos_ord; prox++){
            if(V[prox] > V[prox + 1]){
                aux = V[prox];
                V[prox] = V[prox + 1];
                V[prox + 1] = aux;
                nOps+= 7;
            }
            nCmp+= 2;
        }
        nCmp++;
        nOps+= 2;
    }
    tempo_final = (long int)time(NULL);
    tempo_total = tempo_final - tempo_inicial;
    td.tempo = tempo_total;
    td.nCmp = nCmp;
    td.nOps = nOps;
    return td;
}