#include <stdio.h>

// 1. Escreva um programa em C que leia dois números inteiros e imprima o mairo deles.

int soma(int a, int b) {
    return a + b;
}

int main() {
    int numero1, numero2;

    printf("Insira o valor do primeiro número inteiro: ");
    scanf("%d", &numero1);

    printf("Insira o valor do segundo número inteiro: ");
    scanf("%d", &numero2);

    printf("A soma dos dois valores é %d\n", soma(numero1, numero2));

    return 0;
}