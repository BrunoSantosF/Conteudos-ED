#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gato.h"
#include "Cachorro.h"
#include "BanhoTosa.h"
#include "lista.h"


struct banhotosa {
    char * nomeLoja;
    tLista * listaAgressivos;
    tLista * listaMansos;
};

BanhoTosa * inicBanhoTosa(char* nome){
    BanhoTosa * loja =  malloc(sizeof(BanhoTosa));
    loja->nomeLoja = strdup(nome);
    loja->listaAgressivos = CriaLista();
    loja->listaMansos = CriaLista();

    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){

    if (retornaNivelAgressividadeCachorro(dog)){
        loja->listaAgressivos = InsereNaListaCachorro(loja->listaAgressivos,dog);
    }
    else {
        loja->listaMansos = InsereNaListaCachorro(loja->listaMansos,dog);
    }
}

void cadastraGato(BanhoTosa* loja, Gato* cat){

    if (retornaNivelAgressividadeGato(cat)){
        loja->listaAgressivos = InsereNaListaGato(loja->listaAgressivos,cat);
    }
    else {
        loja->listaMansos = InsereNaListaGato(loja->listaMansos,cat);
    }
}

void imprimeBanhoTosa(BanhoTosa* loja){
    printf("\nNome da Loja : %s\n",loja->nomeLoja);
    printf("\nLista de Mansos : \n");
    ImprimiLista(loja->listaMansos,0);
    printf("\n\nLista de Agressivos : \n");
    ImprimiLista(loja->listaAgressivos,1);
}


float calculaReceita(BanhoTosa* loja) {
    return CalculandoReceitinha(loja->listaAgressivos) + CalculandoReceitinha(loja->listaMansos);
}

void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
     if (EncontrarAnimalCachorro(loja->listaAgressivos,loja->listaMansos,retornaNomeCachorro(dog),retornaNivelAgressividadeCachorro(dog)) == 1){
        cadastraCachorro(loja,dog);
        loja->listaAgressivos = RemoverLista(loja->listaAgressivos,retornaNomeCachorro(dog));
        
    }
    else if (EncontrarAnimalCachorro(loja->listaAgressivos,loja->listaMansos,retornaNomeCachorro(dog),retornaNivelAgressividadeCachorro(dog)) == -1){
        printf("\n\n\n\nEsta tudo normal\n\n\n\n");
    }
    else {
        cadastraCachorro(loja,dog);
        loja->listaMansos = RemoverLista( loja->listaMansos,retornaNomeCachorro(dog));
        
    }
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    
    if (EncontrarAnimalGato(loja->listaAgressivos,loja->listaMansos,retornaNomeGato(cat),retornaNivelAgressividadeGato(cat)) == 1){
        cadastraGato(loja,cat);
        loja->listaAgressivos = RemoverLista(loja->listaAgressivos,retornaNomeGato(cat));
        
    }
    else if (EncontrarAnimalGato(loja->listaAgressivos,loja->listaMansos,retornaNomeGato(cat),retornaNivelAgressividadeGato(cat)) == -1){
        printf("\n\n\n\nEsta tudo normal\n\n\n\n");
    }
    else {
        cadastraGato(loja,cat);
        loja->listaMansos = RemoverLista( loja->listaMansos,retornaNomeGato(cat));
        
    }

}

void liberaBanhoTosa(BanhoTosa* loja){
    free(loja->nomeLoja);
    LiberaLista(loja->listaAgressivos);
    LiberaLista(loja->listaMansos);
    free(loja);
}