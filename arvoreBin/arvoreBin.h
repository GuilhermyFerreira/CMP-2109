#ifndef ARVORE_BIN_H
#define ARVORE_BIN_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvBin;

ArvBin* cria_ArvBin();
//Cria a arvore
ArvBin* cria_ArvBin(ArvBin *raiz){
    ArvBin* raiz = (ArvBin*) malloc (sizeof (ArvBin));
    if (raiz != NULL){
            *raiz=NULL;
    return raiz;
    }
};

//Destroi a arvore

void libera_NO(struct NO* no){
    if(no=NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
            return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera raiz
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz==NULL)
        return 1;
    if (*raiz == NULL)
        return 1;
    return 0;
}

int totalNo_ArvBin (ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int total_esq = totalNO_ArvBin(&((*raiz)->esq));
    int total_dir = totalNO_ArvBin(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}


#endif