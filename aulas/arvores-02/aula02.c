#include <stdio.h>
#include "arvore.h"

struct No {
  int valor;
  struct No* esquerdo;
  struct No* direito;
}

struct No* criarNo(int valor) {
  struct No* novo = (struct No*) malloc(sizeof(struct No));
  novo->valor = valor;
  novo->esquerdo = NULL;
  novo->direito = NULL;
  return novo;
}

int main() {
  criarNo()
  printHelloWorld();
  return 0; 
} 
