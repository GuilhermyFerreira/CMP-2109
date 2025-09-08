#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Hash* criaHash(int TABLE_SIZE){
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if(ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(
            TABLE_SIZE * sizeof(struct produto*));
        if (ha->itens == NULL){
            free(ha)
            return NULL;
        }
        ha->qtd = 0;
        for(i=0; i < ha -> TABBLE_SIZE, i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Hash* liberaHash(Hash* ha){
    if(ha != NULL){
        int i;
        for(i=0; i < ha->MAX; i++){
            if(ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
    return NULL;
}

Hash* insereHash(Hash* ha, struct produto prod){
    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;
    int chave = prod.codigo % ha->TABLE_SIZE;
    struct produto* novo;
    novo = (struct produto*) malloc(sizeof(struct produto));
    if(novo == NULL)
        return 0;
    *novo = prod;
    int i;
    for(i=0; i < ha->TABLE_SIZE; i++){
        int index = (chave + i) % ha->TABLE_SIZE;
        if(ha->itens[index] == NULL){
            ha->itens[index] = novo;
            ha->qtd++;
            return 1;
        }
    }
    free(novo);
    return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

Hash* buscaHash(Hash* ha, int codigo){
    if(ha == NULL)
        return NULL;
    int chave = codigo % ha->TABLE_SIZE;
    int i;
    for(i=0; i < ha->TABLE_SIZE; i++){
        int index = (chave + i) % ha->TABLE_SIZE;
        if(ha->itens[index] == NULL)
            return NULL;
        if(ha->itens[index]->codigo == codigo)
            return ha->itens[index];
    }
    return NULL;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

