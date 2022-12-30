#ifndef INVENTOTY_H
#define INVENTOTY_H
#include "../include/item.h"

typedef struct inventory tInventory;

tInventory * InitializeInventory();
tInventory * CreateInventory(tInventory * inventory , tItem * item);
float ReturnValueInventory(tInventory * inventory);

void PrintInventory(tInventory * inventory);


#endif