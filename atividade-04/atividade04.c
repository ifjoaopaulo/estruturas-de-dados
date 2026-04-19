#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 1000000
#define REPETICOES 10000

int buscaSequencial(int v[], int n, int alvo, long *comp) {
    for (int i = 0; i < n; i++) {
        (*comp)++;
        if (v[i] == alvo) return i;
    }
    return -1;
}

int buscaBinaria(int v[], int n, int alvo, long *comp) {
    int esq = 0, dir = n - 1;
    while (esq <= dir) {
        (*comp)++;
        int meio = esq + (dir - esq) / 2; 
        if (v[meio] == alvo) return meio;
        if (v[meio] < alvo) esq = meio + 1;
        else dir = meio - 1;
    }
    return -1;
}

int main() {
    int *vetor = (int *)malloc(TAMANHO * sizeof(int));
    if (vetor == NULL) return 1;

    int alvo = -1;
    long totalCompSeq = 0, totalCompBin = 0;
    clock_t inicio, fim;

    for (int i = 0; i < TAMANHO; i++) vetor[i] = i * 2;

    // Teste Sequencial
    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        long c = 0;
        buscaSequencial(vetor, TAMANHO, alvo, &c);
        totalCompSeq += c;
    }
    fim = clock();
    printf("Sequencial | Tempo: %.4fs | Media Comp: %ld\n",
           (double)(fim - inicio) / CLOCKS_PER_SEC, totalCompSeq / REPETICOES);

    // Teste Binário
    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        long c = 0;
        buscaBinaria(vetor, TAMANHO, alvo, &c);
        totalCompBin += c;
    }
    fim = clock();
    printf("Binaria    | Tempo: %.4fs | Media Comp: %ld\n",
           (double)(fim - inicio) / CLOCKS_PER_SEC, totalCompBin / REPETICOES);

    free(vetor);
    return 0;
}