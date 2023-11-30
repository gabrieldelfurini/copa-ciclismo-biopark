#include "funcoes.h"
#include <stdio.h>

// Fun��o para calcular a altura da �rvore
int alturaArvBin(ArvBin* raiz) {
    if (*raiz == NULL) {
        return -1;
    } else {
        int alturaEsquerda = alturaArvBin(&(*raiz)->esq);
        int alturaDireita = alturaArvBin(&(*raiz)->dir);

        return 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
    }
}
