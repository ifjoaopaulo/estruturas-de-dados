#include <stdio.h>

// 1. Multiplicação por Somas

int multiplicar(int x, int y) {
        if (y == 1) {
            return x;
        }

    return x + multiplicar(x, y - 1);
}

int main() {
    int x = 3;
    int y = 5;

    printf("3 x 5 = %d\n", multiplicar(x, y));

    return 0;
}