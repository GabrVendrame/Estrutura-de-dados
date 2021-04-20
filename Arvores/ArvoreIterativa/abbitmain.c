#include <stdio.h>
#include <stdlib.h>
#include "abbit.h"

tipoArvore abb;

int menuOpt(){
    int opt;
    printf("\nMenu");
    printf("\n1 - INSERIR ABB");
    printf("\n2 - REMOVER ABB");
    printf("\n3 - CONSULTAR ABB");
    printf("\n4 - QUANTIDADE DE ELEMENTOS");
    printf("\n5 - IMPRIMIR PRE-ORDEM");
    printf("\n6 - IMPRIMIR EM-ORDEM");
    printf("\n7 - IMPRIMIR POS-ORDEM");
    printf("\n8 - SAIR");
    printf("\nESCOLHA A OPCAO: ");
    scanf("%d", &opt);
    return opt;
}

void trataOpt(int opt){
    tipoDado dado;
    int pos, quant;
    switch(opt){
        case 1:
            if(cheia(abb)){
                printf("\nERRO! ARVORE CHEIA!");
            } else{
                printf("\nDigite o dado a ser inserido:\n");
                printf("\nNOME: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                printf("\nRG: ");
                scanf("%d", &dado.rg);
                printf("\nIDADE: ");
                scanf("%d", &dado.idade);
                if(insereABB(&abb, dado)){
                    printf("\nREGISTRO INSERIDO!");
                } else{
                    printf("\nERRO! REGISTRO NAO INSERIDO!");
                }

            }
            break;
        case 2:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                printf("\nDigite o nome do registro a ser removido: ");
                printf("\nNOME: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                if(removeABB(&abb, &dado)){
                    printf("\nREGISTRO REMOVIDO!");
                } else{
                    printf("\nERRO! REGISTRO NAO EXISTE!");
                }
            }
            break;
        case 3:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                printf("\nDigite o nome a ser consultado: ");
                printf("\nNOME: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                if(consulta(abb, &dado)){
                    printf("\nREGISTRO CONSULTADO!");
                    printf("\nNOME: %s\nRG: %d\nIDADE: %d", dado.nome, dado.rg, dado.idade);
                } else{
                    printf("\nERRO! REGISTRO NAO EXISTE!");
                }
            }
            break;
        case 4:
            printf("\nELEMENTOS NA ARVORE: %d", quantA(abb));
            break;
        case 5:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                preOrdem(abb);
            }
            break;
        case 6:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                emOrdem(abb);
            }
            break;
        case 7:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                posOrdem(abb);
            }
            break;
    }
}

void main(void){
    int opt;
    criaArvore(&abb);
    do{
        opt = menuOpt();
        trataOpt(opt);
    }while(opt != 8);
}