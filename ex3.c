#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO 100
int repeat(char lettEntrada[], char lettSaida[], int inicio, int size){

    int firstLett = lettEntrada[inicio];
    int  lastSet = inicio + 1;
    
    while (lastSet< size && lettEntrada[lastSet] != firstLett) {
        lastSet++;
    }

    int rep = lastSet - inicio;
    strncpy(lettSaida, lettEntrada + inicio, rep); // copia o grupo contiguo para a variavel
    lettSaida[rep] = '\0'; // adiciona o fim da string
    
    return lastSet;
}

int cont_Rep(char lettEntrada[], char lettSaida[], int *inicio, int size){
    int repet = 1;
    int saida_size = strlen(lettSaida);

    if(saida_size == 0) return 0;

    while(*inicio + saida_size <= size && strncmp(&lettEntrada[*inicio], lettSaida, saida_size) == 0){
        repet++;
        *inicio += saida_size;
    }
    return repet ;
}

int main(){
    char entrada[TAMANHO];
    char saida[TAMANHO];
    int inicio = 0;

    printf("Digite ai: ");
    fgets(entrada, TAMANHO, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 
    
    int tamanho = strlen(entrada);
    while(inicio < tamanho){
        int inicio_indice = repeat(entrada, saida, inicio, tamanho);
        int repeticao = cont_Rep(entrada, saida, &inicio_indice, tamanho);

        printf("%s%d", saida, repeticao);
        inicio = inicio_indice;

        (inicio< tamanho) && printf("-");

    }
}