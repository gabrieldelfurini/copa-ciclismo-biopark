#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int main(void){
    ArvBin* minhaArvore = criarArvBin(); //criando ponteiro que aponta para a raiz
    ArvBin enderecoDoCiclistaParaAtualizar = NULL, atualizaValorDaRaiz;
    int escolha, numeroInscricaoCiclista, escolhaInformacaoParaAtualizar, fatorDeBalanceamento, categoriasComCiclistas = 0, atualizouCategoria;


    do {
         printf("==================================== MENU PRINCIPAL ===================================\n");
        printf("0 - Sair\n");
        printf("1 - Adicionar novo ciclista\n");
        printf("2 - Mostrar Inscricoes\n");
        printf("3 - Atualizar dados do ciclista\n");
        printf("4 - Remover Ciclista\n");
        printf("5 - Mostrar elementos pre order\n");
        printf("6 - Mostrar categorias\n");
        printf("7 - Trasnformar arvore depois da atualizacao em vetor\n");
        printf("Digite sua escolha: ");
        scanf("%d", &escolha);
        printf("");


        switch(escolha){
            case 0:
                libera_ArvBin(minhaArvore);
                printf("\nSaindo...\n");
                break;
            case 1:

                insere_ArvBin(minhaArvore);

                //Calcular o fator de balanceamento
                fatorDeBalanceamento = (alturaArvBin(&(*minhaArvore)->esq) - alturaArvBin(&(*minhaArvore)->dir)) >= 0 ? alturaArvBin(&(*minhaArvore)->esq) - alturaArvBin(&(*minhaArvore)->dir) :  (alturaArvBin(&(*minhaArvore)->esq) - alturaArvBin(&(*minhaArvore)->dir)) * (-1);

                // Balancear automaticamente a árvore
                if(fatorDeBalanceamento >= 2){
                    balancearArvore(minhaArvore, 0);
                }
                break;

            case 2:

                system("cls");
                printf("==================================== CICLISTAS CADASTRADOS ===================================\n");

                if(*minhaArvore == NULL){ //Conferir se existe ciclistas cadastrados
                    printf("\nNunhum ciclista cadastrado!\n");
                }else{
                    printf("\nLista de ciclistas por categoria:\n");
                    for(int index = 1; index < 6; index++){
                        percorreInOrdem(*minhaArvore, index,0);
                    }
                }

                printf("\n\nPressione qualquer tecla para continuar...");
                getch();
                fflush(stdin);
                system("cls");
                break;

            case 3:

                atualizarCiclista(*minhaArvore);

                //Atualizando a arvore para ficar com os valores certos
                if(*minhaArvore != NULL && qtdDeIncricoes > 2){
                    (*minhaArvore) = balancearArvore(*minhaArvore, 1);
                    printf("\nBalanceou a arvore\n");
                }
                break;

            case 4:

                excluirCiclista(minhaArvore);

                printf("\nPressione qualquer tecla para continuar...");
                getch();
                fflush(stdin);
                system("cls");

                break;

            case 5:

                percorrePreOrdem(*minhaArvore);
                printf("\n");
                break;

            case 6:

                printf("\nElite: %d\n", ctgElite);
                printf("Ate 18 anos: %d\n", ctgAte18);
                printf("De 19 a 29 anos: %d\n", ctg19_29);
                printf("De 30 a 39 anos: %d\n", ctg30_39);
                printf("Acima de 40 anos: %d\n\n", ctgAcima40);
                break;

            case 7:

                (*minhaArvore) = balancearArvore(*minhaArvore, 1);
                printf("\nBalanceou a arvore\n");
                break;

            default:

                printf("\nCaso ainda nao cadastrado.\n\n");
        }
    }while(escolha != 0);

    return 0;
}
