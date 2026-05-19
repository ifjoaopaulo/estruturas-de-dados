#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

int contar_iterativo(celula *le) {
    int n = 0;
    for (celula *p = le; p != NULL; p = p->prox) n++;
    return n;
}

int contar_recursivo(celula *le) {
    if (le == NULL) return 0;
    return 1 + contar_recursivo(le->prox);
}

int altura(celula *c) {
    int passos = 0;
    while (c != NULL && c->prox != NULL) {
        passos++;
        c = c->prox;
    }
    return passos;
}

int profundidade(celula *inicio, celula *destino) {
    int passos = 0;
    celula *p = inicio;
    while (p != NULL && p != destino) {
        passos++;
        p = p->prox;
    }

    return (p == destino) ? passos : -1;
}

int main() {
    celula *c3 = malloc(sizeof(celula));
    c3->conteudo = 30; c3->prox = NULL;
    
    celula *c2 = malloc(sizeof(celula));
    c2->conteudo = 20; c2->prox = c3;
    
    celula *c1 = malloc(sizeof(celula));
    c1->conteudo = 10; c1->prox = c2;

    printf("Contagem Iterativa: %d\n", contar_iterativo(c1));
    printf("Contagem Recursiva: %d\n", contar_recursivo(c1));
    printf("Altura da primeira celula: %d\n", altura(c1));
    printf("Profundidade da terceira celula: %d\n", profundidade(c1, c3));

    return 0;
}