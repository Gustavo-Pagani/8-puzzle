#ifndef BUSCA_LARGURA_H
#define BUSCA_LARGURA_H
#include "estado.h"
void busca_largura(int inicial[3][3]);

void marcar_visitado(Estado *e);

int foi_visitado(Estado *e);

int codigo_do_estado(Estado *e);
#endif
