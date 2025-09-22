#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto {
    int codigo;
    char nome[30];
    float preco;
    int quantidade;
};

struct hash {
    int qtd, TABLE_SIZE;
    struct produto **itens;
};

typedef struct hash Hash;

static Hash* criaHash(int TABLE_SIZE) {
    Hash* ha = (Hash*) malloc(sizeof(Hash));
    if (ha != NULL) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->qtd = 0;
        ha->itens = (struct produto**) malloc(TABLE_SIZE * sizeof(struct produto*));
        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        for (int i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

static void liberaHash(Hash* ha) {
    if (ha != NULL) {
        for (int i = 0; i < ha->TABLE_SIZE; i++) {
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
}

static int insereHash(Hash* ha, struct produto prod) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = prod.codigo % ha->TABLE_SIZE;
    struct produto* novo = (struct produto*) malloc(sizeof(struct produto));
    if (novo == NULL)
        return 0;
    *novo = prod;

    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        int index = (chave + i) % ha->TABLE_SIZE;
        if (ha->itens[index] == NULL) {
            ha->itens[index] = novo;
            ha->qtd++;
            return 1;
        }
    }
    free(novo);
    return 0;
}

static struct produto* buscaHash(Hash* ha, int codigo) {
    if (ha == NULL) return NULL;
    int chave = codigo % ha->TABLE_SIZE;
    for (int i = 0; i < ha->TABLE_SIZE; i++) {
        int index = (chave + i) % ha->TABLE_SIZE;
        if (ha->itens[index] == NULL)
            return NULL;
        if (ha->itens[index]->codigo == codigo)
            return ha->itens[index];
    }
    return NULL;
}

static void imprimir(Hash* ha){
    int i;
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        printf("[%d] ", i);
        if (ha->itens[i] != NULL) {
            struct produto* p = ha->itens[i];
            printf("Codigo: %d | Nome: %s | Preco: %.2f | Quantidade: %d\n",
                   p->codigo, p->nome, p->preco, p->quantidade);
        }
    }
}

#endif
