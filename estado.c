#include <stdlib.h>
#include "estado.h"
#include "puzzle.h"


void copiar_matriz(int origem[3][3], int destino[3][3]){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            destino[i][j] = origem[i][j];
        }
    }
}

Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]){
    Estado *novo_estado = (Estado*) malloc(sizeof(novo_estado));
    copiar_matriz(matriz_nova, novo_estado->matriz);
    novo_estado->anterior = pai;
    novo_estado->movimento = movimento;

    if (pai == NULL){
        novo_estado->profundidade = 0;
    }
    else{
        novo_estado->profundidade =pai->profundidade + 1;
    }
    return novo_estado;
}

void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd){
    int linha_X, coluna_X;
    achar_x(atual->matriz, &linha_X, &coluna_X);
    qtd = 0;

    char movimentos[4] = {'W', 'A', 'S', 'D'};
    for (int i=0; i<4; i++){
        char mov = movimentos[i];
        int nova_linha = linha_X;
        int nova_coluna = coluna_X;

        if (mov == 'W' && nova_linha > 0) {nova_linha--;}
        else if (mov == 'S' && nova_linha < 2) {nova_linha++;}
        else if (mov == 'A' && nova_coluna > 0) {nova_coluna--;}
        else if (mov == 'D' && nova_coluna < 2) {nova_coluna++;}
        else {continue;}

        int matriz_temp[3][3];
        copiar_matriz(atual->matriz, matriz_temp);

        int aux = matriz_temp[nova_linha][nova_coluna];
        matriz_temp[nova_linha][nova_coluna] = matriz_temp[linha_X][coluna_X];
        matriz_temp[linha_X][coluna_X] = aux;

        Estado *novo = criar_estado(atual, mov, matriz_temp);

        filhos[*qtd] = novo;
        (*qtd)++;
    }


}

