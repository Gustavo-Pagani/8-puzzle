#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "puzzle.h"
#include "busca_largura.h"
#include "busca_profundidade.h"

int main() {

    srand(time(NULL));

    int tabuleiro[3][3];
    int vetor[9];
    char mov;
    int opcao;

    // Gera somente tabuleiros válidos
    do {
        gerar_tabuleiro_aleatorio(vetor);
    } while(!eh_resolvivel(vetor));

    preencher_tabuleiro(vetor, tabuleiro);

    printf("\n======================================\n");
    printf("              8-PUZZLE                \n");
    printf("======================================\n");
    printf("1 - Jogar manualmente\n");
    printf("2 - Resolver com IA (BFS)\n");
    printf("3 - Resolver com IA (DFS)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    // ----- OPÇÃO 1: JOGAR MANUALMENTE -----
    if (opcao == 1) {

        while (1) {
            imprimir_tabuleiro(tabuleiro);
            printf("Mover (W/A/S/D) ou X para sair: ");
            scanf(" %c", &mov);

            if (mov == 'X' || mov == 'x') break;

            mover_peca(tabuleiro, mov);

            if (estado_final(tabuleiro)) {
                imprimir_tabuleiro(tabuleiro);
                printf("\n======================================\n");
                printf("       PARABENS! Puzzle Resolvido!    \n");
                printf("======================================\n");
                break;
            }
        }
    }

    // ----- OPÇÃO 2: BFS -----
    else if (opcao == 2) {
        printf("\n======================================\n");
        printf("          EXECUTANDO BFS...           \n");
        printf("======================================\n\n");

        busca_largura(tabuleiro);
    }

    // ----- OPÇÃO 3: DFS -----
    else if (opcao == 3) {
        printf("\n======================================\n");
        printf("          EXECUTANDO DFS...           \n");
        printf("======================================\n\n");

        busca_profundidade(tabuleiro);
    }

    // Opção inválida
    else {
        printf("\nOpcao invalida.\n");
    }

    return 0;
}
