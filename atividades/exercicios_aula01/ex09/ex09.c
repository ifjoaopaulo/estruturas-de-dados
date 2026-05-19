#include <stdio.h>

// 9. Crie uma função que receba dois números inteiros e retorne o resultado da multiplicação sem usar o operador *.

int multiplicacao(int a, int b) {
    int resultado = 0;
    for (int i = 0; i < b; i++) {
        resultado += a;
    };
    return resultado;
}

int main() {
    int numero1, numero2;
    printf("Insira o primeiro número: ");
    scanf("%d", &numero1);

    printf("Insira o segundo número: ");
    scanf("%d", &numero2);

    int resultado = multiplicacao(numero1, numero2);
    printf("Resultado: %d\n", resultado);

    return 0;
}