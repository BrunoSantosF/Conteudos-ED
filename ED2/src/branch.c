#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/branch.h"
#include "../include/inventory.h"


struct branch {
    char * name;
    tInventory * inventory;
};

tBranch * CreateBranch(char * name , tInventory * inventory){
    tBranch * branch = malloc(sizeof(tBranch));
    branch->name = strdup(name);
    branch->inventory = inventory;

    return branch;

}

tInventory * ReturnInventory(tBranch * branch){
    return branch->inventory;
}

void PrintBranch(tBranch * branch){
    printf("       Branch:%s\n",branch->name);
    PrintInventory(branch->inventory);
}

void FreeBranch(tBranch * branch){
    free(branch->name);
    
    free(branch);
}






