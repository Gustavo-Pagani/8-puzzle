#ifndef FILA_H
#define FILA_H

#include "estado.h"

typedef struct No {
    Estado *estado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

Fila* criar_fila();
void insere_fila(Fila *fila, Estado *estado);
Estado* retira_fila(Fila *fila);
int fila_vazia(Fila *fila);

#endif
