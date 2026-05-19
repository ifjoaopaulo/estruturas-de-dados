#include <stdio.h>

typedef struct {
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

struct fila {
    int inicio;
    int final;
    int qtd;
    Aluno dados[MAX];
} Fila;

Fila* criaFila() {

    Fila *fi;

    fi = (Fila*) malloc(sizeof(struct fila));

    if(fi != NULL) {
        fi->inicio = 0;
        fi->final = 0;
        fi->qtd = 0;
    }

    return fi;
}

int insereFila(Fila* fi, Aluno al) {

    if(fi == NULL)
        return 0;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if(no == NULL)
        return 0;

    no->dados = al;
    no->prox = NULL;

    if((*fi) == NULL) {

        *fi = no;

    } else {

        Elem *aux = *fi;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = no;
    }

    return 1;
}

void imprimeFila(Fila* fi) {
    
}

int main() {
    Fila* fila = criarFila();

    Aluno aluno1, aluno2, aluno3;

    aluno1.matricula = 101;
    aluno1.nome = Joao;
    aluno1.n1 = 9.5;
    aluno1.n2 = 8;
    aluno1.n3 = 7.8;

    aluno2.matricula = 102;
    aluno2.nome = Clara;
    aluno2.n1 = 9;
    aluno2.n2 = 9.4;
    aluno2.n3 = 6;

    aluno3.matricula = 103;
    aluno3.nome = Luiz;
    aluno3.n1 = 4;
    aluno3.n2 = 3;
    aluno3.n3 = 10;

    insereFila(&fila, aluno1);
    insereFila(&fila, aluno2);
    insereFila(&fila, aluno3);

    imprimeFila(&fila);

    return 0;
}