#include <stdio.h>

// 11. (Desafio) Faça um programa que leia uma string e use ponteiros para contar quantas vogais ela contém.

int contadorVogais(char *p) {
    int quantidadeVogais = 0;

    while (*p != '\0') {
        switch (*p) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
            case 'A': case 'E': case 'I': case 'O': case 'U':
                quantidadeVogais++;
                break;
            
            default:
                break;
        };
        p++;
    };

    return quantidadeVogais;
}

int main() {
    char string[30];
    int resultado;
    printf("Insira uma palavra: ");
    scanf(" %s", &string);

    resultado = contadorVogais(string);
    printf("A quantidade de vogais é: %d\n", resultado);

    return 0;
}