#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "A_estrela.h"
#include "fila_prio.h"
#include "estado.h"
#include "puzzle.h"

void busca_Aestrela(int inicial[3][3]) {
    FilaPrio *fila = criaFilaPrio();

    Estado *estado_inicial = criar_estado(NULL, ' ', inicial);
    marcar_visitado(estado_inicial);
    push_prio(fila, estado_inicial);

    int visitados = 0;

    while (!FilaPrioVazio(fila)) {
        Estado *atual = pop_prio(fila);
        visitados++;

        if (estado_final(atual->matriz)) {
            printf("\n\n====== SOLUÇÃO ENCONTRADA (A*) ======\n");

            Estado *caminho[5000];
            int k = 0;

            while (atual != NULL) {
                caminho[k++] = atual;
                atual = atual->anterior;
            }

            printf("\nCaminho (do início ao fim):\n\n");
            for (int i = k - 1; i >= 0; i--) {
                imprimir_tabuleiro(caminho[i]->matriz);
                if (caminho[i]->movimento != ' ')
                    printf("Movimento: %c\n\n", caminho[i]->movimento);
            }
            printf("Estados visitados: %d\n", visitados);

            printf("=====================================\n");
            liberaFilaPrio(fila);
            return;
        }

        Estado *filhos[4];
        int qtd;
        gerar_filhos(atual, filhos, &qtd);

        for (int i = 0; i < qtd; i++) {
            if (filhos[i] != NULL && !foi_visitado(filhos[i])) {
                marcar_visitado(filhos[i]);
                push_prio(fila, filhos[i]);
            }
        }
    }

    printf("\nNenhuma solução encontrada com A*.\n");
    liberaFilaPrio(fila);
}
