#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula* busca_com_cabeca(int x, celula *le) {
    celula *p = le->prox;
    while (p != NULL && p->conteudo != x) p = p->prox;
    return p;
}

int crescente_com_cabeca(celula *le) {
    celula *p = le->prox;
    if (p == NULL || p->prox == NULL) return 1;
    while (p->prox != NULL) {
        if (p->conteudo > p->prox->conteudo) return 0;
        p = p->prox;
    }
    return 1;
}

int main() {
    celula *cabeca = (celula*) malloc(sizeof(celula));
    cabeca->prox = (celula*) malloc(sizeof(celula));
    cabeca->prox->conteudo = 10;
    cabeca->prox->prox = (celula*) malloc(sizeof(celula));
    cabeca->prox->prox->conteudo = 20;
    cabeca->prox->prox->prox = NULL;

    printf("Lista com cabeca: [H] -> 10 -> 20\n");
    printf("Esta crescente? %s\n", crescente_com_cabeca(cabeca) ? "Sim" : "Nao");
    
    celula *res = busca_com_cabeca(20, cabeca);
    if(res) printf("Busca por 20: Encontrado no endereco %p\n", (void*)res);

    return 0;
}