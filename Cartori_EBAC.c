#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //bibliote de alocações de textos por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função por cadastrar os usuários no sistema
{
	//início de criação de variáveis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //função para abrir o arquivo e "a" para atualizar 
	fprintf(file,","); //"," salva a nova função
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
 	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //Para o sistema e aguarda a resposta do usuário
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL) //função para saber se é verdadeira ou não
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Definindo variáveis
	
	for (laco=1;laco=1;) //for = se
	{
	
	system("cls"); //responsável por limpar a tela
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	printf("\t~ ~ ~ Cartório da EBAC ~ ~ ~\n\n"); //Início do Menu
	printf("Escolha a opção deseja no menu: \n\n");
	printf("\t1 Registrar nomes \n");
	printf("\t2 Consultar nomes \n");
	printf("\t3 Deletar nomes \n"); 
	printf("\t4 Sair do Sistema \n\n");
	printf("Opção: "); //Fim do Menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usuário
	system("cls");
	
	switch(opcao) //Início da seleção do usuário
	{
		case 1: //fução para escolha do usuário (1,2,3,4,5,6... etc.)
		registro(); //chamada de funções
		break; //função para encerrar o loop
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!");
		return 0; //Retorna o valor a 0/ fecha o sistema
		break;
		
		default:
		printf("Essa opção não está disponível.\n\n");
		system("pause");
		break;
		//Fim da seleção do usuário
	}	
}
}
