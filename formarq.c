#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


FILE *conversaoInvert(FILE *caminho, char diretorio[]);
FILE *conversaoUToD(FILE *caminho, char diretorio[]);
//FILE *conversaoDToU(FILE *caminho);
//FILE *conversaoCript(FILE *caminho);
char somaUm(char caractere);
char *retiraExtensao(char novoDiretorio[]); //Função que tira a extensão de um arquivo
char *pegaExtensao(char *diretorio);

int main(int argc, char *argv[]) {

	FILE *path;
	char* comando;

	path = fopen(argv[1], "r+b"); //Atribui o caminho do arquivo inserido à variavel path
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
				conversaoUToD(path, argv[1]);
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

FILE *conversaoUToD(FILE *caminho, char diretorio[]) {

	char ch;
	char novoDiretorio[strlen(diretorio)+2]; //String do novo arquivo que será criado
	strcpy(novoDiretorio, diretorio);
	FILE *novoArquivo; //Arquivo em si que será criado
	char *x, *extensao;
	int i;

	extensao = pegaExtensao(diretorio);
	x = retiraExtensao(novoDiretorio); //Tira a extensão do arquivo
	strcpy(novoDiretorio, x);
	printf("%s\n", extensao);

	int resultado = strcmp(extensao, ".unx"); //Vê se o extensão é .unx
	if(resultado == 0) {
		strcat(novoDiretorio, ".dos");
	} else {
		printf("Formato de arquivo inválido! (Insira um arquivo .unx)\n");
		exit(0);
	}

	novoArquivo = fopen(novoDiretorio, "w+");

	while(ch != EOF) {
		ch = fgetc(caminho);
		printf("%c", ch);
		if(ch == '\n') {
			printf("\nAchei uma quebra de linha!\n" );
			ch = '\r';
			fputc(ch, novoArquivo);
			ch = '\n';
			fputc(ch, novoArquivo);
		} else {
			fputc(ch, novoArquivo);
		}
	}

	return novoArquivo;
}

FILE *conversaoInvert(FILE *caminho, char diretorio[]) {

	char ch;
	char novoDiretorio[strlen(diretorio)+2]; //String do novo arquivo que será criado
	strcpy(novoDiretorio, diretorio);
	FILE *novoArquivo; //Arquivo em si que será criado
	char *x, *extensao;
	int i;

	extensao = pegaExtensao(diretorio);
	x = retiraExtensao(novoDiretorio); //Tira a extensão do arquivo
	strcpy(novoDiretorio, x);
	printf("%s\n", extensao);

	int resultado = strcmp(extensao, ".inv"); //Vê se o extensão é .inv
	if(resultado == 0) {
		strcat(novoDiretorio, ".dnv");
	} else {
		strcat(novoDiretorio, ".inv");
	}

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
	int arrayBinario[7] = {0};
	int arrayReverso[7]	 = {1};
	int i = 0;
  char reverso;
	float numReverso = 0;

	printf("Caractere: %c\n", caractere);
	printf("Número em decimal: %d\n", numero);
	for(i=0;numero>0;i++) { //Gera o binário do número
	arrayBinario[i]=numero%2;
	numero=numero/2;
	}
	int tamanhoBinario = i;
	printf("Número em binário: ");
	for(i=6;i>=0; i--) {
		printf("%d", arrayBinario[i]);
	}
	printf("\n");

	for(i=0;i<7;i++) { //Soma um no binário
		if(arrayBinario[i] == 0) {
			arrayReverso[i] = 1;
		} else {
			arrayReverso[i] = 0;
		}
	}

	printf("Número binário reverso: ");
	for(i=6;i>=0; i--) {
		printf("%d", arrayReverso[i]);
	}
	printf("\n");

	for(i=0;i<7;i++) {
		numReverso += (arrayReverso[i] * pow(2, i));
	}
	printf("Número decimal reverso: %d\n", (int) numReverso);
	reverso = (char) numReverso;

	return reverso;
}

char *retiraExtensao(char novoDiretorio[]) {

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

char *pegaExtensao(char *diretorio) {

	int i;
	char *extensao;

	for(i=strlen(diretorio)-1; i>0; i--){ //Verifica se tem um ponto e atribui a extensão na variável extensao
		if(diretorio[i] == '.') {
			extensao = diretorio + i;
			break;
		} else {
			extensao = NULL;
		}
	}

return extensao;
}
