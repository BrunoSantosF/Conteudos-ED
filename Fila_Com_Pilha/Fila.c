#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"
#include "Pilha.h"

#define tam 8

struct fila {
    tPilha * pilha1;
    tPilha * pilha2;
};

tFila * CriaFila(){
    tFila * fila = malloc(sizeof(tFila));
    fila->pilha1 = CriandoPilha();
    fila->pilha2 = CriandoPilha();

    return fila;
}

void InsereFila(tFila * fila, int elem){
    InserindoPilha(fila->pilha1, elem);
}

int RetiraFila(tFila * fila){
    int qtd = RetornaTopo(fila->pilha1);
    
    for (int i = 0; i <= qtd-1; i++){
        InserindoPilha(fila->pilha2,RemovendoPilha(fila->pilha1));
    }
    RemovendoPilha(fila->pilha2);
    
    qtd = RetornaTopo(fila->pilha2);
    for (int i = 0; i <= qtd-1; i++){
        InserindoPilha(fila->pilha1,RemovendoPilha(fila->pilha2));
    }
    
    return 0;
}

void ImprimirFila(tFila * fila){
    ImprimirPilha(fila->pilha1);
}

void LiberaFila(tFila * fila){
    free(fila);
}