#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Professor.h"
#include "FilaLista.h"

typedef struct cell tCell;

struct cell {
    tProfessor * professor;
    tCell * prox;
};

struct fila_lista {
    tCell * prim;
    tCell * auxPrim;
    tCell * ult;
};

tProfessor * RetornaProfessorFila_Lista(tCell * aux);

tFila_Lista * CriaFila_Lista(){
    tFila_Lista * filalista = malloc(sizeof(tFila_Lista));
    filalista->prim = filalista->ult = filalista->auxPrim = NULL;

    return filalista;
}

void InsereFila_Lista(tFila_Lista * filalista, tProfessor * professor){
    tCell * aux = malloc(sizeof(tCell));
    aux->professor = professor;
    aux->prox = NULL;

    if (filalista->prim == NULL){
        filalista->prim = aux;
        filalista->auxPrim = aux;
        filalista->ult = aux;
    }
    else {
        filalista->ult->prox = aux;
        filalista->ult = aux;
    }

}

tProfessor * RetornaProfessorFila_Lista(tCell * aux){
    tProfessor * professor = aux->professor;
    return professor;
}

tProfessor * RetiraFila_Lista(tFila_Lista * filalista){
    
    tProfessor * professor = RetornaProfessorFila_Lista(filalista->prim);
    filalista->prim = filalista->prim->prox;
    
    return professor;
}

void ImprimiFila_Lista(tFila_Lista * filalista){
    tCell * aux = filalista->prim;

    for (aux; aux != NULL; aux = aux->prox){
        ImprimiProfessor(aux->professor);
    }
    printf("==================\n");
}

void LiberaFila_Lista(tFila_Lista * filalista){
    tCell * atual = filalista->auxPrim;
    tCell * anterior = NULL;

    while (atual){
        anterior = atual->prox;
        free(atual);
        atual = anterior;
    }
    
    free(filalista);
}
