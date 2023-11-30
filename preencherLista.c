#include "funcoes.h"
#include <stdio.h>

// Fun��o auxiliar para preencher uma lista com os valores da �rvore em ordem crescente
void preencherLista(ArvBin raiz, no* lista, int* index) {
    if (raiz != NULL) {
        preencherLista(raiz->esq, lista, index); // Percorre a sub�rvore esquerda
        lista[*index] = *raiz; // Armazena a estrutura do n� no vetor
        (*index)++;
        preencherLista(raiz->dir, lista, index); // Percorre a sub�rvore direita
    }
}
