#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

Fila* criar_fila() {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere_fila(Fila *fila, Estado *estado) {
    No *novo_no = malloc(sizeof(No));
    novo_no->estado = estado;
    novo_no->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo_no;
        fila->fim = novo_no;
    } else {
        fila->fim->prox = novo_no;  //conecta ultimo nó ao novo_no
        fila->fim = novo_no;
    }
}

Estado* retira_fila(Fila *fila) {
    if (fila->inicio == NULL) {return NULL;}

    No *removido = fila->inicio;
    Estado *e = removido->estado;

    fila->inicio = removido->prox;
    free(removido);

    return e;
}

int fila_vazia(Fila *fila) {
    return (fila->inicio == NULL);
}

