#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "puzzle.h"

void gerar_tabuleiro_aleatorio(int vetor[9]) {
    srand(time(NULL));

    for (int i = 0; i < 9; i++)
        vetor[i] = i;

    for (int i = 0; i < 9; i++) {
        int j = rand() % 9;
        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }

    assert(vetor != NULL);
}

void preencher_tabuleiro(int vetor[9], int matriz[3][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            matriz[i][j] = vetor[k++];
}

void imprimir_tabuleiro(int matriz[3][3]) {
    printf("\n+---+---+---+\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] == 0
                ? printf("|   ")
                : printf("| %d ", matriz[i][j]);
        }
        printf("|\n+---+---+---+\n");
    }
}
