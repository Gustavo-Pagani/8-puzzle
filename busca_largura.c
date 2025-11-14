#include <stdio.h>
#include <stdlib.h>
#include "busca_largura.h"
#include "fila.h"
#include "estado.h"
#include "puzzle.h"

void busca_largura(int inicial[3][3]) {

    Fila *fila = criar_fila();
    Estado *estado_inicial = criar_estado(NULL, ' ', inicial);

    insere_fila(fila, estado_inicial);
    int visitados = 0;

    while (!fila_vazia(fila)){
        Estado *atual = retira_fila(fila);
        visitados++;

        if(estado_final(atual->matriz)){
            printf("\nSolucao encontrada!\n");
            printf("Estados visitados: %d\n\n", visitados);

            Estado *caminho[1000];
            int K =0;
            while (atual != NULL){
                caminho[K++] = atual;
                atual = atual->anterior;
            }
            for (int i= K-1; i>=0; i--){
                imprimir_tabuleiro(caminho[i]->matriz);
            }
            return;
        }
        Estado *filhos[4];
        int qtd =0;
        gerar_filhos(atual, filhos, &qtd);

        for (int i=0; i<qtd; i++){

            insere_fila(fila,filhos[i]);
        }
        
        
    }
}
