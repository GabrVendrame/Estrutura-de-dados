#include <stdio.h>
#include "pilhaEstatica.h"

tipoPilha pilha;

int menu(){
    int opt;
    printf("\n|       MENU      |");
    printf("\n|1 - Inserir pilha|");
    printf("\n|2 - Remove pilha |");
    printf("\n|3 - Mostra topo  |");
    printf("\n|4 - Mostra pilha |");
    printf("\n|5 - Sair         |");
    printf("\nSeleciona uma opcao: ");
    scanf("%d", &opt);
    return opt;
}

void trataopt(int opt){
    int x;
    switch(opt){
        case 1:
            if(pilhaCheia(pilha)){
                printf("\nERRO! A PILHA ESTA CHEIA!");
            }
            else{
                printf("\nDigite o dado que deseja empilhar: ");
                scanf("%d", &x);
                inserePilha(&pilha, x);
            }        
            break;
        case 2:
            if(pilhaVazia(pilha)){
                printf("\nERRO! A PILHA ESTA VAZIA!");
            }
            else{
                removePilha(&pilha, &x);
                printf("\nElemento removido!");
            }
            break;
        case 3:
            if(pilhaVazia(pilha)){
                printf("\nERRO! A PILHA ESTA VAZIA!");
            }
            else{
                printf("\nTopo = %d", pilhaTopo(pilha));
            }
            break;
        case 4:
            break;
        case 5:
            break;
    }
}

void main(void){
    int opt;
    criaPilha(&pilha);
    do{
        opt = menu();
        trataopt(opt);

    } while(opt != 5);
}