#include <stdio.h>

// 3. Elabore um algoritmo que calcule a média de 4 notas e imprima se o aluno foi aprovado (média >= 6), reprovado ou em recuperação (média entre 4 e 5.9).

float mediaQuatroNotas(float a, float b, float c, float d) {
    float media = (a + b + c + d)/4;
    return media;
};

int main() {
    float nota1, nota2, nota3, nota4;
    printf("Informe a primeira nota: ");
    scanf("%f", &nota1);

    printf("Informe a segunda nota: ");
    scanf("%f", &nota2);

    printf("Informe a terceira nota: ");
    scanf("%f", &nota3);

    printf("Informe a quarta nota: ");
    scanf("%f", &nota4);

    float mediaFinal = mediaQuatroNotas(nota1, nota2, nota3, nota4);

    if (mediaFinal >= 6) {
        printf("Aluno aprovado\n");
    } else if (mediaFinal >= 4) {
        printf("Aluno em recuperação\n");
    } else {
        printf("Aluno reprovado\n");
    }

    return 0;
}