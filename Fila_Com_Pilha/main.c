#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"
#include "Pilha.h"

int main(){
    tFila * fila = CriaFila();

    InsereFila(fila,1);
    InsereFila(fila,2);
    InsereFila(fila,3);
    InsereFila(fila,4);
    InsereFila(fila,5);
    
    ImprimirFila(fila);

    RetiraFila(fila);
    RetiraFila(fila);

    ImprimirFila(fila);


    return 0;
}