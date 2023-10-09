//lista encadeada
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dados{
    char nome[30];
    int idade;
    struct dados *prox;
}noptr;

noptr *inicio;

void menu(){
    printf("\n1 - Inserir no inicio");
    printf("\n2 - Mostrar todos");
    printf("\n3 - Apagar primeiro elemento da Lista");
    printf("\n4 - Enviar um nome");
    printf("\n5 - Sair");
    printf("\nDigite uma opcao: ");
}

void insereLista(noptr *novo, char nome[], int idade){
    novo->idade = idade;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        novo->prox = inicio;
        inicio = novo;
    }
}

void mostrarTodos(){
    if(inicio == NULL){
        printf("\nLista vazia"); 
        return;
    }
    noptr *p;
    p = inicio; 
    while(p != NULL){
        printf("\n%s, %d anos", p->nome, p->idade);
        p = p->prox;
    }
    printf("\n");

}

void removeLista(){
    noptr *p;
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        p = inicio;
        printf("\nRemovendo %s", p->nome);
        inicio = inicio->prox;
        free(p);
    }
}

void aumentaIdade(){
    noptr *p;
    if(inicio == NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        p = inicio;
        while(p != NULL){
            p->idade = p->idade + 10;
            p = p->prox;
        }
    }
}

int main(){
    int op, idade;
    char nome[30];
    noptr *novo;
    inicio = NULL;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                novo = (noptr *)malloc(sizeof(noptr));
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                printf("\nDigite a idade: ");
                scanf("%d", &idade);
                insereLista(novo, nome, idade);
                break;
            case 2:
                mostrarTodos();
                break;
            case 3:
                removeLista();
                break;
            case 4:
                printf("\nDigite o nome: ");
                scanf("%s", nome);
                printf("\nDigite a idade: ");
                scanf("%d", &idade);
                insereLista(novo, nome, idade);
                break;
            case 5:
                printf("\nSaindo...");
                break;
            default:
                printf("\nOpcao invalida");
        }
    }while(op != 5);
    return 0;
}


