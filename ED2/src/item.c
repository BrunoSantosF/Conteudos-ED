#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/item.h"

struct item {
    int amount; //quantidade de produtos
    char * product; //nome do produto
    float value; //valor do produto
};

tItem * CreateItem(char * product , float value ,int amount){
    tItem * item = malloc(sizeof(tItem));
    item->amount = amount;
    item->product = strdup(product);
    item->value = value;

    return item;
}

char * ReturnProduct(tItem * item){
    return item->product;
}

int AmountItem(tItem * item){
    return item->amount;
}

float ReturnValue(tItem * item){
    return item->value;
}

void PrintItens(tItem * item){
    printf("          itens: %s, price:%.2f, amount:%d \n", item->product,item->value,item->amount);
}

void FreeItem(tItem * item){
    free(item->product);
    free(item);
}


