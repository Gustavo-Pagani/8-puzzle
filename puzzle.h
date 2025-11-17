#ifndef PUZZLE_H
#define PUZZLE_H


void gerar_tabuleiro_aleatorio(int vetor[9]);

void preencher_tabuleiro(int vetor[9], int matriz[3][3]);

void imprimir_tabuleiro(int matriz[3][3]);

void achar_x(int matriz[3][3], int *linha_X, int *coluna_X);

void mover_peca(int matriz[3][3], char direcao);

int estado_final(int matriz[3][3]);

int eh_resolvivel(int vetor[9]);


#endif
