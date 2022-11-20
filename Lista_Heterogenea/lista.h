#ifndef LISTA_H
#define LISTA_H


typedef struct lista tLista;

tLista * CriaLista();
void InsereAlunoLista(tLista * lista,void * item);
void InsereProfessorLista(tLista * lista,void * item);
void ImprimiLista(tLista * lista);
void RemoveLista(tLista * lista,void * item);
void LiberaLista(tLista * lista);

#endif