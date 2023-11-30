#include "funcoes.h"
#include <stdio.h>

void libera_NO(no *no_liberar) { // função recursiva para percorrer
    if (no_liberar == NULL) {
        return;
    } else {
        libera_NO(no_liberar->esq);
        libera_NO(no_liberar->dir);
        free(no_liberar);
    }
}
