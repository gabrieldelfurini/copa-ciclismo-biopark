#include "funcoes.h"
#include <stdio.h>

// Fun��o para percorrer a �rvore pre-orden
void percorrePreOrdem(ArvBin raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->numeroIncricao); // Visita a raiz
        percorrePreOrdem(raiz->esq); // Percorre a sub�rvore esquerda
        percorrePreOrdem(raiz->dir); // Percorre a sub�rvore direita
    }
}
