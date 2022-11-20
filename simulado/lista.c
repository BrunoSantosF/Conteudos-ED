#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"
#include "BanhoTosa.h"
#include "lista.h"

#define gatoo 0
#define cachorroo 1

typedef struct cell tCell;

struct cell {
    void  * item;
    int id;
    tCell * prox;
};

struct lista {
    tCell * prim;
    tCell * ult;    
};

tLista * CriaLista(){
    tLista * lista = malloc(sizeof(tLista));
    lista->prim = lista->ult = NULL;

    return lista;
}

tLista * InsereNaListaCachorro(tLista * lista, void * item){
    tCell * aux =  malloc(sizeof(tCell));
    aux->id = cachorroo;
    aux->item = item;
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
    }
    else {
        lista->ult->prox = aux;
        lista->ult = aux;
    }

    return lista;

}

tLista * InsereNaListaGato(tLista * lista, void * item){
    tCell * aux =  malloc(sizeof(tCell));
    aux->id = gatoo;
    aux->item = item;
    aux->prox = NULL;

    if (lista->prim == NULL){
        lista->prim = aux;
        lista->ult = aux;
    }
    else {
        lista->ult->prox = aux;
        lista->ult = aux;
    }

    return lista;

}


void ImprimiLista(tLista * lista,int id){
    tCell * aux = lista->prim;

    for (aux;aux != NULL;aux = aux->prox){
        if (aux->id == cachorroo ){
            imprimeCachorro(aux->item);
        }
        if (aux->id == gatoo){
            imprimeGato(aux->item);
        }
        
    }
}

//Valor Gato: 30 reais, Valor Cachorro: 40 reais. 
//Caso o animal seja agressivo, é cobrado uma taxa extra de 5 reais.
float  CalculandoReceitinha(tLista * lista){
    tCell * aux = lista->prim;
    float result = 0.0;

    while (aux){
        if (aux->id == cachorroo){
            if (retornaNivelAgressividadeCachorro(aux->item)){
                result += 45;
            }
            else {
                result += 40;
            }
        }
        else {
            if (retornaNivelAgressividadeGato(aux->item)){
                result += 35;
            }
            else {
                result += 30;
            }
        }
        aux = aux->prox;
    }
    
    return result;
}

int EncontrarAnimalCachorro(tLista * listaAgressivo,tLista * listaManso,char * name,int id){
    
    tCell * aux1 = listaAgressivo->prim;
    //tCell * aux2 = listaManso->prim;

    //lista de agressivo(1)
    while (aux1){
        if (aux1->id == cachorroo && strcmp(name,retornaNomeCachorro(aux1->item)) == 0){
            if (id != 1){
                return 1; //quer dizer que está na lista errada e era pra está no manso
            }
        }
        aux1 = aux1->prox;
    }

    aux1 = listaManso->prim;
    //lista de manso(0)
    while (aux1){
        if (aux1->id == cachorroo && strcmp(name,retornaNomeCachorro(aux1->item)) == 0){
            if (id != 0){
                return 2; //quer dizer que está na lista errada e era pra está no agressivo
            }
        }
        aux1 = aux1->prox;
    }

    return -1;
}

int EncontrarAnimalGato(tLista * listaAgressivo,tLista * listaManso,char * name,int id){
    
    tCell * aux1 = listaAgressivo->prim;
    //tCell * aux2 = listaManso->prim;

    //lista de agressivo(1)
    while (aux1){
        if (aux1->id == gatoo && strcmp(name,retornaNomeGato(aux1->item)) == 0){
            if (id != 1){
                return 1; //quer dizer que está na lista errada e era pra está no manso
            }
        }
        aux1 = aux1->prox;
    }

    aux1 = listaManso->prim;
    //lista de manso(0)
    while (aux1){
        if (aux1->id == gatoo && strcmp(name,retornaNomeGato(aux1->item)) == 0){
            if (id != 0){
                return 2; //quer dizer que está na lista errada e era pra está no agressivo
            }
        }
        aux1 = aux1->prox;
    }

    return -1;
}



tLista * RemoverLista(tLista * lista,char * name){
    if (lista == NULL){
        return lista;
    }
    tCell * aux1 = lista->prim;
    tCell * aux2 = NULL;

    while (aux1){
        if (aux1->id == gatoo && strcmp(name,retornaNomeGato(aux1->item)) == 0){
            break;
        }
        else {
            if (aux1->id == cachorroo && strcmp(name,retornaNomeCachorro(aux1->item)) == 0){
                break;
            }
        }
        aux2 = aux1;
        aux1 = aux1->prox;
    }

    if (lista->prim == aux1){
        lista->prim = aux1->prox;
    }
    else if(lista->ult == aux1){
        lista->ult = aux2;
        aux2->prox = NULL;
    }
    else {
        aux2->prox = aux1->prox;
    }

   

    free(aux1);

    return lista;

}


void LiberaLista(tLista * lista){
    tCell * aux1 = lista->prim;
    tCell * aux2 = NULL;

    while (aux1){
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;    
    }
    
    free(lista);

}