#ifndef FILALISTA_H
#define FILALISTA_H

typedef struct fila_lista tFila_Lista;

tFila_Lista * CriaFila_Lista();
void InsereFila_Lista(tFila_Lista * filalista, tProfessor * professor);
tProfessor * RetiraFila_Lista(tFila_Lista * filalista);
void ImprimiFila_Lista(tFila_Lista * filalista);
void LiberaFila_Lista(tFila_Lista * filalista);


#endif