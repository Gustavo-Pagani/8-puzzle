#include <stdlib.h>
#include <stdio.h>
#include "estado.h"
#include "puzzle.h"
int visitado[362880] = {0};

void copiar_matriz(int origem[3][3], int destino[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            destino[i][j] = origem[i][j];
        }
    }
}

int comparar_matrizes(int a[3][3], int b[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != b[i][j]) {
                return 0;   // diferente
            }
        }
    }
    return 1;               // iguais
}

Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]){
    Estado *novo_estado = (Estado*) malloc(sizeof(Estado));

    copiar_matriz(matriz_nova, novo_estado->matriz);

    novo_estado->anterior = pai;
    novo_estado->movimento = movimento;

    if (pai == NULL){
        novo_estado->profundidade = 0;
    }
    else {
        novo_estado->profundidade = pai->profundidade +1;
    }

    return novo_estado;
}

void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd){
    int linha_zero, coluna_zero;
    achar_x(atual->matriz, &linha_zero, &coluna_zero);

    *qtd = 0;

    char movs[4] = {'W', 'A', 'S', 'D'};

    for (int i=0; i<4; i++){
        int nova_linha = linha_zero;
        int nova_coluna = coluna_zero;
        char move = movs[i];

        if      (move == 'W' && nova_linha > 0) {nova_linha--;}
        else if (move == 'S' && nova_linha < 2) {nova_linha++;}
        else if (move == 'A' && nova_coluna > 0) {nova_coluna--;}
        else if (move == 'D' && nova_coluna < 2) {nova_coluna++;}
        else {continue;}

        int temp[3][3];
        copiar_matriz(atual->matriz, temp);

        int aux = temp[nova_linha][nova_coluna];
        temp[nova_linha][nova_coluna] = temp[linha_zero][coluna_zero];
        temp[linha_zero][coluna_zero] = aux;

        filhos[*qtd] = criar_estado(atual, move, temp);
        (*qtd)++;
     }
}

void matriz_para_vetor(int matriz[3][3], int vetor[9]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            vetor[k++] = matriz[i][j];
        }
    }
}

int fatorial(int n) {
    int r = 1;
    for (int i = 2; i <= n; i++) {
        r *= i;
    }
    return r;
}

int codigo_matriz(int v[9]) {
    int cod = 0;

    for (int i = 0; i < 9; i++) {
        int count = 0;

        for (int j = i + 1; j < 9; j++) {
            if (v[j] < v[i]) {
                count++;
            }
        }

        cod += count * fatorial(8 - i);
    }

    return cod;
}

int codigo_do_estado(Estado *e){
    int v[9];
    matriz_para_vetor(e->matriz, v);
    return codigo_matriz(v);
}

int foi_visitado(Estado *e){
    int cod = codigo_do_estado(e);
    return visitado[cod];
}

void marcar_visitado(Estado *e){
    int cod = codigo_do_estado(e);
    visitado[cod] = 1;
}



