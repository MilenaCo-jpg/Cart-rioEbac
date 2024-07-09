#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //criando as funções
{
	setlocale(LC_ALL,"Portuguese");
	
	//Inicio da criação de vartiáveis(string)
	char arquivo[40]; //variável para criar o arquivo que o CPF estará contido. Toda vez que for criar um usuário novo, o arquivo irá mudar, pois sempre serão CPFs diferentes
	char cpf[40]; //criando uma string (o colchete quer dizer que isso é uma string) do tipo 40 para que o usuário posso digitar até 40 caracteres. Criamos com o tipo char porque nesse campo precisaremos digitar caracteres. Obs.: anteriormente estava o printf para que aparecesse uma mensagemm quando o usuário escolhesse a opção 1 do menu
	char nome [40];
	char sobrenome [40];
	char cargo [40]; //a string reserva um espaço na memória,por isso não precisa igualar a zero
	//Final da criação d variáveis
	
	printf("Digite o CPF: ");	//em um banco de dados cada letra precisa ter uma chave primária. Nossa chave será o CPF, pois ele é único para cada pessoa
	scanf("%s", cpf); //armazenando dentro de uma string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores da String (strcpy é una função). Estamos criando o arquivo CPF e para não perguntar ao usuário o valor do CPF duas vezes, vamos copiar o valor da string CPF para o arquivo
	
	FILE *file;				//Criando o arquivo (Procurar nas bibliotecas alguma estrutura file, pois vamos criar o arquivo)| FILE = estamos chamando uma função que já foi criada pelo próprio sistema
	file = fopen(arquivo, "w"); //cria o arquivo. W é de escrever
	fprintf(file, cpf); //salvando no arquivo a variável CPF. O fprintf quer dizer que o código está falando com o programa e não com o usuário.
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar para que ele abra um novo arquivo
	fprintf(file, ","); //colocar uma vírgula entre as informações
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, ","); 
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL,"Portuguese"); //definir a linguagem para cada variável
	
	char cpf[40];
	char conteudo[200]; //criando a variável para conter o arquivo que foi criado no momento do registro
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf); //string é um conjunto de variáveis
	
	FILE *file; //consulte o arquivo
	file = fopen(cpf, "r"); //R para ler o arquivo que estou solicitado
	
	if(file == NULL) //se o arquivo for nulo (não existir). Dois == porque está comparando o arquivo (file) com o CPF (p/verificar se é NULL ou não)
	{
		printf("O CPF não foi localizado \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto o conteúdo estiver dentro do arquivo file e for até 200, o sistema vai busca-lo e traze-lo para o programa. !=null significa que quando não tiver mais conteúdo no arquivo, o sistema pode parar de buscar.
	{
		printf("Essas são as informações do usuário: \n");
		printf("%s", conteudo); //mostrando o conteúdo para o usuário
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuário não identificado\n");
		system("pause");
		
	}
	
}
	
int main()
{
	int opcao=0;	//Definindo variáveis(sempre colocar uo valor 0 na variável para que ela não fique com um valor variável de memória. Também serve para avisar ao computador que essa variável  não está livre, que ela é nossa.
	int x=1;
	
	for(x=1;x=1;) //Nesse caso, eu só preciso que o for sempre volte para o 1 (menu)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

		printf("\tCartório da Ebac\t\n\n");	//inicio do menu
		printf("Escolha a opção desejada no menu abaixo:\n\n");
		printf("1 - Registrar nomes\n");
		printf("2 - Consultar nomes\n");
		printf("3 - Deletar nomes\n");
		printf("4 - Sair do sistema\n\n");
		printf("Insira a opção desejada: "); //final do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usuário
	
		system("cls");  //o CLS tem como função limpar a tela
	
	
		switch(opcao) //inicio da seleção do menu
		{
			case 1:
			registro(); //Chamando a função
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Opção indisponível. Por favor digite novamente\n");
			system("pause");
			break;	
		}
}

} //Fim da seleção

