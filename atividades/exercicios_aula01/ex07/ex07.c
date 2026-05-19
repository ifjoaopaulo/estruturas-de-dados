#include <stdio.h>

// 7. Escreva uma função em C que receba um vetor de inteiros e retorne o maior valor contido nele.

int encontrarMaiorValor(int vetor[], int tamanho) {
    int maiorNumero = vetor[0];

    for (int i = 0; i < tamanho; i++) {
        if(vetor[i] > maiorNumero) {
            maiorNumero = vetor[i];
        }
    };
    return maiorNumero;
}

int main(){
    int numeros[10];
    int maiorNumero;
    for (int i = 0; i < 10; i++) {
        printf("Insira um número: ");
        scanf("%d", &numeros[i]);
    };

    maiorNumero = encontrarMaiorValor(numeros, 10);

    printf("Maior valor digitado: %d\n", maiorNumero);

    return 0;
}