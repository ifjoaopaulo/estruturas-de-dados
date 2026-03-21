#include <stdio.h>

// 4. Utilize o comando switch para criar um pequeno menu com 3 opções:
// 1 - Novo cadastro
// 2 - Consultar
// 3- Sair

int main() {
    int escolhaMenu;
    char nome[30];
    char pesquisaConsulta[50];

    do {
        printf("Escolha a ação que deseja realizar:\n");
        printf("1 - Novo cadastro\n");
        printf("2 - Consultar\n");
        printf("3 - Sair\n");
        scanf("%d", &escolhaMenu);

        switch (escolhaMenu) {
            case 1:
                printf("Informe o nome para caome[3dastro: ");
                scanf("%s", &nome);
                break;
        
            case 2:
                printf("Informe o que deseja consultar: ");
                scanf("%s", &pesquisaConsulta);
                break;
        
            default:
                printf("Saindo agora...\n");
        }
    }

    return 0;
}