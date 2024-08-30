#include <stdio.h> //biblioteca de comunicacão com o usuario
#include <stdlib.h> //biblioteca de alocacão de especo em memoria
#include <locale.h> //biblioteca de alocacão de texto por região
#include <string.h> //biblioteca responsável por cuidar das string
int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO Arquivo não foi localizado\n\n");
	}
	
	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações cadastradas: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
} 

int deletar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(fgets(conteudo, 200, file))
	{
		remove(cpf);
		printf(" Usuário deletado do sistema\n\n");
		system("pause");
	}
	
	while(file == NULL)
	{
		printf(" Não foi possivel localizar o usuário no sistema\n\n");
		system("pause");
		break;
	}
}


	

int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;) 
	{

		system("cls");
		
  		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("~~~ Cartório ~~~\n\n"); //inicio do menu
		printf("Escolha a opção desejada:\n\n");
		printf("\t1- Novo Registro\n");
		printf("\t2- Consultar Registro\n");
		printf("\t3- Deletar Registro\n");
		printf("\t4- Sair do sistema\n\n");//fim do menu
		printf("Opção: "); 
	
		scanf("%d", &opcao);//armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
					
			default:
			printf("Essa opção não está  disponível");
			system("pause");
			break;
		}
}
}
