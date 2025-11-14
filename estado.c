#include <stdlib.h>
#include <assert.h>
#include "estado.h"
#include "puzzle.h"

void copiar_matriz(int origem[3][3], int destino[3][3]){
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            destino[i][j] = origem[i][j];
        }
    }
}

Estado* criar_estado(Estado *pai, char movimento, int matriz_nova[3][3]);
