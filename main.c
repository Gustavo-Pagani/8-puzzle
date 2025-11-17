#include <stdio.h>
#include "puzzle.h"
#include "busca_largura.h"

int main() {

    int tabuleiro[3][3];
    int vetor[9];
    char mov;
    int opcao;

    // Gera apenas tabuleiros válidos
    do {
        gerar_tabuleiro_aleatorio(vetor);
    } while(!eh_resolvivel(vetor));

    preencher_tabuleiro(vetor, tabuleiro);

    printf("\n======================================\n");
    printf("              8-PUZZLE                \n");
    printf("======================================\n");
    printf("1 - Jogar manualmente\n");
    printf("2 - Resolver com IA (BFS)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    //   OPÇÃO 1: JOGAR MANUALMENTE
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
                printf("       PARABENS! Puzzle Resolvido!     \n");
                printf("======================================\n");
                break;
            }
        }
    }

    //   OPÇÃO 2: RESOLVER COM BFS
    else if (opcao == 2) {
        printf("\n======================================\n");
        printf("          EXECUTANDO BFS...           \n");
        printf("======================================\n\n");
        busca_largura(tabuleiro);
    }


    else {
        printf("\nOpcao invalida.\n");
    }

    return 0;
}
