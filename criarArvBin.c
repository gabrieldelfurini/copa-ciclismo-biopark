#include "funcoes.h"
#include <stdio.h>

// Criar o ponteiro para a raiz da �rvore
ArvBin* criarArvBin() {
    // Aloca ponteiro raiz da �rvore
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));

    if(raiz != NULL) {
        *raiz = NULL;
    } else {
        printf("Erro na aloca��o...\n");
        exit(0);
    }

    return raiz;
}
