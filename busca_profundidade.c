#include <stdio.h>
#include "busca_profundidade.h"
#include "pilha.h"
#include "estado.h"
#include "puzzle.h"

void busca_profundidade(int inicial[3][3]){
    Pilha *pilha = CriaPilha();

    Estado *estado_inicial = criar_estado(NULL, ' ', inicial);
    marcar_visitado(estado_inicial);
    push(pilha, estado_inicial);

    int visitados = 0;

    while (!vaziaPilha(pilha)){
         Estado *atual = pop(pilha);
         visitados++;

         // Achou a solução
         if (estado_final(atual->matriz)){

            printf("\nSolução encontrada!\n");
            printf("Estados visitados: %d\n\n", visitados);

            // Reconstruir caminho igual ao BFS
            Estado *caminho[5000];
            int k = 0;

            while (atual != NULL) {
                caminho[k++] = atual;
                atual = atual->anterior;
            }

            // Imprimir caminho do início ao fim
            for (int i = k - 1; i >= 0; i--) {
                imprimir_tabuleiro(caminho[i]->matriz);
            }
            printf("Estados visitados: %d\n\n", visitados);
            return;
         }

        // Gerar filhos
        Estado *filhos[4];
        int qtd = 0;

        gerar_filhos(atual, filhos, &qtd);

        for (int i = 0; i < qtd; i++){
            if (!foi_visitado(filhos[i])) {
                marcar_visitado(filhos[i]);
                push(pilha, filhos[i]);
            }
        }
    }

    printf("\nSem solução\n");
}
