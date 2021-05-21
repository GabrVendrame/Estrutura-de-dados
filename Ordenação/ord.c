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
    int i;
    srand(time(NULL));
    for(i = 0; i < tam; i++){
        V[i] = rand() % 100;
    }
}

void printVet(tipoVet V, int tam){
    int i;
    if(tam <= 1000){
        for(i = 0; i < tam; i++){
            printf("%d ", V[i]);
        }
        printf("\n");
    } else{
        printf("\nTAMANHO DO VETOR MUITO GRANDE! IMPRESSAO OMITIDA!\n");
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

tipoD shellSort(tipoVet V, int tam){
    int ult_ord, ant, aux, desloc;
    long int tempo_inicial, tempo_final, tempo_total;
    double nCmp = 0, nOps = 0;
    tipoD td;
    tempo_inicial = (long int)time(NULL);
    desloc = tam / 2;
    nCmp++;
    nOps++;
    while(desloc > 0){
        nCmp++;
        nOps++;
        for(ult_ord = 0; ult_ord < tam - desloc; ult_ord++){
            aux = V[ult_ord + desloc];
            ant = ult_ord;
            nCmp+= 2;
            while(ant >= 0 && aux < V[ant]){
                V[ant + desloc] = V[ant];
                ant = ant - desloc;
                nCmp+= 2;
                nOps+= 4;
            }
            V[ant + desloc] = aux;
            nCmp++;
            nOps+= 7;
        }
        desloc = desloc / 2;
        nCmp++;
        nOps+=2;
    }
    tempo_final = (long int)time(NULL);
    tempo_total = tempo_final - tempo_inicial;
    td.tempo = tempo_total;
    td.nCmp = nCmp;
    td.nOps = nOps;
    return td;  
}

tipoD merge(tipoVet V, int inicio, int meio, int fim){
    tipoVet part1, part2;
    int tam1 = 0, tam2 = 0, i, j, k, maior;
    for(i = inicio; i < meio + 1; i++){
        part1[tam1] = V[i];
        tam1++;
    }
    for(i = meio + 1; i < fim + 1; i++){
        part2[tam2] = V[i];
        tam2++;
    }
    maior = abs(part1[tam1-1] + part2[tam2-1]) + 1;
    part1[tam1] = maior;
    part2[tam2] = maior;
    i = 0;
    j = 0;
    for(k = inicio; k < fim + 1; k++){
        if(part1[i] < part2[j]){
            V[k] = part1[i];
            i++;
        } else{
            V[k] = part2[j];
            j++;
        }
    } 
}

tipoD _mergeSort(tipoVet V, int inicio, int fim){
    int meio;
    if((fim - inicio) > 0){
        meio = (inicio + fim) / 2;
        _mergeSort(V, inicio, meio);
        _mergeSort(V, meio + 1, fim);
        merge(V, inicio, meio, fim);
    }
}

tipoD mergeSort(tipoVet V, int tam){
    _mergeSort(V, 0, tam-1);
}

int indiceFilhoEsq(int indice){
    return (2 * indice + 1);
}

int indiceFilhoDir(int indice){
    return (2 * indice + 2);
}

tipoD arrumaMaxHeap(tipoVet V, int tam, int indice){
    int maior, posmaior, aux;
    maior = V[indice];
    posmaior = indice;
    if(indiceFilhoEsq(indice) < tam){
        if(V[indiceFilhoEsq(indice)] > maior){
            maior = V[indiceFilhoEsq(indice)];
            posmaior = indiceFilhoEsq(indice);
        }
        if(indiceFilhoDir(indice) < tam){
    
            if(V[indiceFilhoDir(indice)] > maior){
        
                maior = V[indiceFilhoDir(indice)];
                posmaior = indiceFilhoDir(indice);
            }
        }
    }
    if(posmaior != indice){
        aux = V[indice];
        V[indice] = maior;
        V[posmaior] = aux;
        arrumaMaxHeap(V, tam, posmaior);
    }
}

tipoD maxHeap(tipoVet V, int tam){
    int i;
    for(i = (tam - 2) / 2; i > -1; i--){
        arrumaMaxHeap(V, tam, i);
    }
}

tipoD heapSort(tipoVet V, int tam){
    int i, aux;
    maxHeap(V, tam);
    for(i = tam - 1; i > 0; i--){
        aux = V[i];
        V[i] = V[0];
        V[0] = aux;
        arrumaMaxHeap(V, i, 0);
    }
}

int particiona(tipoVet V, int inicio, int fim){
    int posDiv, i, meio, div, aux;
    meio = (inicio + fim) / 2;
    aux = V[fim];
    V[fim] = V[meio];
    V[meio] = aux;
    div = V[fim];
    posDiv = inicio;
    for(i = inicio; i < fim; i++){
        if(V[i] < div){
            aux = V[i];
            V[i] = V[posDiv];
            V[posDiv] = aux;
            posDiv++;
        }
    }
    V[fim] = V[posDiv];
    V[posDiv] = div;
    return posDiv;
}

tipoD _quicksort(tipoVet V, int inicio, int fim){
    int posDiv;
    if(fim > inicio){
        posDiv = particiona(V, inicio, fim);
        _quicksort(V, inicio, posDiv - 1);
        _quicksort(V, posDiv + 1, fim);
    }
}

tipoD quickSort(tipoVet V, int tam){
    _quicksort(V, 0, tam-1);
}

tipoD transfereVetor(tipoVet V, tipoVet R, int C[], int tam){
    int i;
    for(i = tam - 1; i >= 0; i--){
        R[C[V[i]] - 1] = V[i];
        C[V[i]]--;
    }
    for(i = 0; i < tam; i++){
        V[i] = R[i];
    }
}

tipoD registraContagem(tipoVet V, int C[], int tam, int fim){
    int i;
    for(i = 0; i <= fim; i++){
        C[i] = 0;
    }
    for(i = 0; i < tam; i++){
        C[V[i]]++;
    }
    for(i = 1; i <= fim; i++){
        C[i] += C[i-1];
    }
}

tipoD _countingSort(tipoVet V, int tam, int inicio, int fim){
    tipoVet R;
    int C[fim];
    registraContagem(V, C, tam, fim);
    transfereVetor(V, R, C, tam);
}

tipoD countingSort(tipoVet V, int tam){
    int i, maior;
    maior = V[0];
    for(i = 1; i < tam; i++){
        if(V[i] > maior){   
            maior = V[i];
        }
    }
    _countingSort(V, tam, 0, maior);
}

int pegaDigito(int n, int posdigito){
    int i, digito = 0;
    for(i = 0; i <= posdigito; i++){
        digito = n % 10;
        n = n / 10;
    }
    return digito;
}

int calculaQuantDigito(int numero){
    int quant = 0;
    do{
        numero = numero / 10;
        quant++;
    } while(numero != 0);
    return quant;
}

tipoD countingSort2(tipoVet V, int tam, int posdigito){
    int i, maior, C[10], n;
    maior = V[0];
    for(i = 1; i < tam; i++){
        if(V[i] > maior){
            maior = V[i];
        }
    }
    while(pegaDigito(n, posdigito)){
        for(i = 0; i < 10; i++){
            C[i] = 0;
        }
        for(i = 0; i < tam; i++){
            C[V[i]]++;
        }
        for(i = 1; i <= fim; i++){
            C[i] += C[i-1];
        }
        for(i = tam - 1; i >= 0; i--){
            R[C[V[i]] - 1] = V[i];
            C[V[i]]--;
        }
        for(i = 0; i < tam; i++){
            V[i] = R[i];
        }
    }
}

tipoD radixSort(tipoVet V, int tam){
    int maxNum, digito, quantdigito, posdigito;
    tipoVet C, R;
    quantdigito = calculaQuantDigito(maxNum);
    for(posdigito = 0; posdigito < quantdigito; posdigito++){
        countingSort2(V, tam, posdigito);
    }
}