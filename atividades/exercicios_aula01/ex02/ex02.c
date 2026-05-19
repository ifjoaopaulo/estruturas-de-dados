#include <stdio.h>

// 2. Faça um programa que leia a idade de uma pessoa e informe se ela pode votar (idade mínima: 16 anos).

int main() {
    int idade;
    printf("Informe sua idade: ");
    scanf("%d", &idade);

    if (idade >= 16) {
        printf("Você pode votar.\n");
    } else {
        printf("Você não pode votar.\n");
    };

    return 0;
}