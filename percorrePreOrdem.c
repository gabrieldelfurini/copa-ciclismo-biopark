#include "funcoes.h"
#include <stdio.h>

// Função para percorrer a árvore pre-orden
void percorrePreOrdem(ArvBin raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->numeroIncricao); // Visita a raiz
        percorrePreOrdem(raiz->esq); // Percorre a subárvore esquerda
        percorrePreOrdem(raiz->dir); // Percorre a subárvore direita
    }
}
