#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// 1. Definição da Estrutura do Nó (NO)
typedef struct NO
{
  int valor;
  struct NO *esq;
  struct NO *dir;
} NO;

// 2. Definição do Tipo ArvBin (Ponteiro para o Nó)
typedef NO *ArvBin;

/* FUNÇÕES DE GESTÃO DA ÁRVORE (PONTEIRO PARA PONTEIRO) */

// Cria e inicializa a referência da raiz para NULL
ArvBin *cria_ArvBin()
{
  ArvBin *raiz = (ArvBin *)malloc(sizeof(ArvBin));
  if (raiz != NULL)
  {
    *raiz = NULL; // Inicializa a árvore como vazia
  }
  return raiz;
}

// Verifica se a árvore está vazia
int estaVazia_ArvBin(ArvBin *raiz)
{
  if (raiz == NULL)
    return 1; // A referência da raiz não existe
  if (*raiz == NULL)
    return 1; // A árvore não tem nós
  return 0;
}

// Função auxiliar para liberar recursivamente cada nó
void libera_NO(struct NO *no)
{
  if (no == NULL) // CORREÇÃO: Comparação '=='
    return;
  libera_NO(no->esq);
  libera_NO(no->dir);
  free(no);
}

// Libera toda a árvore e a referência da raiz
void libera_ArvBin(ArvBin* raiz)
{
  if (raiz == NULL)
    return;
  libera_NO(*raiz); // Libera cada nó da árvore
  free(raiz);       // Libera o ponteiro que guarda a referência da raiz
}

// Conta o total de nós na árvore (Função puramente recursiva)
int totalNo_ArvBin_Aux(ArvBin no)
{
  if (no == NULL)
    return 0;
  // Conta o nó atual (1) + nós da esquerda + nós da direita
  return 1 + totalNo_ArvBin_Aux(no->esq) + totalNo_ArvBin_Aux(no->dir);
}

// Funções de API que chamam as auxiliares ou iniciam a recursão
int totalNo_ArvBin(ArvBin *raiz)
{
  if (raiz == NULL || *raiz == NULL)
    return 0;
  return totalNo_ArvBin_Aux(*raiz);
}


/* FUNÇÕES DE ÁRVORE BINÁRIA DE BUSCA (ABB) */

// Insere um valor na ABB (necessita de ArvBin* para modificar a árvore)
int inserir(ArvBin *raiz, int valor)
{
  if (raiz == NULL)
    return 0;

  if (*raiz == NULL)
  { // Caso base: Encontrou local para inserção
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
      return 0; // Erro de alocação
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    *raiz = novo;
    return 1;
  }

  // Se o valor já existe, não insere
  if (valor == (*raiz)->valor)
  {
    return 0;
  }
  // Recurso à esquerda ou à direita
  else if (valor < (*raiz)->valor)
  {
    return inserir(&((*raiz)->esq), valor);
  }
  else
  { // valor > (*raiz)->valor
    return inserir(&((*raiz)->dir), valor);
  }
}

// Busca um valor na ABB (necessita de ArvBin* para consistência com as demais)
int buscar(ArvBin *raiz, int valor)
{
  if (raiz == NULL || *raiz == NULL)
    return 0; // Árvore vazia ou fim do ramo

  if (valor == (*raiz)->valor)
    return 1; // Encontrou

  if (valor < (*raiz)->valor)
    return buscar(&((*raiz)->esq), valor);
  else
    return buscar(&((*raiz)->dir), valor);
}


/* FUNÇÕES DE PERCURSO */

// Percurso Pré-Ordem (Raiz -> Esquerda -> Direita)
void preOrdem(ArvBin no)
{
  if (no == NULL)
    return;
  printf("%d ", no->valor);
  preOrdem(no->esq);
  preOrdem(no->dir);
}

// Percurso Em-Ordem (Esquerda -> Raiz -> Direita)
void emOrdem(ArvBin no)
{
  if (no == NULL)
    return;
  emOrdem(no->esq);
  printf("%d ", no->valor);
  emOrdem(no->dir);
}

// Percurso Pós-Ordem (Esquerda -> Direita -> Raiz)
void posOrdem(ArvBin no)
{
  if (no == NULL)
    return;
  posOrdem(no->esq);
  posOrdem(no->dir);
  printf("%d ", no->valor);
}

#endif