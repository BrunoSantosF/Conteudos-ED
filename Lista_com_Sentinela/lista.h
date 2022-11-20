#ifndef LISTA_H
#define LISTA_H

typedef struct lista tLista;

//Cria uma lista vazia
tLista * CriaLista();

//Insere na lista
void InsereNaLista(tLista * lista,char * item);

//Imprimi a lista
void ImprimiLista(tLista * lista);

//libera a lista
void LiberaLista(tLista * lista);

//Remove item
void RemoveElementoLista(tLista * lista,char * item);

#endif