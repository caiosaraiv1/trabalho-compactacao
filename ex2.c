#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decompressingString(char *input, char *output)
{
    int indiceInicio = 0;
    int indiceFim = 0;
    int i = 0;
    int tamString = 0;

    char aSerCopiado[1] = {0};    // Cria  o espaço pro caractere a ser reproduzido
    int valorASerReproduzido = 0; // cria esoaço pr numero de vzs a ser reproduzido

    // saber tamanho String
    while (input[i] != "\0"){
        tamString++;
    }

    // Dividir a string em pedaços separados por "-"
    while (input[i] != "-"){
        indiceFim++;
    }

    char aSerCopiado = input[0];

    // Copiar o char pro output
    for (int j = 0; j < tamString; j++){
        output[j] = aSerCopiado;
    }
}

int main(){
    char *input[255] = {0};
    char *output[255] = {0};

    printf("Digite uma string para ser descompactada: ");
    fgets(input, 255, stdin);           // Lê a string de entrada
    input[strcspn(input, "\n")] = '\0'; // Remove o caractere de nova linha do final da string, se houver

    decompressingString(input, output);
    printf(output);
}