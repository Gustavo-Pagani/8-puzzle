#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "puzzle.h"
#include "busca_profundidade.h"

int main(void) {
    int tabuleiro[3][3];
    int vetor[9];
    char mov;
    do {

        gerar_tabuleiro_aleatorio(vetor);
    } while (!eh_resolvivel(vetor));

    preencher_tabuleiro(vetor, tabuleiro);

    while(1){

        imprimir_tabuleiro(tabuleiro);
        printf("Mover (W/A/S/D) ou x para sair: ");
        scanf(" %c",&mov);

        if (mov == 'X' || mov == 'x'){ break;}

        mover_peca(tabuleiro, mov);

        if (estado_final(tabuleiro)){
            imprimir_tabuleiro(tabuleiro);
            printf("\nPARABENS, Você resolveu o puzzle!!.");
            break;
        }

    }

    return 0;
}
