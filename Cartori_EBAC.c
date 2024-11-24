#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //bibliote de aloca��es de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o por cadastrar os usu�rios no sistema
{
	//in�cio de cria��o de vari�veis/string
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final de cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //fun��o para abrir o arquivo e "a" para atualizar 
	fprintf(file,","); //"," salva a nova fun��o
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
	
	system("pause"); //Para o sistema e aguarda a resposta do usu�rio
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL) //fun��o para saber se � verdadeira ou n�o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
}



int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Definindo vari�veis
	
	for (laco=1;laco=1;) //for = se
	{
	
	system("cls"); //respons�vel por limpar a tela
	setlocale(LC_ALL, "Portuguese"); //Definindo a Linguagem
	
	printf("\t~ ~ ~ Cart�rio da EBAC ~ ~ ~\n\n"); //In�cio do Menu
	printf("Escolha a op��o deseja no menu: \n\n");
	printf("\t1 Registrar nomes \n");
	printf("\t2 Consultar nomes \n");
	printf("\t3 Deletar nomes \n"); 
	printf("\t4 Sair do Sistema \n\n");
	printf("Op��o: "); //Fim do Menu
	
	scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	system("cls");
	
	switch(opcao) //In�cio da sele��o do usu�rio
	{
		case 1: //fu��o para escolha do usu�rio (1,2,3,4,5,6... etc.)
		registro(); //chamada de fun��es
		break; //fun��o para encerrar o loop
		
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
		printf("Essa op��o n�o est� dispon�vel.\n\n");
		system("pause");
		break;
		//Fim da sele��o do usu�rio
	}	
}
}
