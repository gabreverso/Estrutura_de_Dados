#include <stdio.h>
#include <stdlib.h> // Adicione esta inclusão para usar malloc.

typedef struct dadosProduto {
    int codigo;
    float preco;
    int quantidade;
} dados;

typedef struct no {
    dados dados;
    struct no *prox;
} noptr;

noptr *inicio = NULL; // Inicialize inicio como NULL.

void insereProduto(noptr **novo, int codigo, float preco, int quantidade) {
    noptr *novoProduto = (noptr *)malloc(sizeof(noptr)); // Aloque memória para o novo nó.
    novoProduto->dados.codigo = codigo;
    novoProduto->dados.preco = preco;
    novoProduto->dados.quantidade = quantidade;
    novoProduto->prox = NULL;
    if (*novo == NULL) {
        *novo = novoProduto;
    } else {
        novoProduto->prox = *novo;
        *novo = novoProduto;
    }
}

void listarProdutos() {
    noptr *p = inicio;
    if (p == NULL) {
        printf("\nLista vazia\n");
    } 
    else {
        while (p != NULL) {
            printf("\nCodigo: %d", p->dados.codigo);
            printf("\nPreco: %.2f", p->dados.preco);
            printf("\nQuantidade: %d\n");
            p = p->prox;
        }
    }
}

int main() {
    int codigo = 1; // Inicialize código com um valor diferente de zero.
    int quantidade;
    float preco;
    noptr *dados = NULL;

    while (codigo != 0) {
        printf("\nDigite o codigo (ou 0 para sair): ");
        scanf("%d", &codigo);
        if (codigo != 0) {
            printf("\nDigite o preco: ");
            scanf("%f", &preco);
            printf("\nDigite a quantidade: ");
            scanf("%d", &quantidade);
            insereProduto(&dados, codigo, preco, quantidade);
        }
    }
    listarProdutos();

    // Libere a memória alocada.
    while (dados != NULL) {
        noptr *temp = dados;
        dados = dados->prox;
        free(temp);
    }

    return 0;
}
