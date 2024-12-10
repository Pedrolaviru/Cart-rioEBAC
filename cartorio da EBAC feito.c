#include <stdio.h>  // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca para suporte de localiza��o
#include <string.h> // Biblioteca respons�vel por cuidar das string


int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings 
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome ao ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	 	 
	
}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
			printf("Nao foi possivel abrir o arquivo, nao localizado!. \n");

	}
	
	while(fgets(conteudo, 200, file )!=NULL)
	{
		printf("\n Essas sao as informacoes do usuario: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
		system("pause");
		
	
	
	}
	


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuario a ser deletado: ");
	scanf ("%s",cpf);
	
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!.\n");
		system("pause");
		
	}	
	
	
	
}

int main() {
    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    int opcao = 0; // 
    int x = 1;

    for (x = 1; x <= 10; x++) { // 
        system("cls"); // 

        // Exibi��o do menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada no menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("Op��o: ");

        scanf("%d", &opcao); // 

        system("cls"); // 

        switch (opcao) {
            case 1:
                registro();
                system("pause");
                break;

            case 2:
                consulta();
                system("pause");
                break;

            case 3:
                deletar();
                system("pause");
                break;

            default:
                printf("Essa op��o n�o est� dispon�vel.\n");
                system("pause");
                break;
        }
    }

    return 0; // Fim do programa
}

