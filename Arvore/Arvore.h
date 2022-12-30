#ifndef ARVORE_H
#define ARVORE_H
#include "Aluno.h"
#include "Arvore.h"

typedef struct arvore tArvore;

tArvore * InsereArvore(tAluno * aluno,tArvore * arvore);
void ImprimiArvore(tArvore * arvore);
int QuantidadeDeFolhas(tArvore * arvore);
int PertenceArvore(tArvore * arvore, char * nome);
int NumeroDeOcorrencias(tArvore * arvore,char * nome);
tArvore * RetornaNoPai(tArvore * arvore,char * nome);
void ImprimiNo(tArvore * arvore);
int AlturaArvore(tArvore * arvore);

#endif