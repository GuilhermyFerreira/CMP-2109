#include "TabelaHash.h"

int main() {
    int opcao;
    Hash* tabela = criaHash(6);

    if (tabela == NULL) {
        printf("Erro ao criar a tabela hash!\n");
        return 1;
    }

    do {
        printf("\n=== MENU ===\n");
        printf("1 - Inserir produto\n");
        printf("2 - Buscar produto\n");
        printf("3 - Sair\n");
        printf("4 - Imprimir a tabela\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                struct produto p;
                printf("Codigo: ");
                scanf("%d", &p.codigo);
                // struct produto* encontrado = buscaHash(tabela, p.codigo);
                // while(encontrado!=NULL){
                //     system("cls");//Se for para windows
                //     //system("clear");//Se for para Linux
                //     printf("Código já inserido\n");
                //     printf("digite novamente:");
                //     scanf("%d",&p.codigo);
                //     encontrado = buscaHash(tabela, p.codigo);
                // }
                printf("Nome: ");
                scanf(" %[^\n]", p.nome);
                printf("Preco: ");
                scanf("%f", &p.preco);
                printf("Quantidade: ");
                scanf("%d", &p.quantidade);

                if (insereHash(tabela, p))
                    printf("Produto inserido com sucesso!\n");
                else
                    printf("Erro: tabela cheia ou falha na alocacao.\n");
                break;
            }
            case 2: {
                int codigo;
                printf("Codigo para busca: ");
                scanf("%d", &codigo);

                struct produto* encontrado = buscaHash(tabela, codigo);
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
            case 4:
                if(tabela==NULL){
                    printf("Tabela vazia");
                    break;
                }
                 imprimir(tabela);
                 break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    liberaHash(tabela);
    return 0;
}
