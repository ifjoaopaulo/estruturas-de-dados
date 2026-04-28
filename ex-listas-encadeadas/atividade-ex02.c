#include <stdio.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

int contadorIterativo = 0;
int contarCelulasIterativo() {

}

int contadorRecursivo = 0;
int contarCelulasRecursivo(celula *le) {
    if (le != NULL) {
        contadorRecursivo += 1;
        contarCelulasRecursivo(le->prox);
    } else {
        return contadorRecursivo;
    }
}

int main() {
    celula = NULL;

    printf("Quantidade de células (recursivo): %d\n", contarCelulasRecursivo());

    return 0;
}