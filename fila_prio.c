#include <stdlib.h>
#include <stdio.h>
#include "fila_prio.h"

FilaPrio* criaFilaPrio(){
    FilaPrio *queue = (FilaPrio*) malloc(sizeof(FilaPrio));
    queue->inicio = NULL;
    return queue;
}


int FilaPrioVazio(FilaPrio *queue){
    return (queue->inicio == NULL);
}

void push_prio(FilaPrio *queue, Estado *e){
    NoPrio *novo = (NoPrio*) malloc(sizeof(NoPrio));
    novo->estado = e;
    novo->prox = NULL;

    if (queue->inicio == NULL || e->f < queue->inicio->estado->f){
        novo->prox = queue->inicio;
        queue->inicio = novo;
    } else {
        NoPrio *aux = queue->inicio;
        while (aux->prox != NULL && aux->prox->estado->f <= e->f){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

}

Estado* pop_prio(FilaPrio *queue){
    if (FilaPrioVazio(queue)){
            printf("\nFila de prioridade vazia, impossivel continuar.\n");
            exit(1);
    }

    NoPrio *aux =queue->inicio;
    Estado *e = aux->estado;
    queue->inicio = aux->prox;
    free(aux);
    return e;
}

void liberaFilaPrio(FilaPrio *queue) {
    NoPrio *aux = queue->inicio;
    while (aux != NULL) {
        NoPrio *prox = aux->prox;
        free(aux);
        aux = prox;
    }
    free(queue);
}
