#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "puzzle.h"

int main(void) {
    int tabuleiro[3][3];
    int vetor[9];

    gerar_tabuleiro_aleatorio(vetor);
    preencher_tabuleiro(vetor, tabuleiro);

    printf("Tabuleiro gerado:\n");
    imprimir_tabuleiro(tabuleiro);

    return 0;
}
