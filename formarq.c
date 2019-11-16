#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *conversaoInvert(FILE *caminho, char diretorio[]);
//FILE *conversaoUToD(FILE *caminho);
//FILE *conversaoDToU(FILE *caminho);
//FILE *conversaoCript(FILE *caminho);
int somaUm(char ch);
char *ext(char novoCaminho[]);

int main(int argc, char *argv[]) {

	FILE *path;
	char* comando;

	path = fopen(argv[1], "r+");
	comando = argv[2];

	if(path == NULL) {
		printf("Caminho inexistente!\n");
	} else {
		if(argc == 3) {
		switch(*comando) {
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
		if(argc == 4) {
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

	char caractere;
	char novoDiretorio[strlen(diretorio)+2];
	strcpy(novoDiretorio, diretorio);
	FILE *novoArquivo;
	char *x;
	int i;

	printf("Novo diretório: %s\n", novoDiretorio);

	while(caractere = fgetc(caminho) != EOF) {
		fputc(somaUm(caractere), novoArquivo);
	}

	return novoArquivo;
}

int somaUm(char ch) {
	int chSomaUm;

	return chSomaUm;
}
