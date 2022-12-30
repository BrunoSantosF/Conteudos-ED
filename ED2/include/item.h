#ifndef ITEM_H
#define ITEM_H

typedef struct item tItem;

tItem * CreateItem(char * product , float value ,int amount);
char * ReturnProduct(tItem * item);
int AmountItem(tItem * item);
float ReturnValue(tItem * item);
void PrintItens(tItem * item);
void FreeItem(tItem * item);


#endif