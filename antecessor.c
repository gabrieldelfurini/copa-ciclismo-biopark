#include "funcoes.h"
#include <stdio.h>

// Função para encontrar o nó direito mais profundo da sua árvore da esquerda
ArvBin antecessor(ArvBin no, ArvBin *ant) {
    ArvBin atual = no;

    // Percorre a árvore para encontrar o nó mais à direita
    while (atual->dir != NULL) {
        *ant = atual;
        atual = atual->dir;
    }

    return atual;
}
