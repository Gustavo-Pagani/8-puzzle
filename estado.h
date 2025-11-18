#ifndef ESTADO_H
#define ESTADO_H

typedef struct Estado {
    int matriz[3][3];
    struct Estado *anterior;
    char movimento;

    int profundidade;
    int g;                  // Custo do caminho
    int h;                  // Custo Estimado
    int f;                  // f = g + h (usado no A*)
} Estado;



Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]);



void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd);



int heuristica_manhattan(int matriz[3][3]);


int foi_visitado(Estado *e);
void marcar_visitado(Estado *e);



int codigo_do_estado(Estado *e);
int codigo_matriz(int v[9]);

#endif
