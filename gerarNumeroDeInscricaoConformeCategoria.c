#include "funcoes.h"
#include <stdio.h>

int gerarNumeroDeInscricaoConformeCategoria(int categoriaDoCiclista){
    //(Nome da função se autoexplica)
    switch(categoriaDoCiclista){
        case 1:
            ctgElite++;
            return ctgElite;
            break;
        case 2:
            ctgAte18++;
            return ctgAte18;
            break;
        case 3:
            ctg19_29++;
            return ctg19_29;
            break;
        case 4:
            ctg30_39++;
            return ctg30_39;
            break;
        case 5:
            ctgAcima40++;
            return ctgAcima40;
            break;
        default:
            printf("Categoria Invalida");
    }
}
