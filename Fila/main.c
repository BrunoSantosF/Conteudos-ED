#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Fila.h"

int main(){
    tFila * fila = CriaFila();

    InsereFila(fila,0);
    InsereFila(fila,1);
    InsereFila(fila,2);
    InsereFila(fila,3);
    InsereFila(fila,4);
    InsereFila(fila,5);
    InsereFila(fila,6);
    InsereFila(fila,7);
    
    ImprimirFila(fila);

    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    RetiraFila(fila);
    

    ImprimirFila(fila);

    LiberaFila(fila);



    return 0;
}