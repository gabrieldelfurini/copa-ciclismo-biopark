#include "funcoes.h"
#include <stdio.h>

// Fun��o principal para balancear a �rvore dinamicamente
ArvBin balancearArvore(ArvBin *raiz, int vaiOrdenarVetor) {

    // Criar uma lista para armazenar os valores da �rvore em ordem crescente
    no* lista = (no*)malloc(qtdDeIncricoes * sizeof(no));

    if (lista == NULL) {
        printf("Erro na aloca��o de mem�ria\n");
        exit(1);
    }

    int indexParaOVetor = 0;

    // Preencher a lista com os valores da �rvore
    preencherLista(*raiz, lista, &indexParaOVetor);

    //Aqui ele vai ordenar o vetor, se caso o usuario pedir
    if(vaiOrdenarVetor != 0){

        for(int index = 0; index < qtdDeIncricoes; index++){
            for(int index2 = index; index2 < qtdDeIncricoes; index2++){
                if(lista[index].numeroIncricao > lista[index2].numeroIncricao){
                    no temp = lista[index];
                    lista[index] = lista[index2];
                    lista[index2] = temp;
                }
            }
        }

        printf("\n\n");
    }

    // Construir a �rvore balanceada a partir da lista e j� atualizar a raiz
    (*raiz) = construirArvoreBalanceada(lista, 0, (qtdDeIncricoes) - 1);

    free(lista);

    return;
}
