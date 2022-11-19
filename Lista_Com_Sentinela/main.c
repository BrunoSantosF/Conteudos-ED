#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(){

    tLista * list = CriaLista();
    char linha[1000];

    FILE * arquivo = fopen("entradas.txt","r");

    while (!feof(arquivo)){
        fscanf(arquivo,"%[^\n]\n",linha);
        
        char * string = strtok(linha," ");
        while (string){
            InsereNaLista(list,string);
            string = strtok(NULL," ");
        }
        
    }

    fclose(arquivo);
    //imprimindo lista de com os dados
    ImprimiLista(list);

    printf("\n============== Removendo elemento ==============\n");
    RemoveElementoLista(list,"edgar");
    ImprimiLista(list);

    LiberaLista(list);
    
    
    return 0;
}



