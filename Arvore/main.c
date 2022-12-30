#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"
#include "Arvore.h"

int main(){

    FILE * arquivo = fopen("entrada.txt","r");
    char nome[30],string[100];
    int id = 0;
    
    tArvore * arvore = NULL;
    while (!feof(arquivo)){
        fscanf(arquivo,"%[^\n]\n",string);
        sscanf(string,"%[^-]-%d",nome,&id);
        
        tAluno * aluno = CriaAluno(nome,id);
        arvore = InsereArvore(aluno,arvore);

    }
    
    ImprimiArvore(arvore);

    printf("\033[33;1mQuantidade de folhas: %d\033[m\n",QuantidadeDeFolhas(arvore));
    printf("\033[32;1mSe Pertence: %d\033[m\n",PertenceArvore(arvore,"alan"));
    printf("\033[34;1mNumero de ocorrencias: %d\033[m\n",NumeroDeOcorrencias(arvore,"fernandes"));
    tArvore * noPai = RetornaNoPai(arvore,"leao");
    ImprimiNo(noPai);
    printf("\033[36;1mTamanho da arvore: %d\033[m\n",AlturaArvore(arvore));

    return 0;
}