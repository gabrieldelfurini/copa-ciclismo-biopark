#include "funcoes.h"
#include <stdio.h>

int libera_ArvBin(ArvBin* raiz) {
    if (raiz == NULL) { // se �rvore vazia
        return 0;
    } else {
        libera_NO(*raiz); // chama fun��o recursiva
    }
    free(raiz);
}
