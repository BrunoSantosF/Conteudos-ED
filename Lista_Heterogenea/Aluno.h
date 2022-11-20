#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno tAluno;

tAluno * CriaAluno(char * nome, int matricula);
char * RetornaNomeAluno(tAluno * aluno);
int RetornaMatriculaAluno(tAluno * aluno);
void ImprimiAluno(tAluno * aluno);
void LiberaAluno(tAluno * aluno);

#endif