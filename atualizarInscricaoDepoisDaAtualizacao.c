#include "funcoes.h"
#include <stdio.h>

// Fun��o para atualizar a quantidade da categoria depois de uma atualiza��o/exclus�o
void atualizarInscricaoDepoisDaAtualizacao(int numeroInscricao, int numeroCategoria, ArvBin raiz){
    ArvBin enderecoDoCiclistaParaAtualizar = NULL;

    //Armazena a categoria escolhida para futuros usos
    int *categoriaEscolhida = NULL;
    switch(numeroCategoria){
        case 1:
            categoriaEscolhida = &ctgElite;
            break;
        case 2:
            categoriaEscolhida = &ctgAte18;
            break;
        case 3:
            categoriaEscolhida = &ctg19_29;
            break;
        case 4:
            categoriaEscolhida = &ctg30_39;
            break;
        case 5:
            categoriaEscolhida = &ctgAcima40;
            break;
        default:
            printf("Categoria Invalida - Erro");
    }

    //Remover se for o ultimo
    if(numeroInscricao == (*categoriaEscolhida)){
        switch(numeroCategoria){
            case 1:
                ctgElite--;
                break;
            case 2:
                ctgAte18--;
                break;
            case 3:
                ctg19_29--;
                break;
            case 4:
                ctg30_39--;
                break;
            case 5:
                ctgAcima40--;
                break;
            default:
                printf("Categoria Invalida");
        }
    }else{
        //Entra aqui se n�o for o �ltimo numero de inscri��o da categoria

        //Atualizar os numeros de inscri��o de todos os ciclistas com numeros de inscri��o maiores que o numero de inscri��o atualizada/exlcu�da
        for(int index = numeroInscricao + 1; index <= (*categoriaEscolhida); index++){
            ArvBin ciclista = percorreInOrdem(raiz, numeroCategoria, index); // index = 2      (*categoriaEscolhida) = 2
            ciclista->numeroIncricao--;
        }
        (*categoriaEscolhida)--;
    }

    //Vai diminuir 1 unidade da quantidade total de inscri��es de ciclistas
    qtdDeIncricoes--;
    return 0;
}
