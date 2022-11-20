#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"

#define tam 8

struct fila {
    int inicio; //inicio da fila
    int qtd; //quantidade de elementos na fila
    int vetor[tam]; //fila de vetor
};

tFila * CriaFila(){
    tFila * fila = malloc(sizeof(tFila));
    fila->inicio = fila->qtd = 0;

    return fila;
}

void InsereFila(tFila * fila, int elem){
    //verifica se a fila existe ou se ela já está cheia
    if (!fila || fila->qtd >= tam){
        printf("Fila está cheia ou ocorreu um erro !!!\n");
        return;
    }

    int pos  = (fila->inicio + fila->qtd) % tam; //calculo para achar a posição para colocar o elemento no vetor circular
    fila->vetor[pos] = elem;
    fila->qtd++;

}

int RetiraFila(tFila * fila){

    if (!fila || fila->qtd <= 0){
        printf("Fila está vazia ou ocorreu um erro !!!\n");
        return 0000;
    }

    int x = fila->vetor[fila->inicio];
    printf("Elemento Removido: %d\n",x);

    fila->inicio = (fila->inicio + 1)%tam;
    fila->qtd--;

    return x;
}

void ImprimirFila(tFila * fila){

    for (int i = 0; i < fila->qtd; i++){
        int pos = (fila->inicio + i) % tam;
        printf("%dº = %d\n",i,fila->vetor[pos]);
    }
    printf("=================\n");
}

void LiberaFila(tFila * fila){
    free(fila);
}