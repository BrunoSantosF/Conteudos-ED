#ifndef LISTA_H
#define LISTA_H

typedef struct lista tLista;

tLista * CriaLista();

tLista * InsereNaListaCachorro(tLista * lista, void * item);
tLista * InsereNaListaGato(tLista * lista, void * item);
void ImprimiLista(tLista * lista,int id);
void LiberaLista(tLista * lista);
float  CalculandoReceitinha(tLista * lista);

int EncontrarAnimalCachorro(tLista * listaAgressivo,tLista * listaManso,char * name,int id);
int EncontrarAnimalGato(tLista * listaAgressivo,tLista * listaManso,char * name,int id);
tLista * RemoverLista(tLista * lista,char * name);

#endif