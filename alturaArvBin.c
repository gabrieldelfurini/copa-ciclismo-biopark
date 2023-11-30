#include "funcoes.h"
#include <stdio.h>

// Função para calcular a altura da árvore
int alturaArvBin(ArvBin* raiz) {
    if (*raiz == NULL) {
        return -1;
    } else {
        int alturaEsquerda = alturaArvBin(&(*raiz)->esq);
        int alturaDireita = alturaArvBin(&(*raiz)->dir);

        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}
