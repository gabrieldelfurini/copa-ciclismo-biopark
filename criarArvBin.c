#include "funcoes.h"
#include <stdio.h>

// Criar o ponteiro para a raiz da árvore
ArvBin* criarArvBin() {
    // Aloca ponteiro raiz da árvore
    ArvBin *raiz = (ArvBin*) malloc(sizeof(ArvBin));

    if(raiz != NULL) {
        *raiz = NULL;
    } else {
        printf("Erro na alocação...\n");
        exit(0);
    }

    return raiz;
}
