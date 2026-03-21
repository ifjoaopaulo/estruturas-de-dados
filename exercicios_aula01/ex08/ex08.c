#include <stdio.h>

// 8. Implemente um programa que leia 5 nomes e os imprima em ordem inversa.

int main() {
    char listaNomes[5][50];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Informe um nome: ");
        scanf(" %s", listaNomes[i]);
    };
    
    for (i = 5; i >= 0; i--) {
        printf("%s\n", listaNomes[i]);
    };

    return 0;
}