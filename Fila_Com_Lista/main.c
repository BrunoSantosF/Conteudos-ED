#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "Professor.h"
#include "FilaLista.h"


int main(){
    tProfessor *a1,*a2,*a3,*a4,*a5,*a6,*a7,*a8,*a9;

    a1 = CriaProfessor("Afonso", 1);
    a2 = CriaProfessor("Bruno", 2);
    a3 = CriaProfessor("Carlos", 3);
    a4 = CriaProfessor("Daniel", 4);
    a5 = CriaProfessor("Fael", 5);
    a6 = CriaProfessor("Gatti", 6);
    a7 = CriaProfessor("Herique", 7);
    a8 = CriaProfessor("Icaro", 8);
    a9 = CriaProfessor("Joao", 9);

    tFila_Lista * fila = CriaFila_Lista();

    InsereFila_Lista(fila,a1);
    InsereFila_Lista(fila,a2);
    InsereFila_Lista(fila,a3);
    InsereFila_Lista(fila,a4);
    InsereFila_Lista(fila,a5);
    InsereFila_Lista(fila,a6);
    InsereFila_Lista(fila,a7);
    InsereFila_Lista(fila,a8);
    InsereFila_Lista(fila,a9);

    ImprimiFila_Lista(fila);

    RetiraFila_Lista(fila);
    RetiraFila_Lista(fila);
    RetiraFila_Lista(fila);

    ImprimiFila_Lista(fila);


    LiberaProfessor(a1);
    LiberaProfessor(a2);
    LiberaProfessor(a3);
    LiberaProfessor(a4);
    LiberaProfessor(a5);
    LiberaProfessor(a6);
    LiberaProfessor(a7);
    LiberaProfessor(a8);
    LiberaProfessor(a9);

    LiberaFila_Lista(fila);

    return 0;
}

