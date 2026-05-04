#include <stdio.h>
#include <stdlib.h>

/*
Alocar células com malloc pode ser ineficiente devido à fragmentação de memória.
*/

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula* criar_no(int x) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->conteudo = x; novo->prox = NULL;
    return novo;
}

celula* inverte(celula *le) {
    celula *ant = NULL, *atual = le, *prox = NULL;
    while (atual != NULL) {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    return ant;
}

void imprimir(celula *le) {
    for (celula *p = le; p != NULL; p = p->prox) printf("%d ", p->conteudo);
    printf("\n");
}

int main() {
    celula *L1 = criar_no(1);
    L1->prox = criar_no(2);
    L1->prox->prox = criar_no(3);

    printf("Lista original: "); imprimir(L1);
    
    L1 = inverte(L1);
    printf("Lista invertida: "); imprimir(L1);

    return 0;
}