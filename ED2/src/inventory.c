#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/item.h"
#include "../include/inventory.h"

struct inventory{
    float value; //valor de todos os itens do estoque
    tItem * item; // conteudo da lista
    tInventory * next; //proximo celula da lista
};

tInventory * InitializeInventory(){
    return NULL;
}

tInventory * CreateInventory(tInventory * inventory , tItem * item){
    tInventory * Inventory = malloc(sizeof(tInventory));
    Inventory->item = item;
    Inventory->next = inventory;
    Inventory->value = AmountItem(item);

    return Inventory;
}

float ReturnValueInventory(tInventory * inventory){
    float sum = 0;
    tInventory * assistant = inventory;

    for (assistant; assistant != NULL ;assistant = assistant->next){
        sum += AmountItem(assistant->item) * ReturnValue(assistant->item);
    }
    
    return sum;
}

void PrintInventory(tInventory * inventory){
    tInventory * assistant = inventory;
    
    printf("       Inventory: %.2f\n",ReturnValueInventory(inventory));
    for (assistant; assistant != NULL ;assistant = assistant->next){
        PrintItens(assistant->item);
    } 

}
