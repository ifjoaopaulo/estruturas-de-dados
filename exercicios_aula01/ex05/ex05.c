#include <stdio.h>

// 5. Crie um programa que leia 10 números e imprima a soma e a média deles.

int main() {
    int numero, soma, i;
    for (i = 0; i < 10; i++) {
        printf("Insira um número inteiro: ");
        scanf("%d", &numero);

        soma += numero;
    };

    float media = soma / 10;

    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);

    return 0;
}