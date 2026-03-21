#include <stdio.h>

// 6. Modifique o programa anterior para contar quantos dos números lidos são pares.

int main() {
    int numero, soma, i, quantidadePares;
    for (i = 0; i < 10; i++) {
        printf("Insira um número inteiro: ");
        scanf("%d", &numero);
        if (numero % 2 == 0) {
            quantidadePares++;
        }

        soma += numero;
    };

    float media = soma / 10;

    printf("Soma: %d\n", soma);
    printf("Média: %.2f\n", media);
    printf("Quantidade de pares digitados: %d\n", quantidadePares);

    return 0;
}