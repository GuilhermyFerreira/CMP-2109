#include "TabelaHash.h"


int main() {
    int opcao;
    Hash *tabela = NULL;
    do {
        printf("\n=== MENU ===\n");
        printf("0 - Para criar tabela\n");
        printf("1 - Inserir produto\n");
        printf("2 - Buscar produto\n");
        printf("3 - Imprimir a tabela\n");
        printf("4 - Inserir produto com colisao\n");
        printf("5 - Buscar produto com colisao\n");
        printf("6 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 0: {
            if (tabela != NULL) {
                printf("Tabela ja foi criada\n");
                break;
            }
            tabela = criaHash(5);
            if (tabela == NULL) {
                printf("Erro ao criar a tabela hash!\n");
                return 1;
            } else
                printf("Tabela criada\n");
            break;
        }
        case 1: {
            if (tabela == NULL) {
                printf("Erro, tabela nao criada\n");
                break;
            }
            struct produto p;
            printf("Codigo: ");
            scanf("%d", &p.codigo);
            printf("Nome: ");
            scanf(" %29[^\n]", p.nome);
            printf("Preco: ");
            scanf("%f", &p.preco);
            printf("Quantidade: ");
            scanf("%d", &p.quantidade);

            if (insereHash(tabela, p))
                printf("Produto inserido com sucesso!\n");
            else
                printf("Erro: Posicao ocupada ou falha na alocacao.\n");
            break;
        }
        case 2: {
            if (tabela == NULL) {
                printf("Erro, tabela nao criada\n");
                break;
            }
            int codigoBusca;
            printf("Codigo para busca: ");
            scanf("%d", &codigoBusca);

            struct produto *encontrado = buscaHash(tabela, codigoBusca);
            if (encontrado != NULL) {
                printf("\nProduto encontrado:\n");
                printf("Codigo: %d\nNome: %s\nPreco: %.2f\nQuantidade: %d\n",
                       encontrado->codigo,
                       encontrado->nome,
                       encontrado->preco,
                       encontrado->quantidade);
            } else {
                printf("Produto nao encontrado!\n");
            }
            break;
        }
        case 3:
            if (tabela == NULL) {
                printf("Tabela vazia\n");
                break;
            }
            imprimir(tabela);
            break;

        case 4: {
            if (tabela == NULL) {
                printf("Erro: tabela NAO CRIADA\n");
                break;
            }
            struct produto p;
            printf("Codigo: ");
            scanf("%d", &p.codigo);
            printf("Nome: ");
            scanf(" %29[^\n]", p.nome);
            printf("Preco: ");
            scanf("%f", &p.preco);
            printf("Quantidade: ");
            scanf("%d", &p.quantidade);
            insereHash_SemColisao(tabela, p);
            break;
        }

        case 5: {
            if (tabela == NULL) {
                printf("Erro: tabela NAO CRIADA\n");
                break;
            }
            int codigo;
            struct produto encontrado;
            printf("Codigo para busca: ");
            scanf("%d", &codigo);

            if (buscaHash_SemColisao(tabela, codigo, &encontrado)) {
                printf("Produto encontrado:\n");
                imprimeProduto(encontrado);
            } else {
                printf("Produto nao encontrado.\n");
            }
            break;
        }

        case 6:
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 6);

    liberaHash(tabela);
    return 0;
}
