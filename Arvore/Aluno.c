#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Aluno.h"

struct aluno {
    int id;
    char * nome;
};


tAluno * CriaAluno(char * nome, int id){
    tAluno * aluno = malloc(sizeof(tAluno));

    aluno->id = id;
    aluno->nome = strdup(nome);

    return aluno;
}

char * RetornaNome(tAluno * aluno){
    return aluno->nome;
}

int RetornaId(tAluno * aluno){
    return aluno->id;
}

void ImprimiAluno(tAluno * aluno){
    printf("%s[%d]",RetornaNome(aluno),RetornaId(aluno));
}

void RemoveAluno(tAluno * aluno){
    free(aluno->nome);
    free(aluno);
}