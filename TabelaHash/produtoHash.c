#include "TabelaHash.h"

int main()
{
    int opcao;
    Hash *tabela;
    do
    {
        printf("\n=== MENU ===\n");
        printf("0 - Para criar tabela\n");
        printf("1 - Inserir produto\n");
        printf("2 - Buscar produto\n");
        printf("3 - Imprimir a tabela\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 0:
        {   
            if(tabela!=NULL){
                printf("Tabela ja foi criada");    
                break;
            }
            tabela = criaHash(10);
            if (tabela == NULL)
            {
                printf("Erro ao criar a tabela hash!\n");
                return 1;
            }
            else
                printf("Tabela criada");
            break;
        }
        case 1:
        {
            if (tabela == NULL){
                printf("Erro, tabela nao criada");
                break;
            }
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
        case 2:
        {
            if(tabela==NULL){
                printf("Erro, tabela nao criada");
                break;
            }
            int codigo;
            printf("Codigo para busca: ");
            scanf("%d", &codigo);

            struct produto *encontrado = buscaHash(tabela, codigo, encontrado);
            if (encontrado != NULL)
            {
                printf("\nProduto encontrado:\n");
                printf("Codigo: %d\nNome: %s\nPreco: %.2f\nQuantidade: %d\n",
                       encontrado->codigo,
                       encontrado->nome,
                       encontrado->preco,
                       encontrado->quantidade);
            }
            else
            {
                printf("Produto nao encontrado!\n");
            }
            break;
        }
        case 3:
            if (tabela == NULL)
            {
                printf("Tabela vazia");
                break;
            }
            imprimir(tabela);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    liberaHash(tabela);
    return 0;
}
