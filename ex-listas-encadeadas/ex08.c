#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula* busca_remove(int y, celula *le) {
    celula *p = le, *ant = NULL;
    while (p != NULL && p->conteudo != y) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) return le;
    if (ant == NULL) le = p->prox;
    else ant->prox = p->prox;
    free(p);
    return le;
}

celula* remove_k(int k, celula *le) {
    if (le == NULL) return NULL;
    if (k == 0) {
        celula *prox = le->prox;
        free(le);
        return prox;
    }
    celula *p = le;
    for (int i = 0; p != NULL && i < k - 1; i++) p = p->prox;
    if (p == NULL || p->prox == NULL) return le;
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return le;
}

void imprimir(celula *le) {
    for (celula *p = le; p != NULL; p = p->prox) printf("%d ", p->conteudo);
    printf("\n");
}

int main() {
    celula *lista = malloc(sizeof(celula));
    lista->conteudo = 5;
    lista->prox = malloc(sizeof(celula));
    lista->prox->conteudo = 10;
    lista->prox->prox = malloc(sizeof(celula));
    lista->prox->prox->conteudo = 15;
    lista->prox->prox->prox = NULL;

    printf("Lista original: "); imprimir(lista);
    
    lista = busca_remove(10, lista);
    printf("Apos remover 10: "); imprimir(lista);
    
    lista = remove_k(1, lista);
    printf("Apos remover k=1: "); imprimir(lista);

    return 0;
}