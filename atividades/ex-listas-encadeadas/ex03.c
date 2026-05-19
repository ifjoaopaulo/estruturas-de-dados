#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

int esta_crescente(celula *le) {
    for (celula *p = le; p != NULL && p->prox != NULL; p = p->prox) {
        if (p->conteudo > p->prox->conteudo) return 0;
    }
    return 1;
}

celula* menor_iterativo(celula *le) {
    if (le == NULL) return NULL;
    celula *menor = le;
    for (celula *p = le->prox; p != NULL; p = p->prox) {
        if (p->conteudo < menor->conteudo) menor = p;
    }
    return menor;
}

celula* ponto_medio(celula *le) {
    if (le == NULL) return NULL;
    celula *lento = le;
    celula *rapido = le;
    while (rapido != NULL && rapido->prox != NULL) {
        rapido = rapido->prox->prox;
        if (rapido != NULL) lento = lento->prox;
    }
    return lento;
}

int main() {
    celula *n3 = malloc(sizeof(celula)); n3->conteudo = 40; n3->prox = NULL;
    celula *n2 = malloc(sizeof(celula)); n2->conteudo = 25; n2->prox = n3;
    celula *n1 = malloc(sizeof(celula)); n1->conteudo = 10; n1->prox = n2;

    printf("Lista esta em ordem crescente? %s\n", esta_crescente(n1) ? "Sim" : "Nao");
    printf("Menor valor na lista: %d\n", menor_iterativo(n1)->conteudo);
    printf("Ponto medio: %d\n", ponto_medio(n1)->conteudo);

    return 0;
}