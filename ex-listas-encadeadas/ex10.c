#include <stdio.h>
#include <stdlib.h>

typedef struct reg_duplo {
    int conteudo;
    struct reg_duplo *ant;
    struct reg_duplo *prox;
} celula_dupla;

celula_dupla* inserir_apos(celula_dupla *p, int x) {
    celula_dupla *novo = (celula_dupla*) malloc(sizeof(celula_dupla));
    novo->conteudo = x;
    novo->prox = p->prox;
    novo->ant = p;
    if (p->prox != NULL) p->prox->ant = novo;
    p->prox = novo;
    return novo;
}

void imprimir_dupla(celula_dupla *le) {
    celula_dupla *p = le;
    while (p != NULL) {
        printf("%d <-> ", p->conteudo);
        p = p->prox;
    }
    printf("NULL\n");
}

int main() {
    celula_dupla *inicio = (celula_dupla*) malloc(sizeof(celula_dupla));
    inicio->conteudo = 100;
    inicio->ant = NULL;
    inicio->prox = NULL;

    inserir_apos(inicio, 200);
    inserir_apos(inicio, 150);

    printf("Lista Dupla: ");
    imprimir_dupla(inicio);

    return 0;
}