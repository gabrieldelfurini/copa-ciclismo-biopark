#include "funcoes.h"
#include <stdio.h>

// Função auxiliar para preencher uma lista com os valores da árvore em ordem crescente
void preencherLista(ArvBin raiz, no* lista, int* index) {
    if (raiz != NULL) {
        preencherLista(raiz->esq, lista, index); // Percorre a subárvore esquerda
        lista[*index] = *raiz; // Armazena a estrutura do nó no vetor
        (*index)++;
        preencherLista(raiz->dir, lista, index); // Percorre a subárvore direita
    }
}
