#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Aluno.h"

struct aluno {
    char * nome;
    int matricula;
};

tAluno * CriaAluno(char * nome, int matricula){
    tAluno * aluno = malloc(sizeof(tAluno));
    aluno->matricula = matricula;
    aluno->nome = strdup(nome);

    return aluno;
}

char * RetornaNomeAluno(tAluno * aluno){
    return aluno->nome;
}

int RetornaMatriculaAluno(tAluno * aluno){
    return aluno->matricula;
}

void ImprimiAluno(tAluno * aluno){
    printf("Aluno: %s <-> Matricula: %d\n",aluno->nome,aluno->matricula);
}

void LiberaAluno(tAluno * aluno){
    free(aluno->nome);
    free(aluno);
}