#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h" // Inclui a biblioteca da Árvore Binária (ArvBin*)

int main() {
    int opcao;
    // O ponteiro que aponta para a raiz da Árvore Binária
    ArvBin *raiz = NULL; 

    do {
        printf("\n=== MENU ARVORE BINARIA DE BUSCA ===\n");
        printf("0 - Para criar ARVORE\n");
        printf("1 - Inserir VALOR\n");
        printf("2 - Buscar VALOR\n");
        printf("3 - Imprimir a ARVORE (Em Ordem)\n");
        printf("4 - Imprimir (Pre-Ordem)\n");
        printf("5 - Imprimir (Pos-Ordem)\n");
        printf("6 - Sair\n");
        printf("7 liberar a arvore\n");
        printf("Escolha: ");
        
        // CORREÇÃO: Usar scanf com precaução (melhor usar fgets e sscanf em código de produção)
        if (scanf("%d", &opcao) != 1) {
            // Limpa o buffer de entrada em caso de falha
            while (getchar() != '\n'); 
            opcao = -1; // Opção inválida
        }

        switch (opcao) {
            case 0: {
                if (raiz != NULL) {
                    printf("Arvore ja foi criada. Libere antes de criar uma nova.\n");
                    break;
                }
                // int N;
                // printf("Informe o tamanho da arvore: ");
                // scanf ("%d", &N);
                // Cria a referencia da raiz
                raiz = cria_ArvBin(); 
                if (raiz == NULL) {
                    printf("Erro ao criar a referencia da raiz!\n");
                    return 1;
                } else
                    printf("Arvore binaria criada (raiz inicializada para NULL)\n");
                break;
            }
            case 1: {
                if (raiz == NULL) {
                    printf("Erro, arvore nao criada. Use a opcao 0 primeiro.\n");
                    break;
                }
                int valor;
                printf("Digite o valor (inteiro) a ser inserido: ");
                scanf("%d", &valor);

                // insere(ArvBin *raiz, int valor)
                if (inserir(raiz, valor)) 
                    printf("Valor %d inserido com sucesso!\n", valor);
                else
                    printf("Erro: Valor %d ja existe ou falha na alocacao.\n", valor);
                break;
            }
            case 2: {
                if (raiz == NULL) {
                    printf("Erro, arvore nao criada.\n");
                    break;
                }
                int valorBusca;
                printf("Digite o valor para busca: ");
                scanf("%d", &valorBusca);

                // buscar(ArvBin *raiz, int valor)
                if (buscar(raiz, valorBusca)) {
                    printf("Valor %d encontrado na arvore.\n", valorBusca);
                } else {
                    printf("Valor %d nao encontrado!\n", valorBusca);
                }
                break;
            }
            case 3:
                if (raiz == NULL || *raiz == NULL) {
                    printf("Arvore vazia.\n");
                    break;
                }
                printf("\n--- Percurso EM ORDEM (Ordenado) ---\n");
                // emOrdem(ArvBin no)
                emOrdem(*raiz); 
                printf("\n");
                break;
            
            case 4:
                if (raiz == NULL || *raiz == NULL) {
                    printf("Arvore vazia.\n");
                    break;
                }
                printf("\n--- Percurso PRE-ORDEM ---\n");
                // preOrdem(ArvBin no)
                preOrdem(*raiz); 
                printf("\n");
                break;
            
            case 5:
                if (raiz == NULL || *raiz == NULL) {
                    printf("Arvore vazia.\n");
                    break;
                }
                printf("\n--- Percurso POS-ORDEM ---\n");
                // posOrdem(ArvBin no)
                posOrdem(*raiz); 
                printf("\n");
                break;


            case 6:
                printf("Saindo...\n");
                break;

            case 7:
                if (raiz == NULL) {
                    printf("Arvore liberada.\n");
                    break;
                }
                libera_NO(*no);
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    // liberaHash(tabela) -> substituída por libera_ArvBin(raiz)
    if (raiz != NULL) {
        libera_ArvBin(raiz);
        printf("Memoria da arvore liberada.\n");
    }
    
    return 0;
}