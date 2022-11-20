#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"

#define tam 8

struct pilha {
    int topo;
    int vetor[tam];
};

tPilha * CriandoPilha(){
    tPilha * pilha = malloc(sizeof(tPilha));
    pilha->topo = 0;

    return pilha;
}

void InserindoPilha(tPilha * pilha, int i){
    //verificando a pilha se ela está cheia ou nao foi alocada.
    if (!pilha || pilha->topo >= tam){
        printf("Pilha cheia ou com erro !!!\n");
        return;
    }

    pilha->vetor[pilha->topo] = i;

    pilha->topo++;

}

int RemovendoPilha(tPilha * pilha){
    if (!pilha || pilha->topo <= 0){
        printf("Pilha vazia ou com erro !!!\n");
        return 000;
    }

    int x = pilha->vetor[pilha->topo-1];
    pilha->topo--;
    return x;

}

void ImprimirPilha(tPilha * pilha){

    for (int i = 0; i < pilha->topo; i++){
        printf("%dº = %d\n",i,pilha->vetor[i]);
    }
    printf("=================\n\n");
}

void LiberaPilha(tPilha * pilha){
    free(pilha);
}
