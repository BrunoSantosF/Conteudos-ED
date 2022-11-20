#ifndef PILHALISTA_H
#define PILHALISTA_H

#include "Aluno.h"

typedef struct pilha_lista tPilha_lista;

tPilha_lista * CriaPilha_Lista();
void InserePilha_Lista(tAluno * aluno, tPilha_lista * pilhalista);
tAluno * RetiraPilha_lista(tPilha_lista * pilhalista);
void ImprimiPilha_Lista(tPilha_lista * pilhalista);
void LiberaPilha_Lista(tPilha_lista * pilhalista);


#endif