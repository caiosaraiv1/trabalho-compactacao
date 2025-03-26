#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compactar(char *lettEntrada, char *lettSaida){
    int tamanho = strlen(lettEntrada);
    int i = 0;
    int contador = 1;
    char *ptr = lettSaida;
    while(lettEntrada[i] != '\0'){
        *ptr = lettEntrada[i];
        while (i + 1 < strlen && lettEntrada[i] == lettEntrada[i + 1]){
            i++;
            contador++;
        }
        if(contador > 1){
            ptr += sprintf(ptr, "%d", contador);
        }
        if(i + 1 < strlen && lettEntrada[i] == lettEntrada[i + 1 - contador]){
            *ptr = '-';
        }
    }   
}


int main(){
    char entrada[100];
    char saida[100];

    printf("Digite ai: ");
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 
}