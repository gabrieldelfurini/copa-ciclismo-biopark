#include "funcoes.h"
#include <stdio.h>

int libera_ArvBin(ArvBin* raiz) {
    if (raiz == NULL) { // se árvore vazia
        return 0;
    } else {
        libera_NO(*raiz); // chama função recursiva
    }
    free(raiz);
}
