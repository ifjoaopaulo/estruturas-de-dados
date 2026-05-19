#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverter(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int v[], int n) {// [cite: 131]
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) inverter(&v[j], &v[j + 1]);
        }
    }
}

// Partição para Quick Sort 
int partition(int v[], int low, int high) {
    int temp = v[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (v[j] < temp) {
            i++;
            inverter(&v[i], &v[j]);
        }
    }
    inverter(&v[i + 1], &v[high]);
    return (i + 1);
}
 
void quickSort(int v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; i++) v[i] = rand() % n;
}

int main() {
    int tamanhos[] = {10000, 50000, 100000}; 
    for (int k = 0; k < 3; k++) {
        int n = tamanhos[k];
        int *v1 = malloc(n * sizeof(int));
        int *v2 = malloc(n * sizeof(int));

        preencherVetor(v1, n);
        for(int i=0; i<n; i++) v2[i] = v1[i];

        clock_t inicio, fim;

        // Teste Bubble Sort
        inicio = clock();
        bubbleSort(v1, n);
        fim = clock();
        printf("N: %d | Bubble Sort: %.4f s\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        // Teste Quick Sort
        inicio = clock();
        quickSort(v2, 0, n - 1);
        fim = clock();
        printf("N: %d | Quick Sort : %.4f s\n", n, (double)(fim - inicio) / CLOCKS_PER_SEC);

        free(v1); free(v2);
    }
    return 0;
}