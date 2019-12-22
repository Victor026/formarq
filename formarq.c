#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void fileCript(FILE *file, char *new_dir_path, char *key);
char *changeExtension(char *dir_path);

int main(int argc, char *argv[]) {

  char *dir_path, *key, *new_dir_path;
  dir_path = (char *) malloc(sizeof(char) * MAX);
  new_dir_path = (char *) malloc(sizeof(char) * MAX);
  key = (char *) malloc(sizeof(char) * MAX);
  FILE *f;

  /* Copy user inputs into file path and key */
  strcpy(dir_path, argv[1]);
  strcpy(key, argv[2]);

  f = fopen(dir_path, "r");

  /* If the file exists change the extension and encrypt the file */
  if(!f)
    printf("The path does not exist!\n"), exit(0);
  else
    new_dir_path = changeExtension(dir_path), fileCript(f, new_dir_path, key);

  return 0;
}

/* Change the extension of a given file*/
char *changeExtension(char *dir_path) {

  char *extension, *new_dir_path;

  new_dir_path = (char *) malloc(sizeof(char) * MAX);
  extension = (char *) malloc(sizeof(char) * MAX);

  int i;
  for(i = strlen(dir_path)-1; i > 0; i--) {
    if(dir_path[i] == '.') {
      strcpy(extension, dir_path+i);
      dir_path[i] = '\0';
      break;
    } else {
      ;
    }
  }

  if(strcmp(extension, ".crp") == 0)
    strcat(dir_path, ".drp"), strcpy(new_dir_path, dir_path);
  else
    strcat(dir_path, ".crp"), strcpy(new_dir_path, dir_path);

  return new_dir_path;
}

/* Encrypt the file using exclusive or */
void fileCript(FILE *file, char *new_dir_path, char *key) {

  FILE *new_f;
  new_f = fopen(new_dir_path, "w+");
  int ch, i;

  while((ch = getc(file)) != EOF) {
    fputc(ch ^ key[0], new_f);
    for(i=1; i<strlen(key); i++)
      if((ch = getc(file)) == EOF)
        break;
      else
        fputc(ch ^ key[i], new_f);
  }

  fclose(file);
  rewind(new_f);
}
