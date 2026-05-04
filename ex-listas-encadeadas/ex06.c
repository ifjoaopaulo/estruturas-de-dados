#include <stdio.h>
#include <stdlib.h>

/*
A função original apresentada não tem validação se p o p->prox são NULL antes de operar, o que pode levar ao erro do programa. 
*/

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

void remover_primeiro_seguro(celula **ptr_le) {
    if (ptr_le == NULL || *ptr_le == NULL) return;
    
    celula *lixo = *ptr_le;
    *ptr_le = (*ptr_le)->prox; 
    free(lixo);               
}

void liberar_lista_iterativa(celula **ptr_le) {
    celula *atual = *ptr_le;
    while (atual != NULL) {
        celula *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    *ptr_le = NULL;
}

celula* liberar_lista_recursiva(celula *le) {
    if (le == NULL) return NULL;
    liberar_lista_recursiva(le->prox);
    free(le);
    return NULL;
}

void imprimir(celula *le) {
    if (le == NULL) { printf("Lista Vazia\n"); return; }
    for (; le != NULL; le = le->prox) printf("%d ", le->conteudo);
    printf("\n");
}

int josephus(int n, int m) {
    celula *inicio = NULL, *p = NULL;
    for (int i = 1; i <= n; i++) {
        celula *novo = malloc(sizeof(celula));
        novo->conteudo = i;
        if (inicio == NULL) { inicio = novo; } 
        else { p->prox = novo; }
        p = novo;
    }
    p->prox = inicio;

    while (p->prox != p) {
        for (int i = 1; i < m; i++) p = p->prox;
        celula *lixo = p->prox;
        p->prox = lixo->prox;
        free(lixo);
    }
    int sobrevivente = p->conteudo;
    free(p);
    return sobrevivente;
}

int main() {
    celula *minha_lista = malloc(sizeof(celula));
    minha_lista->conteudo = 10;
    minha_lista->prox = malloc(sizeof(celula));
    minha_lista->prox->conteudo = 20;
    minha_lista->prox->prox = malloc(sizeof(celula));
    minha_lista->prox->prox->conteudo = 30;
    minha_lista->prox->prox->prox = NULL;

    printf("Lista Original: ");
    imprimir(minha_lista);

    remover_primeiro_seguro(&minha_lista);
    printf("Apos remover o primeiro (10): ");
    imprimir(minha_lista);

    liberar_lista_iterativa(&minha_lista);
    printf("Apos liberar tudo: ");
    imprimir(minha_lista);

    int n = 7, m = 3;
    printf("Josephus (n=%d, m=%d). Sobrevivente: %d\n", n, m, josephus(n, m));
    
    return 0;
}