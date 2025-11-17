#include <stdio.h>
#include "puzzle.h"
#include "busca_largura.h"

int main() {

    int tabuleiro[3][3];
    int vetor[9];
    char mov;
    int opcao;

    do {
        gerar_tabuleiro_aleatorio(vetor);
    } while(!eh_resolvivel(vetor));

    preencher_tabuleiro(vetor, tabuleiro);

    printf("\n====== 8-PUZZLE ======\n");
    printf("1 - Jogar manualmente\n");
    printf("2 - Resolver com IA (BFS)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {

        while (1) {
            imprimir_tabuleiro(tabuleiro);
            printf("Mover (W/A/S/D) ou X para sair: ");
            scanf(" %c", &mov);

            if (mov == 'X' || mov == 'x') break;

            mover_peca(tabuleiro, mov);

            if (estado_final(tabuleiro)) {
                imprimir_tabuleiro(tabuleiro);
                printf("\nPARABENS! Você resolveu o puzzle!\n");
                break;
            }
        }
    }

    else if (opcao == 2) {
        printf("\n--- Executando BFS ---\n");
        busca_largura(tabuleiro);
        printf("OLA TESTE");
    }

    else {
        printf("Opção inválida.\n");
    }

    return 0;
}
