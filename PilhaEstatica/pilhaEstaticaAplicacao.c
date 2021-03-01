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
            listaPilha(pilha);
            //pilha listada na ordem de inserção, ou seja, o dado inserido por ultimo está no topo;
            break;
        case 5:
            break;
    }
}

void listaPilha(tipoPilha p){
    tipoPilha pilhaux;
    int dado;
    if(pilhaVazia(p)){
        printf("Pilha vazia!\n");
    } else{
        criaPilha(&pilhaux);
        while(!pilhaVazia(p)){
            removePilha(&p, &dado);
            printf("%d\n", dado);
            inserePilha(&pilhaux, dado);
        }
        while(!pilhaVazia(pilhaux)){
            removePilha(&pilhaux, &dado);
            inserePilha(&p, dado);
        }
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