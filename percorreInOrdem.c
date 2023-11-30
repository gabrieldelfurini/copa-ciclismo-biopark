#include "funcoes.h"
#include <stdio.h>

// Função para percorrer a árvore, para printar os elementos OU para retornar o Nó desejado
ArvBin percorreInOrdem(ArvBin raiz, int index, int numeroInscricaoParaAtualizarCiclista) {
    ArvBin ant = NULL;

    if (raiz != NULL) {
        ant = raiz;
        ArvBin encontrado = percorreInOrdem(raiz->esq, index, numeroInscricaoParaAtualizarCiclista); // Percorre a subárvore esquerda

        //Confere se é pra mandar o endereço de memoria do ciclista para atualizar
        if (numeroInscricaoParaAtualizarCiclista != 0) {
            if (numeroInscricaoParaAtualizarCiclista == raiz->numeroIncricao) {
                return raiz;
            }
        } else {
            // Printa os ciclista de acordo com a categoria
            if (raiz->categoria == index) {
                printf("Numero de Inscricao: %d | Nome: %s | Categoria: ", raiz->numeroIncricao, raiz->nome); // Visita a raiz
                switch (index) {
                case 1:
                    printf("Elite\n");
                    break;
                case 2:
                    printf("Ate 18 anos\n");
                    break;
                case 3:
                    printf("De 19 a 29 anos\n");
                    break;
                case 4:
                    printf("De 30 a 39 anos\n");
                    break;
                case 5:
                    printf("Acima de 40 anos\n");
                    break;
                default:
                    printf("Categoria Invalida\n");
                }
            }
        }
        if (encontrado != NULL) {
            return encontrado;
        }
        return percorreInOrdem(raiz->dir, index, numeroInscricaoParaAtualizarCiclista); // Percorre a subárvore direita
    }
    return NULL;
}
