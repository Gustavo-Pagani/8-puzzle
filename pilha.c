#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int vaziaPilha(Pilha *p) {
    return (p->topo == NULL);
}

Pilha* CriaPilha() {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

No* insere_inicio(No* topo, Estado *valor) {
    No* aux = (No*) malloc(sizeof(No));
    aux->info = valor;
    aux->prox = topo;
    return aux;
}

void push(Pilha* p, Estado *e) {
    p->topo = insere_inicio(p->topo, e);
}

No* retira_inicio(No* topo) {
    No* prox = topo->prox;
    free(topo);
    return prox;
}

Estado* pop(Pilha *p) {
    if (vaziaPilha(p)) {
        printf("\n\n==> Pilha VAZIA, impossivel continuar.\n");
        exit(1);
    }

    Estado *v = p->topo->info;
    p->topo = retira_inicio(p->topo);
    return v;
}

Pilha* liberaPilha(Pilha *p) {
    No *q = p->topo;
    while (q != NULL) {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return NULL;
}

void imprimePilha(Pilha *p) {
    if (vaziaPilha(p)) {
        printf("\n\nPilha vazia!\n\n");
        return;
    }

    printf("\n\nImpressão da Pilha: ");
    for (No* q = p->topo; q != NULL; q = q->prox) {
        printf("[%p] ", (void*)q->info);
    }
    printf("\n\n");
}
