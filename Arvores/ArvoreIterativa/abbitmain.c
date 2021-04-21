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
    printf("\n4 - CONSULTAR PAI");
    printf("\n5 - CONSULTAR ASC");
    printf("\n6 - QUANTIDADE DE ELEMENTOS");
    printf("\n7 - IMPRIMIR PRE-ORDEM");
    printf("\n8 - IMPRIMIR EM-ORDEM");
    printf("\n9 - IMPRIMIR POS-ORDEM");
    printf("\n10 - MOSTRAR ABB");
    printf("\n11 - SAIR");
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
            break;
        case 5:
            break;
        case 6:
            printf("\nELEMENTOS NA ARVORE: %d", quantA(abb));
            break;
        case 7:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                preOrdem(abb);
            }
            break;
        case 8:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                emOrdem(abb);
            }
            break;
        case 9:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                posOrdem(abb);
            }
            break;
        case 10:
            if(vazia(abb)){
                printf("\nERRO! ARVORE VAZIA!");
            } else{
                mostraABB(abb);
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
    }while(opt != 11);
}