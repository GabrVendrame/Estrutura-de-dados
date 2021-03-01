#include <stdio.h>
#include <stdlib.h>
#include "filaDinamica.h"

tipoFila fila;

int menuOpcao()
{   int op;

    printf("\n|        Menu        |");
    printf("\n|1 - Enfileirar      |");
    printf("\n|2 - Desemfileirar   |");
    printf("\n|3 - Mostrar primeiro|");
    printf("\n|4 - Mostrar fila    |");
    printf("\n|5 - Sair            |\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d",&op);
    return op;
}

void listaFila(tipoFila fila){
    tipoFila aux;
    int dado;
    if(filaVazia(fila)){
        printf("Fila vazia!");
    } else{
        criaFila(&aux);
        while(!filaVazia(fila)){
            desenfileira(&fila, &dado);
            printf("%d <- ", dado);
            enfileira(&aux, dado);
            
        }
        while(!filaVazia(aux)){
            desenfileira(&aux, &dado);
            enfileira(&fila, dado);
        }
    }
}

void trataOpcao(int op)
{   int dado;

    switch (op){
        case 1: 
            if (filaCheia(fila))
            printf("\nFila Cheia! Dado nao inserido!\n");
            else{
                printf("\nDigite o dado a ser enfileirado : ");
                scanf("%d",&dado);
                enfileira(&fila, dado);
            }
            break;
        case 2: 
            if (filaVazia(fila))
                printf("\nFila Vazia! Dado nao removido!\n");
            else{
                desenfileira(&fila,&dado);
                printf("\nDado Desenfileirado: %d",dado);
            }
            break;
        case 3: 
            if (filaVazia(fila))
            printf("\nFila Vazia! O Primeiro nao pode ser mostrado!\n");
            else{
                primeiroFila(fila, &dado);
                printf("\nPrimeiro: %d",dado);
            }
            break;
        case 4:
            listaFila(fila);
            break;
        case 5:
            break;
    }
}

void main(void){
    int opcao;
    criaFila(&fila);
    do{
        opcao=menuOpcao();
        trataOpcao(opcao);
    } while (opcao!=5);
}

