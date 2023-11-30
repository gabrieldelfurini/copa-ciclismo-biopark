#include "funcoes.h"
#include <stdio.h>

// Função auxiliar para criar uma árvore balanceada a partir de uma lista ordenada
ArvBin construirArvoreBalanceada(no* lista, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;

    // Criar o nó com o valor do meio da lista
    no* novo = (no*)malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro na alocação de memória\n");
        exit(1);
    }

    *novo = lista[meio];
    novo->esq = NULL;
    novo->dir = NULL;

    // Construir recursivamente as subárvores esquerda e direita
    novo->esq = construirArvoreBalanceada(lista, inicio, meio - 1);
    novo->dir = construirArvoreBalanceada(lista, meio + 1, fim);

    return novo;
}
