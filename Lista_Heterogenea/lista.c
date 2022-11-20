#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "Professor.h"
#include "Aluno.h"

#define alu 1
#define prof 0


typedef struct cell tCell;

struct cell {
    void * item;
    int id;
    tCell * prox;
};

struct lista {
    tCell * prim;
    tCell * ult;
};

tLista * CriaLista(){
    tLista * lista = malloc(sizeof(tLista));
    lista->prim = lista->ult = NULL;

    return lista;
}

void InsereAlunoLista(tLista * lista,void * item){
    tCell * aux = malloc(sizeof(tCell));
    aux->item = item;
    aux->id = alu;
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
    }
    else {
        lista->ult->prox = aux;
        lista->ult = aux;
    }

}


void InsereProfessorLista(tLista * lista,void * item){
    tCell * aux = malloc(sizeof(tCell));
    aux->item = item;
    aux->id = prof;
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
    }
    else {
        lista->ult->prox = aux;
        lista->ult = aux;
    }

}

void ImprimiLista(tLista * lista){
    tCell * aux = lista->prim;

    for (aux; aux != NULL; aux = aux->prox){
        if (aux->id == prof){
            ImprimiProfessor(aux->item);
        }
        else {
            ImprimiAluno(aux->item);
        }
    }
    printf("=======================\n");
}

void RemoveLista(tLista * lista,void * item){
    tCell * atual = lista->prim;
    tCell * anterior = NULL;

    if (!lista){
        return;
    }
    while (atual){
        if (strcmp(RetornaNomeAluno(atual->item),RetornaNomeAluno(item)) == 0 && atual->id == alu){
            break;
        }
        if (strcmp(RetornaNomeProfessor(atual->item),RetornaNomeProfessor(item)) == 0 && atual->id == prof){
            break;
        }
        anterior = atual;
        atual = atual->prox;
    }

    if (lista->prim == atual){
        lista->prim = atual->prox;
    }
    else if (lista->ult == atual){
        lista->ult = anterior;
        anterior->prox = NULL;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual);
     
}


void LiberaLista(tLista * lista){
    tCell * atual = lista->prim;
    tCell * anterior = NULL;

    while (atual){
        anterior = atual->prox;
        free(atual);
        atual = anterior;
    }
    
    free(lista);
}

