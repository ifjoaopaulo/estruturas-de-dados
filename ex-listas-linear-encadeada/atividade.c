#include <stdio.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int tamanho;
} Lista;

// Inicializa a lista definindo o tamanho como zero
void inicializa(Lista *l) {
    l->tamanho = 0;
}

// Implemente as funções abaixo:
int insere(Lista *l, int pos, int elem) {
    if (l->tamanho == MAX || pos < 0 || l->tamanho < pos) {
        return 0;
    }

    for (int i = l->tamanho; i > pos; i--) {
        l->itens[i] = l->itens[i - 1];
    }

    l->itens[pos] = elem;
    l->tamanho++;
    return 1;
};

int removeElem(Lista *l, int pos) {

};

int busca(Lista *l, int elem) {

};

int atualiza(Lista *l, int pos, int novoValor) {

};

void exibe(Lista *l) {

};

int main() {
    Lista minhaLista;
    inicializa(&minhaLista);

    // DICA DE TESTE:
    // 1. Insira os valores 10, 20, 30.
    // 2. Exiba a lista.
    // 3. Tente inserir o valor 15 na posição 1.
    // 4. Exiba novamente e veja o deslocamento.
    // 5. Remova um elemento e verifique o resultado.

    insere(&minhaLista; 0; 10);
    insere(&minhaLista; 1; 20);
    insere(&minhaLista; 2; 30);
    insere(&minhaLista; 3; 40);

    printf("Lista: %d\n", minhaLista);

    return 0;
}