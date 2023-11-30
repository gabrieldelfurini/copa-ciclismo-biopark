#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

struct No {
    int numeroIncricao;
    char nome[100];
    int categoria;
    struct No *esq; // ponteiro que aponta para o filho esquerdo
    struct No *dir; // ponteiro que aponta para o filho direito
};
typedef struct No no;
typedef no *ArvBin;

// Varáveis Globais para as Categorias
extern int ctgElite, ctgAte18, ctg19_29, ctg30_39, ctgAcima40, qtdDeIncricoes; // ARRUMAR ISSO DEPOIS

//Protótipos das funções do projeto
ArvBin* criarArvBin();
int gerarNumeroDeInscricaoConformeCategoria(int categoriaDoCiclista);
ArvBin percorreInOrdem(ArvBin raiz, int index, int numeroInscricaoParaAtualizarCiclista);
void atualizarInscricaoDepoisDaAtualizacao(int numeroInscricao, int numeroCategoria, ArvBin raiz);
no* insere_ArvBin(ArvBin* raiz);
void libera_NO(no *no_liberar);
int libera_ArvBin(ArvBin* raiz);
int atualizarCiclista(ArvBin raiz);
ArvBin antecessor(ArvBin no, ArvBin *ant);
ArvBin excluirCiclista(ArvBin *raiz);
void percorrePreOrdem(ArvBin raiz);
int alturaArvBin(ArvBin* raiz);
void preencherLista(ArvBin raiz, no* lista, int* index);
ArvBin construirArvoreBalanceada(no* lista, int inicio, int fim);
ArvBin balancearArvore(ArvBin *raiz, int vaiOrdenarVetor);


#endif // FUNCOES_H_INCLUDED
