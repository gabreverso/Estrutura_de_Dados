#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dados;
    struct no *prox, *ant;
}noptr;

void menu(){
    printf("\n1 - Inserir dado");
    printf("\n2 - Mostrar lista");
    printf("\n3 - Sair\n");
}

void insertList(noptr **inicio, noptr *novo, int valor){
    if(inicio == NULL){
        novo->prox = NULL;
        inicio = novo;
    }

    else if(novo->dados < inicio->dados){
        novo->prox = inicio;
        inicio = novo;
    }

    else{
        p = inicio;
        ant = inicio;
        while(p->prox != NULL && p->dados < novo->dados){
            ant = p;
            p = p->prox;
        }

        if(p->dados > novo->dados){
            novo->prox = p;
            ant->prox = novo;
        }

        else{
            p->prox = novo;
            novo->prox = NULL;
        }
    }
}

void showList(noptr *inicio){
    noptr *p;
    p = inicio;
    while(p != NULL){
        printf("\n%d ", p->dados);
        p = p->prox;
    }
}

int main(){
    noptr *inicio = NULL;
    noptr *novo;
    int op, valor;
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:{
                novo = (noptr*)malloc(sizeof(noptr));
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                insertList(&inicio, novo, valor);
                break;
            }
                
            case 2:{
                showList(inicio);
                break;
            }
            
            case 3:{
                printf("\nSaindo...");
                break;
            }
        
            default:
                printf("\nOpcao invalida");
        }
    }while(op != 3);
    return 0;
}