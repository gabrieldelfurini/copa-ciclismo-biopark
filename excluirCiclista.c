#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

ArvBin excluirCiclista(ArvBin* raiz){
    system("cls");
    printf("==================================== EXCLUIR CICLISTA ===================================\n");


    if((*raiz) == NULL){
        printf("\nNunhum ciclista cadastrado!\n\n");
        return;
    }

    printf("\nLista de ciclistas cadastrados:\n");
    //Printar os elementos de cada categoria
    for(int index = 1; index < 6; index++){
        percorreInOrdem(*raiz, index,0);
    }

    int numeroInscricao;
    printf("\nDigite o Numero de Inscricao do ciclista a ser excluido: ");
    scanf("%d", &numeroInscricao);

    ArvBin atual = *raiz;
    ArvBin ant = NULL;

    while(atual != NULL){
        if(atual->numeroIncricao == numeroInscricao){

            printf("\nCiclista '%d' exlcuido com sucesso!\n", atual->numeroIncricao);

            // Atualizar quantidades das categorias
            atualizarInscricaoDepoisDaAtualizacao(atual->numeroIncricao, atual->categoria, *raiz);

            //Verificar em qual caso de exclusão o nó se encaixa
            if(atual->dir == NULL && atual->esq == NULL){
                //NÓ FOLHA

                //Verificar se é a raiz
                if(ant == NULL){
                    free(atual);
                    //Atualizar o valor do ponteiro que esta dentro da minhaAvrBin na main
                    *raiz = NULL;
                    return;
                }

                if(ant->numeroIncricao < atual->numeroIncricao){
                   ant->dir = NULL;
                   free(atual);
                   return;
                }else{
                   ant->esq = NULL;
                   free(atual);
                   return;
                }
            }else if((atual->dir == NULL && atual->esq != NULL) || (atual->esq == NULL && atual->dir != NULL)){
                //NÓ COM 1 FLILHO

                //Verificar se é a RAIZ
                if(ant == NULL){
                    //Verficar pra qual lado o atual(raiz) tem o filho
                    if(atual->dir == NULL){
                        *raiz = atual->esq;
                    }else{
                        *raiz = atual->dir;
                    }

                    free(atual);
                    return;
                }


                //Verfificar de qual lado o atual tem o filho
                if(atual->dir == NULL){
                    //O filho esta na esquerda do atual

                    //Verificar pra qual lado o anterior vai apontar
                    if(ant->numeroIncricao < atual->numeroIncricao){
                        //Anterior vai apontar para a direita
                        ant->dir = atual->esq;
                        free(atual);
                        return;
                    }else{
                        //Anterior vai apontar para a esquerda
                        ant->esq = atual->esq;
                        free(atual);
                        return;
                    }
                }else{
                    //O filho esta na direita do atual

                    //Verificar pra qual lado o anterior vai apontar
                    if(ant->numeroIncricao < atual->numeroIncricao){
                        ant->dir = atual->dir;
                        free(atual);
                        return;
                    }else{
                        ant->esq = atual->dir;
                        free(atual);
                        return;
                    }
                }
            }else{
                //QUANDO TEM 2 FILHOS

                ArvBin ant2 = NULL;
                ArvBin temp = antecessor(atual->esq, &ant2);

                if(temp->esq != NULL){
                    ant2->dir = temp->esq;
                }else{
                    if(ant2 != NULL){
                        //Verificar se o anterior do numero que vai substituir tem algum valor, para poder setar para null
                        ant2->dir = NULL;
                    }
                }

                //Fazer as ligações necessárias
                temp->dir = atual->dir;
                //Verificar se caso o número para substituir for logo a árvore esquerda
                if(temp == atual->esq){
                    temp->esq = NULL;
                }else{
                    temp->esq = atual->esq;
                }

                //Verificar se é a RAIZ - Se SIM, vai apontar o conteudo de raiz para o filho que vai substituir o atual
                if(ant == NULL){
                    *raiz = temp;
                }

                free(atual);
                return;
            }

            return;
        }else{
            //Percorrer a Arvore ate achar o nó com o número escolhido
            ant = atual;
            if(numeroInscricao > atual->numeroIncricao){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
    }
    printf("\nNunhum ciclista encontrado com o numero de inscricao '%d'!\n", numeroInscricao);
    return NULL;
}
