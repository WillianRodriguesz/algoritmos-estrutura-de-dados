#include <stdio.h>
#include <stdlib.h>
#include "bibslide28.h"
#include <string.h>

int main (){
    void *pbuffer;
    variavel *p;

    pbuffer = (variavel*) malloc(sizeof(variavel));
    p = pbuffer;
    
    p->cont = 0;
    
    do{
        escolhaMenu(pbuffer);
        
        if(menu(pbuffer) == 1)
            pbuffer = addNome(pbuffer);  //retornando o ponteiro da função 
        
        if(menu(pbuffer) == 2)
            imprimir(pbuffer);
        
        if(menu(pbuffer) == 3)
            buscar(pbuffer);
        
        if(menu(pbuffer) == 4)
            pbuffer = excluir(pbuffer);

        if(menu(pbuffer) == 5){
            printf("\n\n Saindo do programa...\n");
            free(pbuffer);
            exit(1);}
    }while(menu(pbuffer) != 5);

free(pbuffer);
return 0;
}   