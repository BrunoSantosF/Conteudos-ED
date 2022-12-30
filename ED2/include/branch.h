#ifndef BRANCH_H
#define BRANCH_H
#include "../include/inventory.h"

typedef struct branch tBranch;

tBranch * CreateBranch(char * name , tInventory * inventory);
void PrintBranch(tBranch * branch);
void FreeBranch(tBranch * branch);
tInventory * ReturnInventory(tBranch * branch);

#endif