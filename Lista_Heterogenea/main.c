#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "lista.h"
#include "Professor.h"
#include "Aluno.h"

int main(){
    tProfessor *p1,*p2,*p3,*p4;

    p1 = CriaProfessor("ZZZZZ", 10);
    p2 = CriaProfessor("XXXXX", 20);
    p3 = CriaProfessor("YYYYY", 30);
    p4 = CriaProfessor("PPPPP", 40);
    
    tAluno *a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9;

    a1 = CriaAluno("Afonso", 1);
    a2 = CriaAluno("Bruno", 2);
    a3 = CriaAluno("Carlos", 3);
    a4 = CriaAluno("Daniel", 4);
    a5 = CriaAluno("Fael", 5);
    a6 = CriaAluno("Gatti", 6);
    a7 = CriaAluno("Herique", 7);
    a8 = CriaAluno("Icaro", 8);
    a9 = CriaAluno("Joao", 9);

    tLista * lista = CriaLista();

    InsereAlunoLista(lista,a1);
    InsereAlunoLista(lista,a2);
    InsereAlunoLista(lista,a3);
    InsereProfessorLista(lista,p1);
    InsereAlunoLista(lista,a4);
    InsereAlunoLista(lista,a5);
    InsereProfessorLista(lista,p2);
    InsereAlunoLista(lista,a6);
    InsereAlunoLista(lista,a7);
    InsereProfessorLista(lista,p3);
    InsereAlunoLista(lista,a8);
    InsereAlunoLista(lista,a9);
    InsereProfessorLista(lista,p4);

    ImprimiLista(lista);

    RemoveLista(lista,p3);
    RemoveLista(lista,a6);

    ImprimiLista(lista);

    LiberaProfessor(p1);
    LiberaProfessor(p2);
    LiberaProfessor(p3);
    LiberaProfessor(p4);
    LiberaAluno(a1);
    LiberaAluno(a2);
    LiberaAluno(a3);
    LiberaAluno(a4);
    LiberaAluno(a5);
    LiberaAluno(a6);
    LiberaAluno(a7);
    LiberaAluno(a8);
    LiberaAluno(a9);

    LiberaLista( lista);

    return 0;
}