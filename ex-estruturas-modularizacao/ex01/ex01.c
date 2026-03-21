#include <stdio.h>

// Exercício 1 -- Cadastro de Alunos

struct Aluno {
    int matricula;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

void lerAluno(struct Aluno *a) {
    printf("Informe o nome do aluno: ");
    scanf("%s", a->nome);

    printf("Informe a matrícula do aluno: ");
    scanf("%d", &a->matricula);

    printf("Informe a primeira nota do aluno: ");
    scanf("%f", &a->nota1);

    printf("Informe a segunda nota do aluno: ");
    scanf("%f", &a->nota2);
};

float calcularMedia(struct Aluno *a) {
    a->media = (a->nota1 + a->nota2) / 2;
    return a->media;
};

void imprimirAluno(struct Aluno *a) {
    printf("Nome: %s\n", a->nome);
    printf("Nota 1: %.2f\n", a->nota1);
    printf("Nota 2: %.2f\n", a->nota2);
    printf("Média das notas: %.2f\n", a->media);
};

int main() {
    struct Aluno alunos[50];

    for (int i = 0; i < 5; i++) {
        lerAluno(&alunos[i]);
    };

    for (int i = 0; i < 5; i++) {
        calcularMedia(&alunos[i]);
    };

    for (int i = 0; i < 5; i++) {
        imprimirAluno(&alunos[i]);
    };

    return 0;
};