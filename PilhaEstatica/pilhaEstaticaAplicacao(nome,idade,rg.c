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

void listaPilha(tipoPilha p){
    tipoPilha pilhaux;
    tipoDado dado;
    if(pilhaVazia(p)){
        printf("Pilha vazia!\n");
    } else{
        criaPilha(&pilhaux);
        while(!pilhaVazia(p)){
            removePilha(&p, &dado);
            printf("\nNome: %s\n", dado.nome);
            printf("\nIdade: %d\n", dado.idade);
            printf("\nRG: %d\n", dado.rg);
            inserePilha(&pilhaux, dado);
        }
        while(!pilhaVazia(pilhaux)){
            removePilha(&pilhaux, &dado);
            inserePilha(&p, dado);
        }
    }

}

void trataopt(int opt){
    tipoDado dado, topo;
    switch(opt){
        case 1:
            if(pilhaCheia(pilha)){
                printf("\nERRO! A PILHA ESTA CHEIA!");
            }
            else{
                printf("\nNome: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                printf("Idade: \n");
                scanf("%d", &(dado.idade));
                printf("RG: \n");
                scanf("%d", &(dado.rg));
                inserePilha(&pilha, dado);
            }        
            break;
        case 2:
            if(pilhaVazia(pilha)){
                printf("\nERRO! A PILHA ESTA VAZIA!");
            }
            else{
                removePilha(&pilha, &dado);
                printf("\nElemento removido!");
            }
            break;
        case 3:
            if(pilhaVazia(pilha)){
                printf("\nERRO! A PILHA ESTA VAZIA!");
            }
            else{
                topo = pilhaTopo(pilha);
                printf("\nNome: %s", topo.nome);
                printf("\nIdade: %d\n", topo.idade);
                printf("\nRG: %d\n", topo.rg);
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


void main(void){
    int opt;
    criaPilha(&pilha);
    do{
        opt = menu();
        trataopt(opt);

    } while(opt != 5);
}