#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 100

// Estrutura para a pilha com vetor
typedef struct {
    char paginas[TAM][100];
    int topo;
} PilhaVetor;

// Estruturas para a pilha com lista encadeada 
typedef struct No {
    char url[100];
    struct No *prox;
} No;

typedef struct {
    No *topo;
} PilhaLista;

// Funções para operação de uma pilha por meio de um vetor
void inicializarVetor(PilhaVetor *p) {
    p->topo = -1;
}

int pilhaVaziaVetor(PilhaVetor *p) {
    return p->topo == -1;
}

int pilhaCheiaVetor(PilhaVetor *p) {
    return p->topo == TAM - 1;
}

void pushVetor(PilhaVetor *p, char url[]) {
    if (pilhaCheiaVetor(p)) {
        printf("Erro (Vetor): Historico cheio.\n");
        return;
    }
    p->topo++;
    strcpy(p->paginas[p->topo], url);
}

void popVetor(PilhaVetor *p) {
    if (pilhaVaziaVetor(p)) {
        printf("Erro (Vetor): Pilha vazia.\n");
        return;
    }
    p->topo--;
}

char* topVetor(PilhaVetor *p) {
    if (pilhaVaziaVetor(p)) return NULL;
    return p->paginas[p->topo];
}

void imprimirVetor(PilhaVetor *p) {
    if (pilhaVaziaVetor(p)) {
        printf("Historico (Vetor) vazio.\n");
        return;
    }
    for (int i = p->topo; i >= 0; i--) {
        printf("%s\n", p->paginas[i]);
    }
}

// Funções para a operação de uma pilha por meio de listas encadeadas
void inicializarLista(PilhaLista *p) {
    p->topo = NULL;
}

int pilhaVaziaLista(PilhaLista *p) {
    return p->topo == NULL;
}

void pushLista(PilhaLista *p, char url[]) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro: Falha de memoria.\n");
        exit(1);
    }
    strcpy(novo->url, url);
    novo->prox = p->topo;
    p->topo = novo;
}

void popLista(PilhaLista *p) {
    if (pilhaVaziaLista(p)) {
        printf("Erro (Lista): Pilha vazia.\n");
        return;
    }
    No *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
}

char* topLista(PilhaLista *p) {
    if (pilhaVaziaLista(p)) return NULL;
    return p->topo->url;
}

void imprimirLista(PilhaLista *p) {
    if (pilhaVaziaLista(p)) {
        printf("Historico (Lista) vazio.\n");
        return;
    }
    No *atual = p->topo;
    while (atual != NULL) {
        printf("%s\n", atual->url);
        atual = atual->prox;
    }
}

void liberarLista(PilhaLista *p) {
    while (!pilhaVaziaLista(p)) {
        popLista(p);
    }
}

int main() {
    PilhaVetor backVetor, forwardVetor;
    PilhaLista backLista, forwardLista;
    
    inicializarVetor(&backVetor);
    inicializarVetor(&forwardVetor);
    inicializarLista(&backLista);
    inicializarLista(&forwardLista);
    
    int modo = 0;
    int opcao;
    char url[100];
    
    printf("=========================================\n");
    printf("Escolha o modo de execucao:\n");
    printf("1 - Pilha Baseada em Vetor Estatico\n");
    printf("2 - Pilha Baseada em Lista Encadeada (Dinamica)\n");
    printf("=========================================\n");
    printf("Sua escolha: ");
    
    while (modo != 1 && modo != 2) {
        if (scanf("%d", &modo) != 1 || (modo != 1 && modo != 2)) {
            printf("Opcao invalida. Digite 1 para Vetor ou 2 para Lista: ");
        }
    }
    
    printf("O sistema executará usando: %s.\n", 
           (modo == 1) ? "VETOR ESTÁTICO" : "LISTA ENCADEADA");
    
    do {
        printf("========= MENU =========\n");
        printf("1 - Visitar nova pagina\n");
        printf("2 - Voltar pagina\n");
        printf("3 - Mostrar pagina atual\n");
        printf("4 - Mostrar historico\n");
        printf("5 - Avançar pagina (Desafio Extra)\n");
        printf("6 - Sair\n");
        printf("========================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("Por favor, digite um numero valido.\n");
            continue;
        }
        
        switch (opcao) {
            case 1:
                printf("Digite a URL: ");
                scanf("%99s", url);
                
                if (modo == 1) {
                    pushVetor(&backVetor, url);
                    inicializarVetor(&forwardVetor);
                } else {
                    pushLista(&backLista, url);
                    liberarLista(&forwardLista);
                }
                break;
                
            case 2:
                if (modo == 1) {
                    if (pilhaVaziaVetor(&backVetor)) {
                        printf("Nao ha paginas para voltar.\n");
                    } else {
                        char* paginaAtual = topVetor(&backVetor);
                        printf("Pagina removida: %s\n", paginaAtual);
                        pushVetor(&forwardVetor, paginaAtual);
                        popVetor(&backVetor);
                    }
                } else {
                    if (pilhaVaziaLista(&backLista)) {
                        printf("Nao ha paginas para voltar.\n");
                    } else {
                        char* paginaAtual = topLista(&backLista);
                        printf("Pagina removida: %s\n", paginaAtual);
                        pushLista(&forwardLista, paginaAtual);
                        popLista(&backLista);
                    }
                }
                break;
                
            case 3:
                if (modo == 1) {
                    char* atual = topVetor(&backVetor);
                    if (atual != NULL) printf("%s\n", atual);
                    else printf("Nenhuma pagina aberta.\n");
                } else {
                    char* atual = topLista(&backLista);
                    if (atual != NULL) printf("%s\n", atual);
                    else printf("Nenhuma pagina aberta.\n");
                }
                break;
                
            case 4:
                if (modo == 1) {
                    imprimirVetor(&backVetor);
                } else {
                    imprimirLista(&backLista);
                }
                break;
                
            case 5:
                if (modo == 1) {
                    if (pilhaVaziaVetor(&forwardVetor)) {
                        printf("Nao ha paginas para avancar.\n");
                    } else {
                        char* proxima = topVetor(&forwardVetor);
                        printf("Avancando para: %s\n", proxima);
                        pushVetor(&backVetor, proxima); 
                        popVetor(&forwardVetor);
                    }
                } else {
                    if (pilhaVaziaLista(&forwardLista)) {
                        printf("Nao ha paginas para avancar.\n");
                    } else {
                        char* proxima = topLista(&forwardLista);
                        printf("Avancando para: %s\n", proxima);
                        pushLista(&backLista, proxima); 
                        popLista(&forwardLista);
                    }
                }
                break;
                
            case 6:
                printf("Limpando dados e encerrando o programa...\n");
                liberarLista(&backLista);
                liberarLista(&forwardLista);
                break;
                
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
    
    return 0;
}