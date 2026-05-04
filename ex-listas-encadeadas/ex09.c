#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

void busca_e_insere(int x, int y, celula *le) {
    celula *p = le;
    
    while (p != NULL && p->conteudo != x) {
        p = p->prox;
    }

    if (p != NULL) {
        celula *nova = malloc(sizeof(celula));
        nova->conteudo = y;
        nova->prox = p->prox;
        p->prox = nova;
    } else {
        printf("Valor %d nao encontrado na lista. Nenhuma insercao realizada.\n", x);
    }
}

void imprimir_lista(celula *le) {
    celula *p = le;
    while (p != NULL) {
        printf("%d -> ", p->conteudo);
        p = p->prox;
    }
    printf("NULL\n");
}

int main() {
    celula *n3 = malloc(sizeof(celula));
    n3->conteudo = 30; n3->prox = NULL;
    
    celula *n2 = malloc(sizeof(celula));
    n2->conteudo = 20; n2->prox = n3;
    
    celula *n1 = malloc(sizeof(celula));
    n1->conteudo = 10; n1->prox = n2;

    printf("Lista original: ");
    imprimir_lista(n1);

    printf("\nInserindo 25 apos o 20...\n");
    busca_e_insere(20, 25, n1);
    imprimir_lista(n1);

    printf("\nInserindo 35 apos o 30...\n");
    busca_e_insere(30, 35, n1);
    imprimir_lista(n1);

    printf("\nTentando inserir apos o 99...\n");
    busca_e_insere(99, 100, n1);

    return 0;
}