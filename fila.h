#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "busca_largura.h"   

// ==============================
// Estrutura de um nó da fila
// ==============================
typedef struct No {
    Estado *estado;       // ponteiro para o estado do puzzle
    struct No *prox;      // prox nó
} No;

// ==============================
// Estrutura da fila
// ==============================
typedef struct {
    No *inicio;   
    No *fim;      
} Fila;



// Cria uma nova fila vazia
Fila* criar_fila();

// Retorna 1 se a fila vazia
int fila_vazia(Fila *fila);

// Adiciona um novo estado ao final da fila
void insere_fila(Fila *fila, Estado *estado);

// Remove e retorna o primeiro estado da fila
Estado* retira_fila(Fila *fila);


// free fila
void liberar_fila(Fila *fila);

#endif
