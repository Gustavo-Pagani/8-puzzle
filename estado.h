#ifndef ESTADO_H
#define ESTADO_H

typedef struct Estado{
    int matriz[3][3];
    struct Estado *anterior;
    char movimento;
    int profundidade;
} Estado;

void copiar_matriz(int origem[3][3], int destino[3][3]);
Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]);
void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd);

void matriz_para_vetor(int matriz[3][3], int vetor[9]);
int fatorial(int n);
int codigo_matriz(int v[9]);

int codigo_do_estado(Estado *e);

int foi_visitado(Estado *e);

void marcar_visitado(Estado *e);

#endif
