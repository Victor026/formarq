#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *conversaoInvert(FILE *caminho, char diretorio[]);
//FILE *conversaoUToD(FILE *caminho);
//FILE *conversaoDToU(FILE *caminho);
//FILE *conversaoCript(FILE *caminho);
char somaUm(char caractere);
char *ext(char novoDiretorio[]); //Função que tira a extensão de um arquivo

int main(int argc, char *argv[]) {

	FILE *path;
	char* comando;

	path = fopen(argv[1], "r+"); //Atribui o caminho do arquivo inserido à variavel path
	comando = argv[2]; //Atribui o segundo argumento ao comando

	if(path == NULL) {
		printf("Caminho inexistente!\n");
	} else {
		if(argc == 3) {
		switch(*comando) { //Verifica o comando inserido caso três argumentos sejam inseridos
			case 'I':
				printf("Conversão Invert\n");
				conversaoInvert(path, argv[1]);
			break;

			case 'U':
				printf("Conversão U to D\n");
				//conversaoUToD(path);
			break;

			case 'D':
				printf("Conversão D to U\n");
				//conversaoDToU(path);
			break;

			default:
				printf("Argumentos inválidos... [I = Invert; U = UNIX to DOS; D = DOS to UNIX]\n");
		}
	} else {
		if(argc == 4) { //Verifica o comando inserido caso quatro argumentos sejam inseridos
			switch(*comando) {
				case 'C':
					printf("Conversão Cript\n");
					//conversaoCript(path);
				break;

				default:
					printf("Argumentos inválidos... [C = Cript]\n");
			}
		}
	}
	}

	return 0;
}


FILE *conversaoInvert(FILE *caminho, char diretorio[]) {

	char ch;
	char novoDiretorio[strlen(diretorio)+2]; //String do novo arquivo que será criado
	strcpy(novoDiretorio, diretorio);
	FILE *novoArquivo; //Arquivo em si que será criado
	char *x;
	int i;

	x = ext(novoDiretorio); //Tira a extensão do arquivo
	strcpy(novoDiretorio, x);
	strcat(novoDiretorio, ".inv");

	novoArquivo = fopen(novoDiretorio, "w+");

	while(ch != EOF) {
		ch = fgetc(caminho);
		fputc(somaUm(ch), novoArquivo);
	}

	if(x != NULL) {
		printf("Novo diretório: %s\n", novoDiretorio);
	} else {
		strcat(novoDiretorio, ".inv");
	}

	return novoArquivo;
}

char somaUm(char caractere) {

	int numero = (int) caractere;
	int arrayBinario[10];
	int arrayReverso[10];
	int i = 0;
  char reverso;
	float numReverso = 0;

	for(i=0;numero>0;i++) {
	arrayBinario[i]=numero%2;
	numero=numero/2;
	}

	for(i=0;i<(sizeof(arrayBinario) / sizeof(int));i++) {
		if(arrayBinario[i] == 0) {
			arrayReverso[i] = 1;
		} else {
			arrayReverso[i] = 0;
		}
	}

	for(i=(sizeof(arrayBinario) / sizeof(int))-1;i>=0;i--) {
		numReverso += arrayReverso[i] * pow(2, i);
	}

	reverso = (char) numReverso;

	return reverso;
}


char *ext(char novoDiretorio[]) {
int i;
char *x;
for(i = strlen(novoDiretorio)-1; i && novoDiretorio[i] != "."; i--) { //Loop desde o último caractere até o primeiro
	if(novoDiretorio[i] == '.') { //Caso ele ache um ponto
		novoDiretorio[i] = '\0';  //Corta a string
	} else {
		x = novoDiretorio;
	}
}

return novoDiretorio;
}
