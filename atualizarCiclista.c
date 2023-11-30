#include "funcoes.h"
#include <stdio.h>

// Função para atualizar os dados dos ciclistas
int atualizarCiclista(ArvBin raiz){
    system("cls");
    printf("==================================== ATUALIZAR UM CICLISTA ===================================\n");

    if (raiz == NULL) {
        printf("\nNunhum ciclista cadastrado!\n\n");
    }else{

        int numeroInscricaoCiclista, escolhaInformacaoParaAtualizar;
        ArvBin enderecoDoCiclistaParaAtualizar = NULL;

        //Mostra os ciclista cadastrados
        printf("\n");
        for(int index = 1; index < 6; index++){
            percorreInOrdem(raiz, index,0);
        }
        printf("\nDigite o numero da inscricao do ciclista: ");
        scanf("%d", &numeroInscricaoCiclista);

        // Percorre a árvore para encontrar o endereço de memória do ciclista
        for(int index = 1; index < 6; index++){
            enderecoDoCiclistaParaAtualizar = percorreInOrdem(raiz, index, numeroInscricaoCiclista);
            if(enderecoDoCiclistaParaAtualizar != NULL){
                break;
            }
        }

        // Atualiza as informações do ciclista
        if (enderecoDoCiclistaParaAtualizar != NULL) {
            printf("\nATUALIZACAO:\n");
            printf("Numero de Inscricao: %d | Nome: %s | Categoria: %d", enderecoDoCiclistaParaAtualizar->numeroIncricao, enderecoDoCiclistaParaAtualizar->nome,enderecoDoCiclistaParaAtualizar->categoria);

            printf("\n1 - Nome\n2 - Categoria\nDigite qual informacao voce deseja atualizar: ");
            scanf("%d", &escolhaInformacaoParaAtualizar);

            while(escolhaInformacaoParaAtualizar != 1 && escolhaInformacaoParaAtualizar != 2){
                printf("\nOpcao Invalida. Digite uma valida: ");
                scanf("%d", &escolhaInformacaoParaAtualizar);
            }

            switch(escolhaInformacaoParaAtualizar){
                case 1:
                    printf("\nDigite o novo nome: ");
                    scanf(" %[^\n]", &enderecoDoCiclistaParaAtualizar->nome);
                    fflush(stdin);
                    printf("\nNome atualizado com sucesso!\n");
                    break;
                case 2:
                    // Atualizar quantidades das categorias
                    atualizarInscricaoDepoisDaAtualizacao(enderecoDoCiclistaParaAtualizar->numeroIncricao, enderecoDoCiclistaParaAtualizar->categoria, raiz);

                    //Escolher a nova categoria
                    printf("\n1 - Categoria Elite\n2 - Categoria ate os 18 anos\n3 - Categoria de 19 a 29 anos\n4 - Categoria de 30 a 39 anos;\n5 - Categoria acima de 40 anos");
                    printf("\nDigite a nova categoria: ");
                    scanf("%d", &enderecoDoCiclistaParaAtualizar->categoria);

                    //Não permitir digitar uma categoria errada
                    while(enderecoDoCiclistaParaAtualizar->categoria < 1 || enderecoDoCiclistaParaAtualizar->categoria > 5){
                        printf("\nOpcao Invalida. Digite uma valida: ");
                        scanf("%d", &enderecoDoCiclistaParaAtualizar->categoria);
                    }

                    //Adicionar novo numero de inscrição depois da atualização
                    enderecoDoCiclistaParaAtualizar->numeroIncricao = gerarNumeroDeInscricaoConformeCategoria(enderecoDoCiclistaParaAtualizar->categoria);

                    printf("\nCategoria atualizada com sucesso!\n");

                    break;
                default:
                    printf("Informacao nao cadastrada\n");
            }
        } else {
            printf("\nNunhum ciclista encontrado com o numero de inscricao '%d'!\n", numeroInscricaoCiclista);
        }
    }

    printf("\nPressione qualquer tecla para continuar...");
    getch();
    fflush(stdin);
    system("cls");
    return;
}
