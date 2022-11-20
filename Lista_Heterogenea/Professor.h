#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct professor tProfessor;

tProfessor * CriaProfessor(char * nome, int turma);
char * RetornaNomeProfessor(tProfessor * professor);
int RetornaMatriculaProfessor(tProfessor * professor);
void ImprimiProfessor(tProfessor * professor);
void LiberaProfessor(tProfessor * professor);

#endif