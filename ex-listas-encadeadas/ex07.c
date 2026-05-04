#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula* vetor_para_lista_iterativo(int v[], int n) {
    celula *ini = NULL, *ult = NULL;
    for (int i = 0; i < n; i++) {
        celula *novo = malloc(sizeof(celula));
        novo->conteudo = v[i];
        novo->prox = NULL;
        if (ini == NULL) ini = novo;
        else ult->prox = novo;
        ult = novo;
    }
    return ini;
}

celula* vetor_para_lista_recursivo(int v[], int n) {
    if (n == 0) return NULL;
    celula *p = malloc(sizeof(celula));
    p->conteudo = v[0];
    p->prox = vetor_para_lista_recursivo(v + 1, n - 1);
    return p;
}

void lista_para_vetor_iterativo(celula *le, int v[]) {
    int i = 0;
    for (celula *p = le; p != NULL; p = p->prox) v[i++] = p->conteudo;
}

void lista_para_vetor_recursivo(celula *le, int v[], int i) {
    if (le == NULL) return;
    v[i] = le->conteudo;
    lista_para_vetor_recursivo(le->prox, v, i + 1);
}

int main() {
    int v_origem[] = {10, 20, 30, 40};
    int n = 4;

    celula *lista = vetor_para_lista_recursivo(v_origem, n);
    printf("Lista criada do vetor: ");
    for(celula *p = lista; p != NULL; p = p->prox) printf("%d ", p->conteudo);

    int v_destino[4];
    lista_para_vetor_iterativo(lista, v_destino);
    printf("\nVetor recuperado da lista: %d %d %d %d\n", v_destino[0], v_destino[1], v_destino[2], v_destino[3]);
    
    return 0;
}