#include <stdio.h>

// Questão 3: Desafio Lógico (O "Espelho")

int numEspelhado;
int espelharNumeroInt(int n) {
    if (n >= 1) {
        numEspelhado = numEspelhado * 10 + (n % 10);
        return numEspelhado, espelharNumeroInt(n / 10);
    } else {
        return numEspelhado;
    }
}

int main() {
    int numOriginal;
    printf("Insira um número para inverter: ");
    scanf("%d", &numOriginal);

    numEspelhado = espelharNumeroInt(numOriginal);
    printf("%d espelhado é %d\n", numOriginal, numEspelhado);

    return 0;
}