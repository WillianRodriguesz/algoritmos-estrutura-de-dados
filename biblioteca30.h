int menu(){
    int i;
    do{
    system("cls");
    printf("\n----------------- [ Menu ] -----------------\n");
    printf("\n [1] - Criar e redimencionar uma matriz");
    printf("\n [2] - Realizar leitura dos elementos");
    printf("\n [3] - Fornecer a soma dos elementos da matriz");
    printf("\n [4] - Retornar em um vetor os elementos de uma coluna");
    printf("\n [5] - Imprimir a matriz");
    printf("\n [6] - Sair do programa\n");
    printf("\n--------------------------------------------\n");
    printf("   DIGITE: ");
    scanf("%i", &i);
    
    }while(i<0 || i>6);
    
    return i;
}

int** criaMatriz (int m, int n){
    int i;
    int **matriz;
    
    matriz = (int**) malloc (m*sizeof(int*));
    
    for(i=0; i<m; i++){
        matriz[i] = (int*) malloc (n*sizeof(int));
    }

    return matriz;
}

void leiaMatriz (int **matriz, int linha, int coluna){
    int i, j;
    system("cls");
    for(i=0; i<linha ;i++){
        for(j=0; j<coluna; j++){
            printf("\nDigite posicao linha [%i]| coluna [%i] = ", i, j);
            scanf("%i", &matriz[i][j]);
            fflush(stdin);
        }
    }

}

void imprimeMatriz (int **matriz, int linha, int coluna){
    int i, j;
    system("cls");
    printf("\n ---- [IMPRIMINDO MATRIZ COMPLETA] ---\n");
    for(i=0; i<linha ;i++){
        for(j=0; j<coluna; j++){
            printf("%i ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n --------- [MATRIZ IMPRIMIDA] --------\n");
    system("pause");
}

void liberarMatriz (int **matriz, int linha){
    int i;

    for(i=0; i<linha; i++)
        free(matriz[i]);
    
    free(matriz);
}

int somaMatriz(int **matriz, int linha, int coluna){
    int i, j, soma=0;
    system("cls");
    for(i=0;i<linha;i++){
        for(j=0; j<coluna; j++){
            soma = soma + matriz[i][j];
        }
    }
    return soma;
}

void* geraVetor(int **matriz, int *vetor, int linha, int coluna){
    int i, j, aux;
    system("cls");
    vetor= (int*) malloc (linha*sizeof(int));
    
    do{
    printf("\n Digite a coluna que deseja imprimir 0 ate %i: ", coluna-1);
    scanf("%i", &aux);
     }while(aux<0 || aux>(coluna-1));

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++){
            if(aux==j)
                vetor[i] = matriz[i][j];
        }
    }
    return vetor;
}

void imprimeVetor (int *vetor, int linha){
    int i;

    printf("\n Vetor ");
    for(i=0; i<linha; i++)
        printf("[%i] ", vetor[i]);

    printf("\n");
    system("pause");
    system("cls");
}