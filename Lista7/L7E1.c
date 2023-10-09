#include<stdio.h>

typedef struct dadosProduto{
    int codigo;
    float preco;
    int quantidade;
}dados;

typedef struct no{
    dados dados;
    struct no *prox;
}noptr; 

noptr *inicio;

void insereProduto(noptr *novo, int codigo, float preco, int quantidade){
    novo->dados.codigo = codigo;
    novo->dados.preco = preco;
    novo->dados.quantidade = quantidade;
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        novo->prox = inicio;
        inicio = novo;
    }
}

void listarProdutos(){
    noptr *p;
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        p = inicio;
        while(p != NULL){
            printf("\nCodigo: %d", p->dados.codigo);
            printf("\nPreco: %.2f", p->dados.preco);
            printf("\nQuantidade: %d", p->dados.quantidade);
            p = p->prox;
        }
    }
}   

int main(){
    int codigo;
    int quantidade;
    float preco;
    noptr *dados = NULL;

    while(codigo != 0){
        printf("\nDigite o codigo (ou 0 para sair): ");
        scanf("%d", &codigo);
        if(codigo != 0){
            printf("\nDigite o preco: ");
            scanf("%f", &preco);
            printf("\nDigite a quantidade: ");
            scanf("%d", &quantidade);
            insereProduto(dados, codigo, preco, quantidade);
        }
    }
    listarProdutos();
    return 0;
}
