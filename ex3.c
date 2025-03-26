#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char entrada[100];
    char saida[100];

    printf("Digite ai: ");
    fgets(entrada, 100, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; 
}