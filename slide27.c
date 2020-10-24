#include <stdio.h>
#include <stdlib.h>

void* realocaMem(int *origem, int *tamanho){
    int *destino, i;
    destino = (int*) malloc ((*tamanho) *sizeof(int));

    memcpy(destino, origem, sizeof(origem));

    free(origem);
    return destino;
} 

int main(){
    int *origem, tamanho=20;
    origem = (int*) malloc(sizeof(int));

    origem = realocaMem(origem, &tamanho);
    free(origem);

return 0;    
}