#include <stdio.h>

// Questão 2: De Iteração para Recursão

// Transforme essa função em uma função recursiva
int soma_iterativa(int n) {
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += i;
    }
    return total;
}

// Função convertida para Recursão
int total = 0;
int soma_recursiva(int n){
    if (n > 1) {
        total += n;
        return total, soma_recursiva(n - 1);
    } else if (n == 1) {
        return total + 1;
    }
}

int main() {
    int numero;

    printf("Insira um valor a ser calculado: ");
    scanf("%d", &numero);

    int total = soma_recursiva(numero);
    printf("A soma de 1 até %d é: %d\n", numero, total);
    return 0;
}