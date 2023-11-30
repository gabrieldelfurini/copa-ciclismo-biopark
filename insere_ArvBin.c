#include "funcoes.h"
#include <stdio.h>

no* insere_ArvBin(ArvBin* raiz) {
    system("cls");
    // Aloca espa�o na mem�ria para novo elemento
    no *novo = malloc(sizeof(no));
    int numeroCategoria;

    // Testa se houve aloca��o
    if (novo == NULL) {
        printf("Sem mem�ria dispon�vel!\n");
        exit(0);
    }

     printf("==================================== ADICIONAR UM CICLISTA ===================================\n");
    //Preencher os dados do ciclista
    printf("\nDigite o nome do ciclista: ");
    scanf(" %[^\n]", &novo->nome);

    printf("\n1 - Categoria Elite\n2 - Categoria ate os 18 anos\n3 - Categoria de 19 a 29 anos\n4 - Categoria de 30 a 39 anos;\n5 - Categoria acima de 40 anos");
    printf("\n\nDigite a categoria do ciclista: ");
    scanf("%d", &numeroCategoria);
    //Verifica se o n�mero da categoria est� entre o intervalo correto
    while(!(numeroCategoria >= 1 && numeroCategoria <= 5)){
        printf("\nCategoria invalida. Digite uma valida: ");
        scanf("%d", &numeroCategoria);
    }

    if(numeroCategoria >= 1 && numeroCategoria <= 5){
        novo->categoria = numeroCategoria;
    };

    novo->numeroIncricao = gerarNumeroDeInscricaoConformeCategoria(novo->categoria);
    novo->dir = NULL;
    novo->esq = NULL;

    //Fazer liga��es necess�rias
    if (*raiz == NULL) { // se �rvore vazia insere primeiro n�
        *raiz = novo;
    } else {
        no *atual = *raiz;
        no *ant = NULL;

        while (atual != NULL) {
            ant = atual;

            if (novo->numeroIncricao == atual->numeroIncricao) {
                printf("Elemento ja existe...");
                free(novo);
                return 0; // elemento j� existe
            }

            if (novo->numeroIncricao > atual->numeroIncricao) {
                atual = atual->dir;
            } else {
                atual = atual->esq;
            }
        }

        if (novo->numeroIncricao > ant->numeroIncricao) {
            ant->dir = novo;
        } else {
            ant->esq = novo;
        }
    }

    printf("\n\nNovo ciclista cadastrado com sucesso!\nNumero de Inscricao: %d | Nome: %s | Categoria: %d\n\n", novo->numeroIncricao, novo->nome, novo->categoria); //'(%d)' so pra usar nos testes, tirar depois
    qtdDeIncricoes++;

    printf("\nPressione qualquer tecla para continuar...");
    getch();
    fflush(stdin);
    system("cls");

    return novo;
}
