#include <stdio.h>
#include "busca_largura.h"
#include "fila.h"
#include "estado.h"
#include "puzzle.h"
int visitado[362880] = {0};

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

void busca_largura(int inicial[3][3]){
    Fila *fila = criar_fila();

    Estado *estado_inicial = criar_estado(NULL, ' ', inicial);
    marcar_visitado(estado_inicial);
    insere_fila(fila, estado_inicial);

    int visitados = 0;

    while (!fila_vazia(fila)){
        Estado *atual = retira_fila(fila);
        visitados++;

        if (estado_final(atual->matriz)){
            printf("\nSolucao encontrada!\n");
            printf("Estados Visitados: %d\n\n", visitados);

            Estado *caminho[5000];
            int k = 0;

            while (atual != NULL){
                caminho[k++] = atual;
                atual = atual->anterior;
            }

            for (int i=k-1; i>=0; i--){
                imprimir_tabuleiro(caminho[i]->matriz);
            }

            return;
        }
        Estado *filhos[4];
        int qtd = 0;

        gerar_filhos(atual, filhos, &qtd);

        for (int i=0; i<qtd; i++){

                if (!foi_visitado(filhos[i]))
                {
                    marcar_visitado(filhos[i]);
                    insere_fila(fila, filhos[i]);
                }
        }
    }

    printf("\nSEM SOLUCAO.\n");

}
