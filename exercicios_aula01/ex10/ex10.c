#include <stdio.h>

// 10. Implemente um programa que utilize ponteiros para trocar o valor de duas variáveis (dica: use uma função void troca(int *a, int *b)).

void troca(int *a, int *b) {
    int auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}

int main() {
    int a = 0;
    int b = 0;

    printf("Insira o primeiro valor: ");
    scanf("%d", &a);

    printf("Insira o segundo valor: ");
    scanf("%d", &b);

    troca(&a, &b);
    printf("Valores invertidos:\nA: %d\nB: %d\n", a, b);

    return 0;
}