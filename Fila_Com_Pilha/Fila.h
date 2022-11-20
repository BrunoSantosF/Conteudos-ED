#ifndef FILA_H
#define FILA_H

typedef struct fila tFila;

tFila * CriaFila();
void InsereFila(tFila * fila, int elem);
int RetiraFila(tFila * fila);
void ImprimirFila(tFila * fila);
void LiberaFila(tFila * fila);

#endif