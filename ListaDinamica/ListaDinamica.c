// ALUNO: Gabriel de Souza Vendrame
// RA: 112681
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxNome 75

typedef struct tipoDataNasc{
    int dia, mes, ano;
}tipoDataNasc;

typedef struct tipoDado{
    char nome[maxNome];
    char profissao[maxNome];
    tipoDataNasc data; 
    float salario;
    int rg;
}tipoDado;

typedef struct tipoE{
    tipoDado dado;
    struct tipoeE *prox;
}tipoE;

typedef tipoE *tipoPonteiro;

typedef struct tipoLista{
    tipoPonteiro lista;
    int quant;
}tipoLista;

void criaLista(tipoLista *l){
    l->quant = 0;
    l->lista = NULL;
}

int cheia(tipoLista l){
    return 0;
}

int vazia(tipoLista l){
    return l.lista == NULL;
}

int quantF(tipoLista l){
    return l.quant;
}

int buscaLista(tipoLista l, char nome[], tipoPonteiro *pos_ant){
    tipoPonteiro pos_prox;
    int tem_mais;
    *pos_ant = NULL;
    if(vazia(l)){
        return 0;
    } else{
        pos_prox = l.lista;
        tem_mais = (pos_prox->prox != NULL);
        while(strcmp(pos_prox->dado.nome, nome) == -1 && tem_mais){
            *pos_ant = pos_prox;
            pos_prox = pos_prox->prox;
            tem_mais = pos_prox->prox != NULL;
        }
        if(strcmp(pos_prox->dado.nome, nome) == 0){
            return 1;
        }
        else if(strcmp(pos_prox->dado.nome, nome) ==+ 1){
            return 0;
        }
        else{
            *pos_ant = pos_prox;
            return 0;
        }
    }
}

int insereLista(tipoLista *l, tipoDado dado){
    tipoPonteiro pos_ant, aux, prox;
    if(cheia(*l)){
        return 0;
    } else{
        if(buscaLista(*l, dado.nome, &pos_ant)){
            return 0;
        } else{
            aux = malloc(sizeof(tipoE));
            aux->dado = dado;
            if(pos_ant == NULL){
                aux->prox = l->lista;
                l->lista = aux;
            } else{
                prox = pos_ant->prox;
                aux->prox = prox;
                pos_ant->prox = aux;
            }
            l->quant++;
            return 1;
        }
    }
}

int consultaNome(tipoLista l, tipoDado *dado){
    tipoPonteiro pos_ant, prox;
    if(vazia(l)){
        return 0;
    } else{
        if(buscaLista(l, dado->nome, &pos_ant)){
            if(pos_ant == NULL){
                *dado = l.lista->dado;
            } else{
                prox = pos_ant->prox;
                *dado = prox->dado;
            }
            return 1;
        }
        else{
            return 0;
        }
    }
}

int consultaPos(tipoLista l, int pos, tipoDado *dado){
    int count;
    tipoPonteiro posaux;
    if(vazia(l) || pos > l.quant){
        return 0;
    } else{
        count = 1;
        posaux = l.lista;
        while(count < pos){
            count++;
            posaux = posaux->prox;
        }
        *dado = posaux->dado;
        return 1;
    }
}

int removeLista(tipoLista *l, tipoDado *dado){
    tipoPonteiro pos_ant, prox;
    if(vazia(*l)){
        return 0;
    } else{
        if(buscaLista(*l, dado->nome, &pos_ant)){
            if(pos_ant == NULL){
                prox = l->lista;
                *dado = prox->dado;
                l->lista = prox->prox;
            } else{
                prox = pos_ant->prox;
                *dado = prox->dado;
                pos_ant->prox = prox->prox;
            }
            free(prox);
            l->quant--;
            return 1;
        } else{
            return 0;
        }
    }
}

int atualizaLista(tipoLista *l, tipoDado dado){
    tipoPonteiro pos_ant, novoDado;
    if(vazia(*l)){
        return 0;
    } else{
        if(buscaLista(*l, dado.nome, &pos_ant)){
            if(pos_ant == NULL) {
                novoDado = l->lista;
            } else {
                novoDado = pos_ant->prox;
            }
            novoDado->dado = dado;
            return 1;
        } else{
            return 0;
        }
    }
}

