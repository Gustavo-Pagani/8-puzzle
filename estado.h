#ifndef ESTADO_H
#define ESTADO_H

#include "busca_largura.h"

void copiar_matriz(int origem[3][3], int destino[3][3]);
Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]);
void gerar_filhos(Estado *atual, Estado *filhos[4], int *qtd);

#endif
