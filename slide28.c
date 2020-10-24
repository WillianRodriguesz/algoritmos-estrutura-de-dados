#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[30];
	int idade;
	int altura;
} Pessoa;

int main()
{
	int escolha, posicao = 0, cont=2;
	Pessoa *dados;

	dados = (Pessoa*) malloc(sizeof(Pessoa)); // alocando memoria

	while(1){

		printf("Deseja adicionar uma nova pessoa? \n");
		printf("0 - Sim  || Nao - 1 \n ");
		printf("Digite: ");
		scanf("%i", &escolha);
		system("cls");

		if(escolha != 1)
		{
			if (posicao > 0){
				dados = (Pessoa*) realloc(dados, sizeof(Pessoa) * cont);  //realoca espaço na memoria
                cont++;                                                   // contador para alocar +1 
            }
			
			if (!dados){
				printf ("\n Não foi possível adicionar mais nomes MEMORIA INSUFICIENTE!");
				exit(1);
			}
			
			fflush(stdin);                          //limpando buffer
			printf("\nDigite o nome: ");
			scanf("%s", dados[posicao].nome);

			printf("\nDigite a idade: ");
			scanf("%i", &dados[posicao].idade);

			printf("\nDigite a altura: ");
			scanf("%i", &dados[posicao].altura);
			fflush(stdin);
			posicao = posicao + 1;       // posicao incial = 0, toda vez que ela entra na funcao ele conta posicao++ (proxima posicao)

			system("cls");
		}
		if(escolha == 1)
		{
			int i;
			printf("\n--- [ Imprimindo todas as pessoas cadastradas ] --- \n");

			for(i = 0; i < posicao; i++)            // imprimindo todas as posições
			{
				printf("\n---- Dados pessoa %i ----\n\n", i);
				printf("Nome: %s \n", dados[i].nome);
				printf("Idade: %i\n", dados[i].idade);
				printf("Altura: %i\n", dados[i].altura);
			}

			printf("\n --- [ Programa encerrado ! ] ---\n\n");
			free(dados);      // liberando espaço da memoria
			exit(1);
			break;
		}

	}


return 0;
}

