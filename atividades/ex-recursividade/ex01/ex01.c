#include <stdio.h>

// Questão 1: Análise de Fluxo (Teste de Mesa)

void exercicio1(int n) {
    if (n > 0) {
        printf("Entrando: %d\n", n);
        exercicio1(n - 1);
        printf("Saindo: %d\n", n);
    }
}

int main() {
    exercicio1(5);
    return 0;
}