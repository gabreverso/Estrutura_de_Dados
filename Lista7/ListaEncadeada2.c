#include<stdio.h>

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

void insereLista(noptr **inicio, int valor){
    noptr *novo = (noptr*)malloc(sizeof(noptr));

    if(novo==NULL){
        printf("\nErro de alocacao");
        return;
    }
    novo->dados = valor;
    novo->prox = NULL;
    if(*inicio == NULL){
        *inicio = novo;
    }
    else{
        noptr *p = *inicio;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }
}

void removeLista(noptr **inicio){
    if(*inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    noptr *p = *inicio;
    noptr *ant = NULL;
    while(p->prox != NULL){
        ant = p;
        p = p->prox;
    }
    if(ant != NULL){
        ant->prox = NULL;
    }
    printf("\nRemovendo %d", p->dados);
}

int main(){
    noptr *inicio = NULL;

    int valor;

    while(valor != 0){
        printf("\nDigite um valor: ");
        scanf("%d", &valor);
        if(valor != 0){
            insereLista(&inicio, valor);
        }
    }

    removeLista(&inicio);

}