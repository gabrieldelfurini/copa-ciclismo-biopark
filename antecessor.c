#include "funcoes.h"
#include <stdio.h>

// Fun��o para encontrar o n� direito mais profundo da sua �rvore da esquerda
ArvBin antecessor(ArvBin no, ArvBin *ant) {
    ArvBin atual = no;

    // Percorre a �rvore para encontrar o n� mais � direita
    while (atual->dir != NULL) {
        *ant = atual;
        atual = atual->dir;
    }

    return atual;
}
