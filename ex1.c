#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que realiza a compressão da stringgit
void compressString(char *input, char *charArray, int *countArray, int *length)
{
    // Variável que armazena o caractere atual que estamos processando
    char currentChar = input[0];
    // Índices de iteração para a string de entrada (input) e para os arrays de resultado
    int i = 0, j = 0, charCount = 0;

    // Loop para percorrer toda a string de entrada
    while (input[i] != '\0')  // Continua até o final da string
    {
        charCount++;  // Conta o número de vezes que o caractere atual aparece consecutivamente

        // Verifica se o próximo caractere é diferente do atual
        if (input[i] != input[i + 1])  // Quando um caractere diferente é encontrado, armazena os dados
        {
            charArray[j] = currentChar;  // Armazena o caractere atual no array de caracteres comprimidos
            countArray[j] = charCount;   // Armazena o número de ocorrências consecutivas do caractere
            j++;  // Move para o próximo índice dos arrays
            currentChar = input[i + 1];  // Atualiza o caractere atual para o próximo caractere
            charCount = 0;  // Reinicia a contagem para o próximo caractere
        }
        i++;  // Avança para o próximo caractere na string de entrada
    }

    *length = j;  // Atribui o tamanho final da compressão ao valor de length
}

int main()
{
    // Aloca dinamicamente memória para a string de entrada e para os arrays de resultado
    char *inputString = (char *)malloc(100 * sizeof(char));  // A string de entrada pode ter até 99 caracteres
    char *compressedChars = (char *)malloc(100 * sizeof(char));  // Array para armazenar os caracteres comprimidos
    int *charCounts = (int *)malloc(100 * sizeof(int));  // Array para armazenar as quantidades de cada caractere

    // Verifica se a alocação de memória foi bem-sucedida
    if (!inputString || !compressedChars || !charCounts)
    {
        printf("Erro na alocação de memória\n");
        return 1;  // Se a alocação falhar, imprime uma mensagem de erro e termina o programa
    }

    // Solicita ao usuário para digitar a string a ser compactada
    printf("Digite a string a ser compactada: ");
    fgets(inputString, 100, stdin);  // Lê a string de entrada
    inputString[strcspn(inputString, "\n")] = '\0';  // Remove o caractere de nova linha do final da string, se houver

    int compressedLength = 0;  // Variável que armazenará o tamanho da string comprimida
    // Chama a função que faz a compressão da string
    compressString(inputString, compressedChars, charCounts, &compressedLength);

    // Imprime a string comprimida
    for (int i = 0; i < compressedLength; i++)
    {
        printf("%c%i-", compressedChars[i], charCounts[i]);
    }

    // Libera a memória alocada dinamicamente
    free(compressedChars);
    free(charCounts);

    return 0;  // Finaliza o programa
}
