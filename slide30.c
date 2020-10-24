#include <stdio.h>
#include <stdlib.h>
#include "biblioteca30.h"

int main (){
    int escolha, m, n;
    int **matriz, *vetor;


    do{
        escolha = menu();

        if(escolha==1){
            printf("Digite o numero de linhas: ");
            scanf("%i", &m);
            printf("Digite o numero de colunas: ");
            scanf("%i", &n);
     
            matriz = criaMatriz(m, n);
        }

        if(escolha==2){
            leiaMatriz(matriz, m, n);
        }
        if(escolha==3){
            printf("\n A som de todos os elemntos = %i\n", somaMatriz(matriz, m, n));
            system("pause");
        }

        if(escolha==4){
            vetor = geraVetor(matriz, vetor, m, n);
            imprimeVetor(vetor, m);
        }

        if(escolha==5){
            imprimeMatriz(matriz, m, n);
        }

        if(escolha == 6){
            printf("\nSaindo do programa...\n");
            printf("\n\n");
            liberarMatriz(matriz, m);
            free(vetor);
            exit(1);
        }
    
    }while(escolha != 6);

return 0;    
}