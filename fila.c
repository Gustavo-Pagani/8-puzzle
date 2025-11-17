#include <stdlib.h>
#include "fila.h"

Fila* criar_fila() {
    Fila *f = malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insere_fila(Fila *fila, Estado *estado) {
    No *novo = malloc(sizeof(No));
    novo->estado = estado;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }
}

Estado* retira_fila(Fila *fila) {
    if (fila->inicio == NULL) return NULL;

    No *rem = fila->inicio;
    Estado *e = rem->estado;

    fila->inicio = rem->prox;
    free(rem);

    return e;
}

int fila_vazia(Fila *fila) {
    return (fila->inicio == NULL);
}
