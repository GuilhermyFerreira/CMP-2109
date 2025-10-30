#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>

/* Cada NO da arvore binaria */
typedef struct NO {
    int info;
    struct NO *esq;
    struct NO *dir;
} NO;

/* A "árvore" em si é um ponteiro para o ponteiro da raiz */
typedef NO* ArvBin;

/* Cria uma árvore vazia (raiz = NULL) */
ArvBin *criarArvore() {
    ArvBin *raiz = (ArvBin *) malloc(sizeof(ArvBin));
    if (raiz != NULL) {
        *raiz = NULL; // árvore começa vazia
    }
    return raiz;
}

/* Insere um novo valor na árvore binária de busca */
int inserir(ArvBin *raiz, int valor) {
    if (raiz == NULL) return 0;

    NO *novo = (NO *) malloc(sizeof(NO));
    if (novo == NULL) return 0;

    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if (*raiz == NULL) {
        // árvore estava vazia, esse nó vira a raiz
        *raiz = novo;
        return 1;
    }

    // senão, vamos descer na árvore até achar lugar
    NO *atual = *raiz;
    NO *pai = NULL;

    while (atual != NULL) {
        pai = atual;

        if (valor == atual->info) {
            // não vamos permitir valores duplicados
            free(novo);
            return 0;
        } else if (valor < atual->info) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }

    // liga o novo nó no pai
    if (valor < pai->info)
        pai->esq = novo;
    else
        pai->dir = novo;

    return 1;
}

/* Busca um valor na árvore: retorna 1 se achou, 0 se não achou */
int buscar(ArvBin *raiz, int valor) {
    if (raiz == NULL) return 0;
    NO *atual = *raiz;

    while (atual != NULL) {
        if (valor == atual->info)
            return 1;
        else if (valor < atual->info)
            atual = atual->esq;
        else
            atual = atual->dir;
    }

    return 0;
}

/* Percurso em pré-ordem: raiz -> esquerda -> direita */
void preOrdem_NO(NO *no) {
    if (no == NULL) return;
    printf("%d ", no->info);
    preOrdem_NO(no->esq);
    preOrdem_NO(no->dir);
}

/* Percurso em ordem (infixa): esquerda -> raiz -> direita */
void emOrdem_NO(NO *no) {
    if (no == NULL) return;
    emOrdem_NO(no->esq);
    printf("%d ", no->info);
    emOrdem_NO(no->dir);
}

/* Percurso em pós-ordem: esquerda -> direita -> raiz */
void posOrdem_NO(NO *no) {
    if (no == NULL) return;
    posOrdem_NO(no->esq);
    posOrdem_NO(no->dir);
    printf("%d ", no->info);
}

//* libera_NO:
void libera_NO(NO *no) {
    if (no == NULL) return;

    libera_NO(no->esq); // libera subárvore esquerda
    libera_NO(no->dir); // libera subárvore direita
    free(no);           // libera o nó atual
}

//* libera_ArvBin:
void libera_ArvBin(ArvBin *raiz) {
    if (raiz == NULL) return;
    libera_NO(*raiz);  // libera todos os nós da árvore
    free(raiz);        // libera a "cabeça" da árvore
}

/* Funções "interface" pro main imprimir */
void imprimirPreOrdem(ArvBin *raiz) {
    if (raiz == NULL) { printf("(arvore nao existe)\n"); return; }
    preOrdem_NO(*raiz);
    printf("\n");
}

void imprimirEmOrdem(ArvBin *raiz) {
    if (raiz == NULL) { printf("(arvore nao existe)\n"); return; }
    emOrdem_NO(*raiz);
    printf("\n");
}

void imprimirPosOrdem(ArvBin *raiz) {
    if (raiz == NULL) { printf("(arvore nao existe)\n"); return; }
    posOrdem_NO(*raiz);
    printf("\n");
}

#endif