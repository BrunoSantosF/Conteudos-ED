#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Professor.h"

struct professor {
    char * nome;
    int turma;
};

tProfessor * CriaProfessor(char * nome, int turma){
    tProfessor * professor = malloc(sizeof(tProfessor));
    professor->turma = turma;
    professor->nome = strdup(nome);

    return professor;
}

char * RetornaNomeProfessor(tProfessor * professor){
    return professor->nome;
}

int RetornaMatriculaProfessor(tProfessor * professor){
    return professor->turma;
}

void ImprimiProfessor(tProfessor * professor){
    printf("professor: %s -> turma: %d\n",professor->nome,professor->turma);
}

void LiberaProfessor(tProfessor * professor){
    free(professor->nome);
    free(professor);
}