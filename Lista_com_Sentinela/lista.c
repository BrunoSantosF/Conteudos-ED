#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct cell tCell;

struct cell {
    char * item;
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

void InsereNaLista(tLista * lista,char * item){
    tCell * aux = malloc(sizeof(tCell));
    aux->item = strdup(item);
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

    for (aux;aux != NULL;aux =  aux->prox){
        printf("%s\n",aux->item);
    }
}

void LiberaLista(tLista * lista){
    tCell * atual = lista->prim;
    tCell * anterior = NULL;


    while (atual){
        anterior = atual->prox;
        free(atual->item);
        free(atual);
        atual = anterior;
    }

    free(lista);
}

void RemoveElementoLista(tLista * lista,char * item){
    tCell * atual = lista->prim;
    tCell * anterior = NULL;

    if (!lista){
        return;
    }

    while (strcmp(item,atual->item) != 0 && atual != NULL ){
        anterior = atual;
        atual =  atual->prox;
    }

    //se for o primeiro item 
    if (lista->prim == atual){
        lista->prim =  atual->prox;

    }//se for o ultimo item
    else if (lista->ult ==  atual){
        lista->ult = anterior;
        anterior->prox = NULL;
    }
    else {
        anterior->prox = atual->prox;
    }

    free(atual->item);
    free(atual);

}
