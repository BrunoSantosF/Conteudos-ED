#ifndef SUPERMARKET_H
#define SUPERMARKET_H

typedef struct supermarket tSupermarket;

tSupermarket * InitializeSupermarket(char * name);
tSupermarket * CreateSupermarket(tBranch * branch , tSupermarket * supermarket);
void PrintSupermarket(tSupermarket * supermarket);
void FreeSupermarket(tSupermarket * supermarket);
void ReturnBranchTotal(tSupermarket * supermarket);

#endif