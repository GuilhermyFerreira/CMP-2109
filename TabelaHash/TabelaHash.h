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
    Hash* ha = (Hash *) malloc(sizeof(Hash));
    int i;
    if (ha != NULL) {
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct produto**) malloc(TABLE_SIZE * sizeof(struct produto*));
        if (ha->itens == NULL) {
            free(ha);
            return NULL;
        }
        ha->qtd = 0;
        for (i = 0; i < ha->TABLE_SIZE; i++)
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

int sondagemquadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*1*1;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}
int chavedivisao(int codigo, int TABLE_SIZE){
    return(codigo & 0x7777777) & TABLE_SIZE;
}

static int insereHash(Hash* ha, struct produto prod) {
    if (ha == NULL || ha->qtd == ha->TABLE_SIZE){
        return 0;
        printf("Erro");
    }

    int codigo=prod.codigo;

    int i, pos, newpos;
    pos=chavedivisao(codigo, ha->TABLE_SIZE);
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newpos = sondagemquadratica(pos, i, ha->TABLE_SIZE);
        
        if (ha->itens[newpos] == NULL) {
            struct produto* novo = (struct produto*) malloc(sizeof(struct produto));
            *novo = prod;
            ha->itens[newpos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

static struct produto* buscaHash(Hash* ha, int codigo, struct produto *p) {
    if (ha == NULL) return NULL;
    int newpos, i, pos;
    for (i = 0; i < ha->TABLE_SIZE; i++) {
        newpos= sondagemquadratica(pos,i,ha->TABLE_SIZE);
        if(ha->itens[newpos]==NULL){
            return 0;
        }
        if (ha->itens[newpos]->codigo==codigo){
            *p=*(ha->itens[newpos]);
        }
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
