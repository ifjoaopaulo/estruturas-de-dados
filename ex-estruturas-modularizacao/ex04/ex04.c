#include <stdio.h>

// Exercício 4 -- Agenda de Contatos

struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
};

void cadastrarContato(struct Contato *c) {
    printf("Informe o nome deste contato: ");
    scanf("%s", c->nome);

    printf("Informe o número de telefone a ser salvo: ");
    scanf("%s", c->telefone);

    printf("Informe o email deste contato: ");
    scanf("%s", c->email);
};

void listarContatos(struct Contato contatos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nome: %s\n", contatos[i].nome);
        printf("Número de telefone: %s\n", contatos[i].telefone);
        printf("Email: %s\n", contatos[i].email);
    };
};

int buscarContato(struct Contato contatos[], int n, char nome[]) {
    for (int i = 0; i < n; i++) {
        if (nome == contatos[i].nome) {
            listarContatos(contatos, 1);
        };
    };
};

int main() {
    struct Contato contatos[10];
    int escolhaAgenda;
    int index = 0;

    while (escolhaAgenda != 4) {
        printf("Bem-vindo a sua Agenda particular!\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Listar todos contatos\n");
        printf("3 - Buscar contato por nome\n");
        printf("4 - Sair");
        scanf("%d", &escolhaAgenda);

        switch (escolhaAgenda) {
            case 1:
                cadastrarContato(&contatos[index]);
                index++;
                break;
            
            case 2:
                listarContatos(contatos, index);
                break;

            case 3:
                char pesquisaNome[50];
                printf("Digite o nome que deseja pesquisar: ");
                scanf("%s", pesquisaNome);
                buscarContato(contatos, index, pesquisaNome);
                break;

            case 4:
                printf("Saindo agora...\n");

            default:
                printf("Ação inválida!\n");
    };

    return 0;
}