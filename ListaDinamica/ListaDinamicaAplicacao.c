#include <stdio.h>
#include <stdlib.h>
#include "ListaDinamica.h"

tipoLista lista;

int menuOpt(){
    int opt;
    printf("\n|           MENU            |\n");
    printf("|1 - INSERIR                |\n");
    printf("|2 - REMOVER                |\n");
    printf("|3 - CONSULTA POR NOME      |\n");
    printf("|4 - CONSULTA POR POSICAO   |\n");
    printf("|5 - QUANTIDADE DE ELEMENTOS|\n");
    printf("|6 - IMPRIMIR LISTA         |\n");
    printf("|7 - ATUALIZAR LISTA        |\n");
    printf("|8 - SAIR                   |\n");
    printf("ESCOLHA UMA OPCAO: ");
    scanf("%d", &opt);
    return opt;
}

void trataOpt(int opt){
    tipoDado dado;
    int pos;
    switch(opt){
        case 1:
            if(cheia(lista)){
                printf("\nLISTA CHEIA!\n");

            } else{
                printf("\nINSERCAO\n");
                printf("Nome: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                printf("Dia do nascimento: ");
                scanf("%d", &(dado.data.dia));
                printf("Mes do nascimento: ");
                scanf("%d", &(dado.data.mes));
                printf("Ano do nascimento: ");
                scanf("%d", &(dado.data.ano));
                printf("RG: ");
                scanf("%d", &(dado.rg));
                printf("Profissao: ");
                fflush(stdin);
                fgets(dado.profissao, maxNome, stdin);
                fflush(stdin);
                printf("Salario: ");
                scanf("%f", &(dado.salario));
                insereLista(&lista, dado);
                printf("REGISTRO INSERIDO!\n");
            }
            break;
        case 2:
            if(vazia(lista)){
                printf("\nLISTA VAZIA!\n");
            } else{
                printf("\nREMOCAO\nDigite o nome do registro a ser removido: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                if(removeLista(&lista, &dado)){
                    printf("Nome: %s", dado.nome);
                    printf("Data do nascimento: %d/%d/%d\n", dado.data.dia, dado.data.mes, dado.data.ano);
                    printf("RG: %d\n", dado.rg);
                    printf("Profissao: %s", dado.profissao);
                    printf("Salario: R$%.2f\n", dado.salario);
                    printf("REGISTRO REMOVIDO!\n");
                } else{
                    printf("\nERRO! O REGISTRO NAO EXISTE!\n");
                }
            }
            break;
        case 3:
            if(vazia(lista)){
                printf("\nLISTA VAZIA!\n");
            } else{
                printf("\nDigite o nome a ser consultado: ");
                fflush(stdin);
                fgets(dado.nome, maxNome, stdin);
                fflush(stdin);
                if(consultaNome(lista, &dado)){
                    printf("\nREGISTRO CONSULTADO!\n");
                    printf("Nome: %s", dado.nome);
                    printf("Data do nascimento: %d/%d/%d\n", dado.data.dia, dado.data.mes, dado.data.ano);
                    printf("RG: %d\n", dado.rg);
                    printf("Profissao: %s", dado.profissao);
                    printf("Salario: R$%.2f\n", dado.salario);
                } else{
                    printf("\nERRO! REGISTRO NAO EXISTE!\n");
                }
            }
            break;
        case 4:
            if(vazia(lista)){
                printf("\nLISTA VAZIA!\n");
            } else{
                printf("Qual a posicao do item que deseja consultar: ");
                scanf("%d", &pos);
                if(consultaPos(lista, pos, &dado)){
                    printf("\nREGISTRO CONSULTADO!\n");
                    printf("Posicao: %d\n", pos);
                    printf("Nome: %s", dado.nome);
                    printf("Data do nascimento: %d/%d/%d\n", dado.data.dia, dado.data.mes, dado.data.ano);
                    printf("RG: %d\n", dado.rg);
                    printf("Profissao: \n", dado.profissao);
                    printf("Salario: R$%.2f\n", dado.salario);
                } else{
                    printf("\nERRO! ESSA POSICAO NAO EXISTE!\n");
                }
            }
            break;
        case 5:
            printf("\nExiste %d elemento(s) na lista\n", quantF(lista));
            break;
        case 6:
            if(vazia(lista)){
                printf("\nLISTA VAZIA!\n");
            } else{
                printf("\nELEMENTOS DA LISTA\n");
                for(pos = 1; pos <= quantF(lista); pos++){
                    consultaPos(lista, pos, &dado);
                    printf("\nRegistro numero %d\n", pos);
                    printf("Nome: %s", dado.nome);
                    printf("Data do nascimento(dia/mes/ano): %d/%d/%d\n", dado.data.dia, dado.data.mes, dado.data.ano);
                    printf("RG: %d\n", dado.rg);
                    printf("Profissao: %s", dado.profissao);
                    printf("Salario: R$%.2f\n", dado.salario);
                }
            }
            break;
        case 7:
            if(vazia(lista)){
                printf("\nLISTA VAZIA!\n");
            } else{
                printf("\nATUALIZAR LISTA\n");
                printf("Dia do nascimento: ");
                scanf("%d", &(dado.data.dia));
                printf("Mes do nascimento: ");
                scanf("%d", &(dado.data.mes));
                printf("Ano do nascimento: ");
                scanf("%d", &(dado.data.ano));
                printf("RG: ");
                scanf("%d", &(dado.rg));
                printf("Profissao: ");
                fflush(stdin);
                fgets(dado.profissao, maxNome, stdin);
                fflush(stdin);
                printf("Salario: ");
                scanf("%f", &(dado.salario));
                atualizaLista(&lista, dado);
                printf("REGISTRO ATUALIZADO!\n");    
            }
            break;
    }
}

void main(void){
    int opt;
    criaLista(&lista);
    do{
        opt = menuOpt();
        trataOpt(opt);
    } while(opt != 8);
}