#ifndef PILHA_H
#define PILHA_H

#include "estado.h"

typedef struct no {
    Estado *info;
    struct no *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

Pilha* CriaPilha();
int vaziaPilha(Pilha *p);
void push(Pilha *p, Estado *e);
Estado* pop(Pilha *p);
Pilha* liberaPilha(Pilha *p);
void imprimePilha(Pilha *p);

#endif
