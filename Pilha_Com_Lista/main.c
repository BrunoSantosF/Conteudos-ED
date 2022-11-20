#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Aluno.h"
#include "PilhaLista.h"


int main(){
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

    tPilha_lista * pilhalista = CriaPilha_Lista();

    InserePilha_Lista(a1,pilhalista);
    InserePilha_Lista(a2,pilhalista);
    InserePilha_Lista(a3,pilhalista);
    InserePilha_Lista(a4,pilhalista);
    InserePilha_Lista(a5,pilhalista);
    InserePilha_Lista(a6,pilhalista);
    InserePilha_Lista(a7,pilhalista);
    InserePilha_Lista(a8,pilhalista);
    InserePilha_Lista(a9,pilhalista);

    ImprimiPilha_Lista(pilhalista);

    
    RetiraPilha_lista(pilhalista);
    
    ImprimiPilha_Lista(pilhalista);

    

    LiberaPilha_Lista(pilhalista);

    return 0;
}

