#include <stdio.h>

// Exercício 3 -- Cadastro de Funcionários

struct Funcionario {
    int id;
    char nome[50];
    float salarioBruto;
    float desconto;
    float salarioLiquido;
};

void lerFuncionario(struct Funcionario *f) {
    printf("Informe o nome do funcionário: ");
    scanf("%s", f->nome);

    printf("Informe o ID do funcionário: ");
    scanf("%d", &f->id);

    printf("Informe o salário bruto do funcionário: ");
    scanf("%f", &f->salarioBruto);
};

float calcularSalarioLiquido(struct Funcionario *f) {
    printf("Informe o desconto a ser aplicado sobre o salário deste funcionário: ");
    scanf("%f", &f->desconto);

    f->salarioLiquido = f->salarioBruto - (f->salarioBruto * f->desconto);
};

void imprimirFuncionario(struct Funcionario *f) {
    printf("\n");
    printf("Nome do funcionário: %s\n", f->nome);
    printf("ID: %d\n", f->id);
    printf("Salário bruto: %.2f\n", f->salarioBruto);
    printf("Salário líquido: %.2f\n", f->salarioLiquido);
    printf("Desconto aplicado sobre o salário bruto: %.2f\n", f->desconto);
};

int main() {
    struct Funcionario funcionarios[50];

    for (int i = 0; i < 3; i++) {
        lerFuncionario(&funcionarios[i]);
        calcularSalarioLiquido(&funcionarios[i]);
    };

    for (int i = 0; i < 3; i++) {
        imprimirFuncionario(&funcionarios[i]);
    };

    return 0;
}