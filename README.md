** -------------- BEM VINDO AO PROGRAMA FORMARQ -------------- **

** PARA QUE SERVE **

O Formarq foi desenvolvido com propósitos múltiplos:

CRIPTOGRAFIA
Formarq é capaz de criptografar arquivos usando criptografia INVERT ou CRIPT.

CONVERSÃO DE ARQUIVOS TEXTO ENTRE UNIX E DOS
Também é possível converter arquivos com quebra de linha CR (sistema UNIX) para LF/CR (sistema DOS) e vice-versa.

** COMO FUNCIONA **

CRIPTOGRAFIA INVERT
Esta criptografia usa o sistema de "complemento de um" para criptografar o arquivo.
Após a conversão será gerado um arquivo com o mesmo nome do original porém com extensão .inv e com o conteúdo criptografado.
Quando o arquivo com extensão .inv for criptografado novamente será gerado um arquivo .dnv com o conteúdo do arquivo original.

CRIPTOGRAFIA CRIPT
Já esta criptografia usa o sistema de "ou exclusivo" entre o arquivo e um chave que será passada pelo usuário.
Após a conversão será gerado um arquivo com o mesmo nome do original porém com extensão .crp e com o conteúdo criptografado.
Quando o arquivo com extensão .crp for criptografado novamente será gerado um arquivo .drp com o conteúdo do arquivo original.

CONVERSÃO UNIX TO DOS
Esta conversão gerará um arquivo .dos com o sistema DOS de quebra de linha (LF/CR).
Quando o arquivo com extensão .dos é convertido novamente, será gerado um arquivo com extensão .unx que voltará a ter o sistema UNIX de qubra de linha (CR).

** COMO UTILIZAR **

O programa exige alguns argumentos que serão passados no terminal, sendo eles:
Primeiro argumento: Script do formarq. (./formarq)
Segundo argumento: Caminho do arquivo a ser modificado. (Ex.: ~/Documentos/teste.txt)
Terceiro argumento: Comando a ser executado. (C para CRIPT, U para UNIX to DOS, I para INVERT).
Quarto argumento: Somente usado na conversão CRIPT, será colocado a chave para a conversão.

Exemplos:
./formarq ~/Documentos/teste.txt I fará a criptografia INVERT no arquivo teste.txt.

./formarq ~/Documentos/teste.txt C MORANGO fará a criptografia CRIPT no arquivo teste.txt usando a chave MORANGO.

