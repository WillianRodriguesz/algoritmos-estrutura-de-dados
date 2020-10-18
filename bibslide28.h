#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pause();

typedef struct{
    char nome[20];          //struct dos nomes
}dados;

typedef struct{
    int i, j, escolha, cont, aux; //struct das variaveis
    char auxnome[20];
}variavel;

void escolhaMenu(void *pbuffer){
    variavel *p;        // criando ponteiro
    p = pbuffer;        //passando ponteiro pbuffer
    system("cls || clear");
    printf("--- [ Menu ] ---\n");
    printf("[1] - Inserir nome \n");
    printf("[2] - Listar nome \n");
    printf("[3] - Procurar nome \n");
    printf("[4] - Exclui nome \n");
    printf("[5] - Sair do programa\n");
    printf("Digite: ");
    scanf("%i", &p->escolha);
    fflush(stdin);
    printf("\n");

    system("cls || clear"); 
}

int menu(void *pbuffer){
    variavel *p;        // está função apenas pega o endereço da escolha, ou seja o conteudo de escolha 
    p = pbuffer;        

    return p->escolha;
}

variavel* addNome(void *pbuffer){
    variavel *p;    // declarando ponteiro das variaveis
    dados *pessoa; // declarando ponteiro do nome

	p = pbuffer;      // pbuffer = [variavel] + [dados até o momento] + [contador(pessoas)], ou seja alloca +1 pessoa no final da struct nome
	pbuffer = realloc (pbuffer, sizeof(variavel)+sizeof(dados)+(p->cont) * sizeof (dados)); // realocando memoria depois do tamanho da struct variavel
    if(pbuffer == NULL){
        printf("\n Não foi possivel adicionar um nome!");   // verificando se é possivel aloca memoria
        exit(1);
    }

    p = pbuffer;    // passando ponteiro do pbuffer p/ p
    pessoa = pbuffer + sizeof(variavel) + (p->cont * sizeof(dados)); // passando o endereço do proximo espaço valido 

    printf("Digite o nome que deseja adicionar: ");
    fflush(stdin);
    fgets (pessoa->nome, 20, stdin);
   
    p->cont++;  // contador do numero de pessoas
    return p;
}

void imprimir (void *pbuffer){
    variavel *p;
    dados *pessoa;
    
    p = pbuffer;
    pessoa = pbuffer + sizeof(variavel);  // endereço de memoria onde começa os nomes
    system("cls || clear");
    printf("--- [Imprimindo nomes] ---\n");
    for(p->i=0; p->i < p->cont; p->i++){ // imprimi até o numero de pessoas ser igual ao i
        printf("%s", pessoa->nome);
        pessoa++;                         // Pula pro proximo endereço da struct (proximo)
    }
    printf("--- [Nomes imprimidos] ---\n");
    pause();
}

void buscar (void *pbuffer){
    variavel *p;
    dados *pessoa;

    p = pbuffer;
    pessoa = pbuffer + sizeof(variavel);            // posicao do ponteiro inicial onde começa os nomes 
    printf("--- [ Procurando na lista ] --- ");
    printf("\nDigite o nome que deseja procurar na lista: ");
    fgets(p->auxnome, 20, stdin);
    fflush(stdin);
    p->j=0;

    for(p->i=0; p->i < p->cont; p->i++){
        if(strcmp(p->auxnome, pessoa->nome) == 0){
            printf("\nNome encontrado na lista: %s\n", p->auxnome);
            p->j++;  // se contador = 0,  não entrar nesse if, logo o nome não esta na lista
            break;
        }else
            pessoa++;
    }   
    
    if(p->j == 0) // verifica contador 
        printf("\n--- [ Nome nao esta na lista!! ] ---\n\n");

    pause();

}

variavel* excluir(void* pbuffer){
    variavel *p;
    dados *pessoa, *pessoaProxima;
    p = pbuffer;
    pessoa = pbuffer + sizeof(variavel);

    printf("\nDigite o nome que deseja excluir: ");
    fgets(p->auxnome, 20, stdin);
    fflush(stdin);
    p->j=0;
    p->aux=0;

    for(p->i=0; p->i < p->cont; p->i++){
        if(strcmp(p->auxnome, pessoa->nome) == 0){
            printf("\nNome encontrado na lista: %s\n", p->auxnome);
            p->j=p->i;           // recebe a posicao da pessoa removida
            p->aux++;           //aux = 0 não entrar no if, nome não está na lista
            break;
        }else
            pessoa++;  //proxima posição
    }   

    if(p->aux == 0){    //verifica linha 122
        printf("\n--- [ Nome nao esta na lista!! ] ---\n");
        exit(1);
    }
   system("pause");

    pessoa = pbuffer + sizeof(variavel) + (p->j *sizeof(dados)); //passa endereço de memoria apartir da posicao do nome que a pessoa quer remover

    while(p->j < p->cont){
        pessoaProxima = pbuffer + sizeof(variavel) + ((p->j+1) * sizeof(dados)); // pega o endereço do proximo nome
        strcpy (pessoa->nome, pessoaProxima->nome); //copia o proximo nome, para o atual
        p->j++; // proxima posiçao do contador
        pessoa++; // proxima posicao da struct pessoa.nome
    }

    p->cont--; //remove uma pessoa do contador
    pbuffer = realloc (pbuffer, sizeof(variavel) + sizeof(dados) + p->cont * sizeof(dados)); // realoca memoria com o tamanho do novo contador de pessoas

    return pbuffer; // retorna o endereço de memoria do pbuffer
}

void pause(){
    printf("Pressione enter para continuar!");      // pause criado para windows e linux
    getchar();
    fflush(stdin);
    return;
}
void sleep(int segundos);
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif