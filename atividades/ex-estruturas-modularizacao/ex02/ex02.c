#include <stdio.h>

// Exercício 2 -- Sistema de Produtos

struct Produto {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
};

float valorEstoque;

void cadastrarProduto(struct Produto *p) {
    printf("Informe o nome do produto: ");
    scanf("%s", p->nome);

    printf("Informe o código do produto: ");
    scanf("%d", &p->codigo);

    printf("Informe o preço do produto: ");
    scanf("%f", &p->preco);

    printf("Informe a quantidade de produtos: ");
    scanf("%d", &p->quantidade);
};

float calcularValorEstoque(struct Produto *p) {
    valorEstoque = p->preco * p->quantidade;
    return valorEstoque;
};

void mostrarProduto(struct Produto *p) {
    printf("\n");
    printf("Nome: %s\n", p->nome);
    printf("Código: %d\n", p->codigo);
    printf("Preço: %.2f\n", p->preco);
    printf("Quantidade em estoque: %d\n", p->quantidade);
};

int main() {
    struct Produto produtos[50];

    for (int i = 0; i < 4; i++) {
        cadastrarProduto(&produtos[i]);
    };

    for (int i = 0; i < 4; i++) {
        mostrarProduto(&produtos[i]);
    };

    float valorTotalEstoque;
    for (int i = 0; i < 4; i++) {
        float valorEstoque = calcularValorEstoque(&produtos[i]);
        valorTotalEstoque = valorTotalEstoque + valorEstoque;
    };

    printf("Valor total do estoque: %.2f\n", valorTotalEstoque);

    return 0;
}