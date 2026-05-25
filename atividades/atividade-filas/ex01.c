#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 1 — Impressão da Fila
Implemente uma função que percorra a fila e imprima todos os seus elementos.

A função deve exibir:

matrícula;
nome;
notas do aluno.
*/

typedef struct {
    int matricula;
    char nome[50];
    float notas[3]; 
} Aluno;

typedef struct No {
    Aluno dados;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void imprimirFila(Fila* f) {
    if (f->inicio == NULL) {
        printf("A fila esta vazia.\n");
        return;
    }

    No* atual = f->inicio;
    
    printf("\nLista de Alunos na Fila:\n");
    
    while (atual != NULL) {
        printf("Matricula: %d\n", atual->dados.matricula);
        printf("Nome: %s\n", atual->dados.nome);
        printf("Notas: %.1f, %.1f, %.1f\n", 
               atual->dados.notas[0], 
               atual->dados.notas[1], 
               atual->dados.notas[2]);
        printf("-------------------------------\n");
        
        atual = atual->prox; 
    }
}

void inicializarFila(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserirFila(Fila* f, Aluno a) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }
    novoNo->dados = a;
    novoNo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novoNo;
    } else {
        f->fim->prox = novoNo;
    }
    f->fim = novoNo;
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    Aluno a1 = {101, "João", {9.5, 8.0, 10.0}};
    Aluno a2 = {102, "Alice", {10.0, 9.8, 10.0}};
    Aluno a3 = {103, "Pedro", {8.5, 9.0, 9.5}};

    inserirFila(&fila, a1);
    inserirFila(&fila, a2);
    inserirFila(&fila, a3);

    imprimirFila(&fila);
    return 0;
}