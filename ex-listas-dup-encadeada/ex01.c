#include <stdio.h>
#include <stdlib.h>

/*
Questões de reflexão:
1. Quando um nó intermediário é removido,
é importante lembrar de atualizar o ponteiro anterior 
ao valor antigo para enxergar que o próximo valor foi atualizado
(o antigo valor prox seria o nó que estamos removendo, 
então o novo prox seria o valor prox do nó removido). 
Um exemplo disso pode ser encontrado na função remover() desta atividade,
onde eu atualizei tanto atual->ant->prox quanto atual->prox->ant.

2. A principal vantagem é a capacidade de usar a lista em via dupla,
permitindo que acessemos tanto o conteúdo seguinte quanto o anterior.
Essa vantagem pode ser observada na função exibirReverso() desta atividade,
onde sua implementação foi facilitada pela existencia do ponteiro ant.

3. Para evitar o memory leak, onde o programa pode ocupar
mais memória do que necessário,
até mesmo após o encerramento de sua execução.
Causando grandes problemas de performance
no dispositivo inteiro
do usuário.
*/

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

// Insere um valor no nó logo após a head(inicio), desde que a lista não esteja vazia.
void inserirInicio(No** inicio, int valor) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* novo = (struct No*) malloc(sizeof(struct No));

    if (novo == NULL) {
        printf("Operação inválida. Valor de novo nó nulo.\n");
        return;
    }

    novo->ant = NULL;
    novo->valor = valor;
    novo->prox = *inicio;

    if (*inicio != NULL) {
        (*inicio)->ant = novo;
    }

    *inicio = novo;
}

// Insere um valor ao fim da lista por meio de um ponteiro *ultimo, que é definido checando se o prox é nulo ou não.
void inserirFim(No** inicio, int valor) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* novo = (struct No*) malloc(sizeof(struct No));

    if (novo == NULL) {
        printf("Operação inválida. Valor de novo nó nulo.\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    struct No* ultimo = *inicio;

    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox;
    }

    ultimo->prox = novo;
    novo->ant = ultimo;
}

// Percorre a lista inteira até encontrar o valor que foi inserido pelo usuário, e então remove ele. 
// Também atualiza os ponteiros anteriores e seguintes ao valor que foi removido(se estirem).
void remover(No** inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* atual = *inicio;

    while(atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor não encontrado na lista.\n");
        return;
    }

    if (atual == *inicio) {
        *inicio = atual->prox;
    }

    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    }

    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }

    free(atual);
    printf("Valor %d removido com sucesso.\n", valor);
}

// Percorre a lista até chegar em um nó que é nulo, exibindo o nó atual toda vez que muda de posição.
void exibirDireto(No* inicio) {
    struct No* atual = inicio;

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->prox;
    }
}

// Primeiro percorre a lista inteira silenciosamente até chegar ao fim, e então volta ao contrário por toda a lista, exibindo-a em reverso.
void exibirReverso(No* inicio) {
    struct No* atual = inicio;

    while(atual->prox != NULL) {
        atual = atual->prox;
    }

    while (atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->ant;
    }
}

// Percorre toda a lista, liberando a memória da posição atual. Usa um ponteiro "prox" local para definir qual o endereço do valor seguinte àquele que está prestes a ser liberado.
void liberarLista(No** inicio) {
    if (*inicio == NULL) {
        return;
    }

    struct No* atual = *inicio;
    struct No* prox;

    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
    printf("Memória liberada.\n");
}

// Função para o Desafio Complementar
// "Busca de um elemento na lista;"
void buscar(struct No** inicio, int valor) {
    if (*inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    struct No* atual = *inicio;
    int posicao = 0;
    
// Nesse caso, a primeira posição seria a posição 0,
// então em uma lista 1, 2, 3, o número 1 seria a posição 0, o número 2 seria a posição 1, etc.,
// como o índice de um vetor.

    while(atual != NULL) {
        if (atual->valor == valor) {
            printf("%d encontrado na posição %d.\n", valor, posicao); 
            return;
        }
        atual = atual->prox;
        posicao++;
    }

    if (atual == NULL) {
        printf("Valor não encontrado na lista.\n");
        return;
    }
}


int main() {

    No* lista = NULL;

    int opcao;
    int valor;

    do {

        printf("\n--- MENU ---\n");
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Remover valor\n");
        printf("4 - Mostrar lista (direto)\n");
        printf("5 - Mostrar lista (reverso)\n");
        printf("6 - Buscar valor\n");
        printf("0 - Sair\n");

        printf("Opção: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("Valor: ");
                scanf("%d", &valor);

                inserirInicio(&lista, valor);
                break;

            case 2:
                printf("Valor: ");
                scanf("%d", &valor);

                inserirFim(&lista, valor);
                break;

            case 3:
                printf("Valor a remover: ");
                scanf("%d", &valor);

                remover(&lista, valor);
                break;

            case 4:
                printf("Lista (direto):\n");
                exibirDireto(lista);
                break;

            case 5:
                printf("Lista (reverso):\n");
                exibirReverso(lista);
                break;

            case 6:
                printf("Valor para buscar: ");
                scanf("%d", &valor);

                buscar(&lista, valor);
                break;

            case 0:
                liberarLista(&lista);
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    if (opcao == 0) {
        liberarLista(&lista);
    }

    return 0;
}