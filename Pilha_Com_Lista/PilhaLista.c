#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Aluno.h"
#include "PilhaLista.h"



typedef struct cell tCell;

struct cell {
    tAluno * aluno;
    tCell * prox;
    tCell * anterior;
};

struct pilha_lista{
    tCell * prim;
    tCell * ult;
};

tAluno * RetornaAlunoDaPilhaLista(tCell * aux);

tPilha_lista * CriaPilha_Lista(){
    tPilha_lista * pilhalista = malloc(sizeof(tPilha_lista));
    pilhalista->prim = pilhalista->ult = NULL;

    return pilhalista;
}

void InserePilha_Lista(tAluno * aluno, tPilha_lista * pilhalista){
    tCell * aux = malloc(sizeof(tCell));
    aux->aluno = aluno;
    aux->prox = NULL;
    aux->anterior = NULL;

    if (pilhalista->prim == NULL){
        pilhalista->prim = aux;
        pilhalista->ult = aux;

    }
    else {
        aux->anterior = pilhalista->ult;
        pilhalista->ult->prox = aux;
        pilhalista->ult = aux;
    }
}

tAluno * RetornaAlunoDaPilhaLista(tCell * aux){
    return aux->aluno;
}

tAluno * RetiraPilha_lista(tPilha_lista * pilhalista){
    if (pilhalista == NULL){
        printf("Pilha esta vazia\n");
        return NULL;
    }
    tAluno * aux = RetornaAlunoDaPilhaLista(pilhalista->ult);

    pilhalista->ult = pilhalista->ult->anterior;
    LiberaAluno(aux);
    free(pilhalista->ult->prox);
    pilhalista->ult->prox = NULL;

    return aux;

}

void ImprimiPilha_Lista(tPilha_lista * pilhalista){
    tCell * aux = pilhalista->prim;

    for(aux; aux != NULL; aux= aux->prox){
        ImprimiAluno(aux->aluno);
    }
    printf("===================\n");
}

void LiberaPilha_Lista(tPilha_lista * pilhalista){
    tCell * atual = pilhalista->prim;
    tCell * anterior = NULL;

    while (atual){
        anterior = atual->prox;
        LiberaAluno(atual->aluno);
        free(atual);
        atual = anterior;
    }
    
    free(pilhalista);

}

