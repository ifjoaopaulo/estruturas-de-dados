#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercício 3 — Contagem de Elementos
Implemente uma função que retorne a quantidade de elementos armazenados na fila.

Para filas dinâmicas, a contagem deve ser realizada percorrendo a estrutura.
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

void consultarPrimeiro(Fila* f) {
    if (f->inicio == NULL) {
        printf("A fila esta vazia. Nao ha alunos para consultar no momento.\n");
        return;
    }

    Aluno primeiro = f->inicio->dados;

    printf("\nPrimeiro Aluno da Fila:\n");
    printf("Matricula: %d\n", primeiro.matricula);
    printf("Nome: %s\n", primeiro.nome);
    printf("Notas: %.1f, %.1f, %.1f\n", 
           primeiro.notas[0], 
           primeiro.notas[1], 
           primeiro.notas[2]);
    printf("------------------------------\n");
}

int contarAlunosNaFila(Fila* f) {
    int contador = 0;
    
    No* atual = f->inicio;
    
    while (atual != NULL) {
        contador++;
        atual = atual->prox; 
    }
    
    return contador;
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
    printf("Quantidade de alunos na fila: %d\n", contarAlunosNaFila(&fila));
    return 0;
}