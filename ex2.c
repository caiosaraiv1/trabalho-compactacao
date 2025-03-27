#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decompressingString(char *input, char *output){
    //Variáveis de controle
    int indiceInicio = 0;
    int indiceFim = 0;
    int tamString = 0;
    int posicaoNum = 1; //posição inicial do numero
    int indexLocalASerCopiado = 0;//Cria um index pros numeros não se sobreescreverem
   
    //Contador de chars
    while(input[indiceInicio] != '\0'){
        char aSerCopiado = input[indiceInicio]; // Cria  o espaço pro caractere a ser reproduzido
        char numASerReproduzidoString[5] = {0};
        int qtdASerReproduzido = 0;// cria espaço pro numero de vzs a ser reproduzido

        // Encontrar o final do número
        indiceFim = indiceInicio + 1;
        while (input[indiceFim] != '-' && input[indiceFim] != '\0'){
            indiceFim++;
        }

        //pega o num a ser repetido em formato de string
        int numIndex = 0;
        while (posicaoNum<indiceFim){
                numASerReproduzidoString[numIndex] = input[posicaoNum]; //l-indice início pra pegar a posição 1 sempre, pois l é sempre um a mais que o II
                numIndex++;
                posicaoNum++;
            }
        numASerReproduzidoString[numIndex] = '\0';//Fechar a string
        
        qtdASerReproduzido = atoi(numASerReproduzidoString);// cria espaço pro numero de vzs a ser reproduzido

        // Copiar o char pro output
        for (int j = 0; j < qtdASerReproduzido; j++){
            output[indexLocalASerCopiado] = aSerCopiado;
            indexLocalASerCopiado++;
        }

        // Avança para o próximo conjunto
        if (input[indiceFim] == '-') {
            indiceInicio = indiceFim + 1;
            posicaoNum = indiceInicio + 1; //atualiza o l pro proximo número
        } else {
            break;  // Sai do loop se chegou ao fim da string
        }
    }
}

int main(){
    char input[255] = {0};
    char output[255] = {0};

    printf("Digite uma string para ser descompactada: ");
    fgets(input, 255, stdin);           // Lê a string de entrada
    input[strcspn(input, "\n")] = '\0'; // Remove o caractere de nova linha do final da string, se houver

    decompressingString(input, output);
    printf("String descompactada: %s\n", output);
}