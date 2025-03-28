#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compactar(char *lettEntrada){
    int tamanho = strlen(lettEntrada);

    for(int i = 0; i < tamanho; i++){
        const char *subEntrada = &lettEntrada[i];
        
    }
}


int main(){
    char entrada[100];
    char saida[100];

    printf("Digite ai: ");
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 
}