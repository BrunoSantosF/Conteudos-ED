#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "Arvore.h"

struct arvore {
    tAluno * item;
    tArvore * esquerda;
    tArvore * direita;
};


tArvore * InsereArvore(tAluno * aluno,tArvore * arvore){
    
    if (arvore == NULL){
        arvore = malloc(sizeof(tArvore));
        arvore->item = aluno;
        arvore->esquerda = NULL;
        arvore->direita = NULL;
    }
    else if ( RetornaId(arvore->item) < RetornaId(aluno)){
        arvore->direita = InsereArvore(aluno,arvore->direita);
    }
    else {
        arvore->esquerda = InsereArvore(aluno,arvore->esquerda);
    }
   
    return arvore;
    
}

void ImprimiArvore(tArvore * arvore){
    
    if (arvore){
        ImprimiAluno(arvore->item);
        printf("\n------ esquerda ------\n");
        ImprimiArvore(arvore->esquerda);
        printf("\n------ direita ------\n");
        ImprimiArvore(arvore->direita);
        
    }
    
}

int QuantidadeDeFolhas(tArvore * arvore){


    if (arvore == NULL){
        return 0;
    }
    else if (arvore->direita == NULL && arvore->esquerda == NULL){
        return 1;
    }
    else {
        return QuantidadeDeFolhas(arvore->esquerda) + QuantidadeDeFolhas(arvore->direita);
    }
    
}

int PertenceArvore(tArvore * arvore, char * nome){

    // 1- encontrou 0-nao encontrou
    if (arvore == NULL){
        return 0;
    }

    if (!strcmp(nome,RetornaNome(arvore->item))){
        return 1;
    }
    else {
        int result = PertenceArvore(arvore->direita,nome) + PertenceArvore(arvore->esquerda,nome);
        if (result > 0){
            return 1;
        }
        else {
            return 0;
        }
        
    }

}

int NumeroDeOcorrencias(tArvore * arvore,char * nome){

    if (arvore == NULL){
        return 0;
    }
    else if (!strcmp(nome,RetornaNome(arvore->item))){
        return 1;
    }
    else {
        return NumeroDeOcorrencias(arvore->esquerda,nome)+NumeroDeOcorrencias(arvore->direita,nome);
    }

}


tArvore * RetornaNoPai(tArvore * arvore,char * nome){
    tArvore * arv1;
    tArvore * arv2;

    if (arvore == NULL){
        return NULL;
    }
    else if (arvore->direita != NULL && !strcmp(nome,RetornaNome(arvore->direita->item)) || arvore->esquerda != NULL && !strcmp(nome,RetornaNome(arvore->esquerda->item))){
        return arvore;
    }
    else {
        arv1 = RetornaNoPai(arvore->esquerda, nome);
        arv2 = RetornaNoPai(arvore->direita, nome);

        if (arv1){
            return arv1;
        }
        if (arv2){
            return arv2;
        }

        return NULL;

    }
}

int AlturaArvore(tArvore * arvore){
    
    if(arvore == NULL || arvore->direita == NULL && arvore->esquerda == NULL){
        return 0;
    }
    else{
        int esq = AlturaArvore(arvore->esquerda)+ 1;
        int dir = AlturaArvore(arvore->direita)+ 1;

        if(esq > dir)
            return esq;
        else
            return dir;
    }

}

void ImprimiNo(tArvore * arvore){
    printf("Nó pai: ");
    ImprimiAluno(arvore->item);
    printf("\n");
}