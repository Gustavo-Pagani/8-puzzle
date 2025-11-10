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
            matriz[i][j] == 0    ? printf("| X ")  : printf("| %d ", matriz[i][j]);
        }
        printf("|\n+---+---+---+\n");
    }
}

void achar_x(int matriz[3][3], int *linha_X, int *coluna_X){
    for (int i=0; i <3; i++){
        for (int j=0; j<3; j++){
            if (matriz[i][j] == 0){
                *linha_X = i;
                *coluna_X = j;
            }
        }
    }
}

void mover_peca(int matriz[3][3], char direcao){

    int linha_X, coluna_X;
    achar_x(matriz, &linha_X, &coluna_X);

    int nova_linha = linha_X;
    int nova_coluna = coluna_X;

    if (direcao == 'W' || direcao == 'w') {nova_linha--;}

    else if (direcao == 'S' || direcao == 's') {nova_linha++;}

    else if (direcao == 'A' || direcao == 'a') {nova_coluna--;}

    else if (direcao == 'D' || direcao == 'd') {nova_coluna++;}

    else {
        printf("Movimento invalido!\n");
    
    }

    if (nova_linha < 0 || nova_linha > 2 || nova_coluna < 0 || nova_coluna > 2) {
        printf("Nao e possivel mover nessa direcao!\n");
    
    }

    int aux = matriz[nova_linha][nova_coluna];
    matriz[nova_linha][nova_coluna] = matriz[linha_X][coluna_X];
    matriz[linha_X][coluna_X] = aux;
}

int estado_final(int matriz[3][3]) {
    int alvo[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] != alvo[i][j])
                return 0; // ainda não está resolvido
        }
    }
    return 1; //  resolvido
}

int eh_resolvivel(int vetor[9]) {
    int inversoes = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 9; j++) {
            // ignorar o zero (espaço vazio)
            if (vetor[i] != 0 && vetor[j] != 0 && vetor[i] > vetor[j]) {
                inversoes++;
            }
        }
    }

    // se o número de inversões for par → resolvível
    return (inversoes % 2 == 0);
}





