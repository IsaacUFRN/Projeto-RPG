#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int rolarDado(int lados) {
    return rand() % lados + 1;
}

int lerInteiro() {
    int numero;

    if(scanf("%d", &numero) != 1) {
        while(getchar() != '\n');
        return -1;
    }

    while(getchar() != '\n');

    return numero;
}

void moverJogador(int *posicao, int passos, int tamanho) {
    *posicao += passos;

    if(*posicao >= tamanho) {
        *posicao = tamanho - 1;
    }
}
