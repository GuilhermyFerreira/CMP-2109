#include <stdlib.h>
#include <string.h>
#include "tabelaHash.h"

struct produto{
    int codigo;
    char nome[30];
    float preco;
    int quantidade; 
}

//Definição do tipo Hash

struct hash{
    int qtd, TABBLE_SIZE;
    struct aluno **intens;
};
typedef struct hash Hash;

