#include <stdio.h>
#include <stdlib.h>
#include "filaEstatica.h"

tipoFila fila;

int menu(){
    int opt;
    printf("\n|       MENU        |");
    printf("\n|1 - Inserir fila   |");
    printf("\n|2 - Remove fila    |");
    printf("\n|3 - Mostra primeiro|");
    printf("\n|4 - Lista fila     |");
    printf("\n|5 - Sair           |");
    printf("\nSeleciona uma opcao: ");
    scanf("%d", &opt);
    return opt;
}

void listaFila(tipoFila f){
    tipoFila filaaux;
    int dado;
    if(filaVazia(f)){
        printf("\nERRO! FILA VAZIA!\n");
    } else{
        criaFila(&filaaux);
        while(!filaVazia(f)){
            desenfileira(&f, &dado);
            enfileira(&filaaux, dado);
        }
        printf("\n");
        while(!filaVazia(filaaux)){
            desenfileira(&filaaux, &dado);
            printf("%d <- ", dado);
            enfileira(&f, dado);
        }
        printf("\n");
    }

}

void trataopt(int opt){
    int dado;
    switch(opt){
        case 1:
            if(filaCheia(fila)){
                printf("\nERRO! FILA CHEIA!\n");
            } else{
                printf("Digite o dado a ser enfileirado: ");
                scanf("%d", &dado);
                enfileira(&fila, dado);
                printf("\nDADO %d ENFILEIRADO!\n", dado);
            }
            break;
        case 2:
            if(filaVazia(fila)){
                printf("\nERRO! FILA VAZIA!\n");
            } else{
                desenfileira(&fila, &dado);
                printf("\nDADO %d DESENFILEIRADO!\n", dado);
            }
            break;
        case 3:
            if(filaVazia(fila)){
                printf("\nERRO! FILA VAZIA!\n");
            } else{
                primeiroF(fila, &dado);
                printf("\nPrimeiro: %d\n", dado);
            }
            break;
        case 4:
            listaFila(fila);
            break;
    }
}

void main(void){
    int opt;
    criaFila(&fila);
    do{
        opt = menu();
        trataopt(opt);

    } while(opt != 5);
}
