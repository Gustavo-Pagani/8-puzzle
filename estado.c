#include <stdlib.h>
#include "estado.h"
#include "puzzle.h"

void copiar_matriz(int origem[3][3], int destino[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            destino[i][j] = origem[i][j];
}

Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]) {
    Estado *novo_estado = (Estado*) malloc(sizeof(Estado));

    copiar_matriz(matriz_nova, novo_estado->matriz);

    novo_estado->anterior = pai;
    novo_estado->movimento = movimento;

    if (pai == NULL)
        novo_estado->profundidade = 0;
    else
        novo_estado->profundidade = pai->profundidade + 1;

    return novo_estado;
}

void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd) {

    int linha_zero, coluna_zero;
    achar_x(atual->matriz, &linha_zero, &coluna_zero);

    *qtd = 0;

    char movs[4] = {'W','A','S','D'};

    for (int i = 0; i < 4; i++) {

        int nl = linha_zero;
        int nc = coluna_zero;
        char m = movs[i];

        if (m == 'W' && nl > 0) {nl--;}
        else if (m == 'S' && nl < 2) {nl++;}
        else if (m == 'A' && nc > 0) {nc--;}
        else if (m == 'D' && nc < 2) {nc++;}
        else {continue;}

        int temp[3][3];
        copiar_matriz(atual->matriz, temp);

        int aux = temp[nl][nc];
        temp[nl][nc] = temp[linha_zero][coluna_zero];
        temp[linha_zero][coluna_zero] = aux;

        filhos[*qtd] = criar_estado(atual, m, temp);
        (*qtd)++;
    }
}
