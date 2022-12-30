#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno tAluno;

tAluno * CriaAluno(char * nome, int id);
char * RetornaNome(tAluno * aluno);
int RetornaId(tAluno * aluno);
void ImprimiAluno(tAluno * aluno);
void RemoveAluno(tAluno * aluno);

#endif