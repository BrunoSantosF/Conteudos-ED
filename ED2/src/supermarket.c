#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/branch.h"
#include "../include/supermarket.h"

typedef struct cell tCell;

struct cell {
    tBranch * branch;
    tCell * next;
};

struct supermarket {
    tCell * first;
    tCell * last;
    char * name;
    float value;
};

tSupermarket * InitializeSupermarket(char * name){
    tSupermarket * supermarket = malloc(sizeof(tSupermarket));
    supermarket->first = supermarket->last = NULL;
    supermarket->name = strdup(name);
    supermarket->value = 0;
}

tSupermarket * CreateSupermarket(tBranch * branch , tSupermarket * supermarket){
    tCell * assistant = malloc(sizeof(tCell));
    assistant->branch = branch;
    assistant->next = NULL;

    if (supermarket->first == NULL){
        supermarket->first = assistant;
        supermarket->last = assistant;
    } else {
        supermarket->last->next = assistant;
        supermarket->last = assistant;   
    }

    return supermarket;

}

void ReturnBranchTotal(tSupermarket * supermarket){
    tCell * aux = supermarket->first;
    float sum = 0.0;

    for (aux; aux != NULL;aux = aux->next){
        sum += ReturnValueInventory(ReturnInventory(aux->branch));
    }
    
    supermarket->value = sum;
}

void PrintSupermarket(tSupermarket * supermarket){
    tCell * aux = supermarket->first;
    ReturnBranchTotal(supermarket);

    printf("Name:%s, Branch total: %.2f\n",supermarket->name,supermarket->value);
    for (aux; aux != NULL;aux = aux->next){
        PrintBranch(aux->branch);
    }
 
}

void FreeSupermarket(tSupermarket * supermarket){
    tCell * aux1 = supermarket->first;
    tCell * aux2 = NULL;

    while (aux1){
        aux2 = aux1->next;
        //LiberarAluno(aux1->aluno);
        free(aux1);
        aux1 = aux2;
    }
    free(supermarket);
}




