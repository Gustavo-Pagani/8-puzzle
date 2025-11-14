#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "puzzle.h"
#include "busca_largura.h"

int main(){
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
    printf("3 - Resolver com IA (DFS)\n");
    printf("4 - Resolver com IA (A*)\n");

    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1){
        
        while(1) {
            imprimir_tabuleiro(tabuleiro);
            printf("Mover (W/A/S/D) ou X para desistir: ");
            scanf(" %c", &mov);

            if (mov == 'X' || mov == 'x'){break;}

            if (estado_final(tabuleiro)){
                imprimir_tabuleiro(tabuleiro);
                printf("\nPARABENS ! Voce resolveu o puzzle!\n");
                break;
            }
        }
    }

    else if (opcao == 2){
        printf("\n\n--- Executando Busca em Largura (BFS) ---\n");
        busca_largura(tabuleiro);
    }

    else if (opcao == 3){
        printf("\n\n--- Executando Busca em Profundiade (DFS) ---\n");
    }

    else if (opcao == 4){
        printf("\n\n--- Executando Busca A Estrela (A*)---\n");
    }

    else {
        printf("Opcao invalida.\n");
    }

    return 0;
}