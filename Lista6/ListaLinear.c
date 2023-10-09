//lista encadeada
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

noptr *inicio;

void menu(){
    printf("\n1 - Inserir no inicio");
    printf("\n2 - Mostrar todos");
    printf("\n3 - Apagar primeiro elemento da Lista");
    printf("\n4 - Apagar todos os elementos da Lista");
    printf("\n5 - Sair");
    printf("\nDigite uma opcao: ");
}

void insereLista(noptr *novo, int valor){
    novo->dados = valor;
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        novo->prox = inicio;
        inicio = novo;
    }
}

void removeLista(){
    noptr *p;
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        p = inicio;
        printf("\nRemovendo %d", p->dados);
        inicio = inicio->prox;
        free(p);
    }
}

void removeTodos(){
    noptr *p;
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        while(inicio != NULL){
            p = inicio;
            printf("\nRemovendo %d", p->dados);
            inicio = inicio->prox;
            free(p);
        }
    }
}

void listaTodos(){
    noptr *aux;
    aux = inicio;
    while(aux != NULL){
        printf("%d ", aux->dados);
        aux = aux->prox;
    }
} 

int main(){
    int recebe = -1;
    inicio = NULL;
    noptr *dados;
    int op;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:{
                printf("\nDigite um valor: ");
                scanf("%d", &recebe);
                dados = (struct no *) malloc(sizeof(noptr));
                if(!dados){
                    printf("\nSem memoria");
                    exit(1);
                }
                insereLista(dados, recebe);
                break;
            }
            
            case 2:{
                printf("\nElementos na lista: ");
                listaTodos();
                break;
            }

            case 3:{
                removeLista();
                break;
            }

            case 4:{
                removeTodos();
                break;
            }

            case 5:{
                printf("\nSaindo...");
                break;
            }  

            default:{
                printf("\nOpcao invalida");
                break;
            }
        }

    }
    while(op != 4);
    
}


