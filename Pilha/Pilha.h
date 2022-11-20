#ifndef PILHA_H
#define PILHA_H

typedef struct pilha tPilha;

tPilha * CriandoPilha();
void InserindoPilha(tPilha * pilha, int i);
int RemovendoPilha(tPilha * pilha);
void ImprimirPilha(tPilha * pilha);
void LiberaPilha(tPilha * pilha);


#endif