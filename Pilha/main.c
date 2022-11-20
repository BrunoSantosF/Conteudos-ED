#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"


int main(){
    tPilha * pilha =  CriandoPilha();

    InserindoPilha(pilha,2);
    InserindoPilha(pilha,3);
    InserindoPilha(pilha,1);
    InserindoPilha(pilha,4);
    InserindoPilha(pilha,5);
    InserindoPilha(pilha,8);
    InserindoPilha(pilha,0);
    InserindoPilha(pilha,9);
    

    ImprimirPilha(pilha);
    
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);
    RemovendoPilha( pilha);

    ImprimirPilha(pilha);


    LiberaPilha(pilha);

    return 0;
}