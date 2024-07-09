#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //criando as fun��es
{
	setlocale(LC_ALL,"Portuguese");
	
	//Inicio da cria��o de varti�veis(string)
	char arquivo[40]; //vari�vel para criar o arquivo que o CPF estar� contido. Toda vez que for criar um usu�rio novo, o arquivo ir� mudar, pois sempre ser�o CPFs diferentes
	char cpf[40]; //criando uma string (o colchete quer dizer que isso � uma string) do tipo 40 para que o usu�rio posso digitar at� 40 caracteres. Criamos com o tipo char porque nesse campo precisaremos digitar caracteres. Obs.: anteriormente estava o printf para que aparecesse uma mensagemm quando o usu�rio escolhesse a op��o 1 do menu
	char nome [40];
	char sobrenome [40];
	char cargo [40]; //a string reserva um espa�o na mem�ria,por isso n�o precisa igualar a zero
	//Final da cria��o d vari�veis
	
	printf("Digite o CPF: ");	//em um banco de dados cada letra precisa ter uma chave prim�ria. Nossa chave ser� o CPF, pois ele � �nico para cada pessoa
	scanf("%s", cpf); //armazenando dentro de uma string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores da String (strcpy � una fun��o). Estamos criando o arquivo CPF e para n�o perguntar ao usu�rio o valor do CPF duas vezes, vamos copiar o valor da string CPF para o arquivo
	
	FILE *file;				//Criando o arquivo (Procurar nas bibliotecas alguma estrutura file, pois vamos criar o arquivo)| FILE = estamos chamando uma fun��o que j� foi criada pelo pr�prio sistema
	file = fopen(arquivo, "w"); //cria o arquivo. W � de escrever
	fprintf(file, cpf); //salvando no arquivo a vari�vel CPF. O fprintf quer dizer que o c�digo est� falando com o programa e n�o com o usu�rio.
	fclose(file); //fechando o arquivo
	
	file = fopen(arquivo, "a"); //a de atualizar para que ele abra um novo arquivo
	fprintf(file, ","); //colocar uma v�rgula entre as informa��es
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
	setlocale(LC_ALL,"Portuguese"); //definir a linguagem para cada vari�vel
	
	char cpf[40];
	char conteudo[200]; //criando a vari�vel para conter o arquivo que foi criado no momento do registro
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf); //string � um conjunto de vari�veis
	
	FILE *file; //consulte o arquivo
	file = fopen(cpf, "r"); //R para ler o arquivo que estou solicitado
	
	if(file == NULL) //se o arquivo for nulo (n�o existir). Dois == porque est� comparando o arquivo (file) com o CPF (p/verificar se � NULL ou n�o)
	{
		printf("O CPF n�o foi localizado \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto o conte�do estiver dentro do arquivo file e for at� 200, o sistema vai busca-lo e traze-lo para o programa. !=null significa que quando n�o tiver mais conte�do no arquivo, o sistema pode parar de buscar.
	{
		printf("Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo); //mostrando o conte�do para o usu�rio
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
		printf("Usu�rio n�o identificado\n");
		system("pause");
		
	}
	
}
	
int main()
{
	int opcao=0;	//Definindo vari�veis(sempre colocar uo valor 0 na vari�vel para que ela n�o fique com um valor vari�vel de mem�ria. Tamb�m serve para avisar ao computador que essa vari�vel  n�o est� livre, que ela � nossa.
	int x=1;
	
	for(x=1;x=1;) //Nesse caso, eu s� preciso que o for sempre volte para o 1 (menu)
	{
		system("cls");
		
		setlocale(LC_ALL,"Portuguese"); //Definindo a linguagem

		printf("\tCart�rio da Ebac\t\n\n");	//inicio do menu
		printf("Escolha a op��o desejada no menu abaixo:\n\n");
		printf("1 - Registrar nomes\n");
		printf("2 - Consultar nomes\n");
		printf("3 - Deletar nomes\n");
		printf("4 - Sair do sistema\n\n");
		printf("Insira a op��o desejada: "); //final do menu
	
		scanf("%d" , &opcao); //armazenando a escolha do usu�rio
	
		system("cls");  //o CLS tem como fun��o limpar a tela
	
	
		switch(opcao) //inicio da sele��o do menu
		{
			case 1:
			registro(); //Chamando a fun��o
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
			printf("Op��o indispon�vel. Por favor digite novamente\n");
			system("pause");
			break;	
		}
}

} //Fim da sele��o

