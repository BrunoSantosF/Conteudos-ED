#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/item.h"
#include "../include/inventory.h"
#include "../include/branch.h"
#include "../include/supermarket.h"

/* Informações sobre o domínio do problema:

- Um Supermercado tem um nome, um vetor de filiais e um valor total do estoque;
- Uma filial tem um nome e um estoque;
- Um estoque tem um valor e um vetor de itens de estoque;
- Um item de estoque tem um quantidade e está relacionado ao um tipo de produto;
- Um tipo de produto tem um nome e um valor.
 */
int main( int argc, char** argv ) {
    tSupermarket * supermarket;
    tBranch * branch;
    tInventory * inventory;
    tItem * it1 ,*it2 ,*it3;

    tBranch * branch2;
    tInventory * inventory2;
    tItem * it4 ,*it5 ,*it6;


    it1 = CreateItem("Leite Integral Selita" , 10 ,200);
    it2 = CreateItem("Presunto de Parma" , 50 ,300);
    it3 = CreateItem("Queijo" , 30 ,200);

    it4 = CreateItem("Biscoito" , 5 ,2000);
    it5 = CreateItem("Presunto de Parma" , 50 ,3000);
    it6 = CreateItem("Carne de Sol" , 30 ,50);

    inventory =  InitializeInventory();
    inventory = CreateInventory(inventory , it1);
    inventory = CreateInventory(inventory , it2);
    inventory = CreateInventory(inventory , it3);

    inventory2 =  InitializeInventory();
    inventory2 = CreateInventory(inventory2 , it4);
    inventory2 = CreateInventory(inventory2 , it5);
    inventory2 = CreateInventory(inventory2 , it6);


    branch = CreateBranch("Jardim Camburi", inventory);
    branch2 = CreateBranch("Jardim da Penha", inventory2);
    
    supermarket = InitializeSupermarket("Carone");
    supermarket = CreateSupermarket( branch, supermarket);
    supermarket = CreateSupermarket( branch2, supermarket);

    PrintSupermarket(supermarket);
    return 0;
}

