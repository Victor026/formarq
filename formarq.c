#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

FILE *conversaoInvert(FILE *caminho, char diretorio[]);
FILE *conversaoUToD(FILE *caminho, char diretorio[]);
FILE *conversaoCript(FILE *caminho, char diretorio[], char *chave);
char somaUm(char caractere);
char *retiraExtensao(char novoDiretorio[]);
char *pegaExtensao(char *diretorio);
char ouExclusivo(char caractere, char chave);

int main(int argc, char *argv[]) {

	FILE *path;
	char *comando;
	char *chave;

	path = fopen(argv[1], "r+b"); //Atribui o caminho do arquivo inserido à variavel path
	comando = argv[2]; //Atribui o segundo argumento ao comando
	chave = argv[3];

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

			default:
				printf("Argumentos inválidos... [I = Invert; U = UNIX to DOS]\n");
		}
	} else {
		if(argc == 4) { //Verifica o comando inserido caso quatro argumentos sejam inseridos
			switch(*comando) {
				case 'C':
					printf("Conversão Cript\n");
					conversaoCript(path, argv[1], chave);
				break;

				default:
					printf("Argumentos inválidos... [C = Cript]\n");
			}
		} else {
			printf("Número de argumentos inválido [2 argumentos para conversão Invert, UNIX e 3 para Cript]\n");
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

	int resultado = strcmp(extensao, ".dos"); //Vê se o extensão é .unx
	if(resultado == 0) {
		strcat(novoDiretorio, ".unx");
		novoArquivo = fopen(novoDiretorio, "w+");
		while(ch != EOF) {
			ch = fgetc(caminho);
			if(ch == '\r') { //Se acha uma quebra de linha DOS
				ch = 00;
				fputc(ch, novoArquivo);
			} else {
				fputc(ch, novoArquivo);
			}
		}
	} else {
		strcat(novoDiretorio, ".dos");
		novoArquivo = fopen(novoDiretorio, "w+");
		while(ch != EOF) {
			ch = fgetc(caminho);
			if(ch == '\n') { //Se acha uma quebra de linha UNIX
				ch = '\r';
				fputc(ch, novoArquivo);
				ch = '\n';
				fputc(ch, novoArquivo);
			} else {
				fputc(ch, novoArquivo);
			}
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

	int resultado = strcmp(extensao, ".inv"); //Vê se o extensão é .inv
	if(resultado == 0) {
		strcat(novoDiretorio, ".dnv");
	} else {
		strcat(novoDiretorio, ".inv");
	}

	novoArquivo = fopen(novoDiretorio, "w+");

	while(ch != EOF) {
		ch = fgetc(caminho);
		fputc(somaUm(ch), novoArquivo); //Faz complemento de um em cada caractere
	}

	if(x != NULL) {
		printf("Novo diretório: %s\n", novoDiretorio);
	} else {
		strcat(novoDiretorio, ".inv");
	}

	return novoArquivo;
}

FILE *conversaoCript(FILE *caminho, char diretorio[], char *chave) {

	char ch;
	char novoDiretorio[strlen(diretorio)+2]; //String do novo arquivo que será criado
	strcpy(novoDiretorio, diretorio);
	FILE *novoArquivo; //Arquivo em si que será criado
	char *x, *extensao;
	int i;

	extensao = pegaExtensao(diretorio);
	x = retiraExtensao(novoDiretorio); //Tira a extensão do arquivo
	strcpy(novoDiretorio, x);

	int resultado = strcmp(extensao, ".crp"); //Vê se o extensão é .crp
	if(resultado == 0) {
		strcat(novoDiretorio, ".drp");
	} else {
		strcat(novoDiretorio, ".crp");
	}

		novoArquivo = fopen(novoDiretorio, "w+"); //Cria o arquivo

	while(ch != EOF) {
		for(i=0; i<strlen(chave); i++) {
			ch = fgetc(caminho);
			fputc(ouExclusivo(ch, chave[i]), novoArquivo);
		}
		i=0;
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

	for(i=0;numero>0;i++) { //Gera o binário do número
	arrayBinario[i]=numero%2;
	numero=numero/2;
	}
	int tamanhoBinario = i;

	for(i=0;i<7;i++) { //Complemento de um
		if(arrayBinario[i] == 0) {
			arrayReverso[i] = 1;
		} else {
			arrayReverso[i] = 0;
		}
	}

	for(i=0;i<7;i++) { //Gera decimal a partir do binário
		numReverso += (arrayReverso[i] * pow(2, i));
	}
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

char ouExclusivo(char caractere, char chave) {

	int i;
	int binCar[7];
	int binChave[7];
	int binOu[7];
	int numCar = (int) caractere;
	int numChave = (int) chave;
	char novoCaractere;
	int numCh = 0;

	for(i=0;i<7;i++) { //Gera o binário do número
	binCar[i]=numCar%2;
	numCar=numCar/2;
	}

	for(i=0;i<7;i++) { //Gera o binário do número
	binChave[i]=numChave%2;
	numChave=numChave/2;
	}

	for(i=0; i<7;i++) { //Ou exclusivo
		if(binCar[i] == binChave[i]) {
			binOu[i] = 1;
		} else {
			binOu[i] = 0;
		}
	}


	for(i=0;i<7;i++) { //Gera decimal a partir do binário
		numCh += (binOu[i] * pow(2, i));
	}
	novoCaractere = (char) numCh;

	return novoCaractere;
}
