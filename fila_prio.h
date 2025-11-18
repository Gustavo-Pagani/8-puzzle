#ifndef FILA_PRIO_H
#define FILA_PRIO_H
#include "estado.h"

typedef struct noPrio {
    Estado *estado;
        struct noPrio *prox;
} NoPrio;

typedef struct {
    NoPrio *inicio;
    NoPrio *fim;
} FilaPrio;

FilaPrio* criaFilaPrio();
int FilaPrioVazio(FilaPrio *f);
void push_prio(FilaPrio *f, Estado *e);
Estado* pop_prio(FilaPrio *f);
void liberaFilaPrio(FilaPrio *f);



#endif
