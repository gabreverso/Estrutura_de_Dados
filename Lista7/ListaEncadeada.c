//lista encadeada
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

noptr *inicio;

void menu(){
    printf("\n1 - Inserir");
    printf("\n2 - Mostrar todos");
    printf("\n3 - Remover");
    printf("\n4 - Remover todos");
    printf("\n5 - Sair");
}

void insereLista(noptr *novo, int valor){
    noptr *p;
    novo->dados = valor;
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        p = inicio;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }
}

void removeLista(){
    noptr *p, *ant;
    if(inicio==NULL){
        printf("\nLista vazia");
        return;
    }
    else{
        p=inicio;
        ant=p;
        while(p->prox != NULL){
            ant = p;
            p = p->prox;
        }
        printf("\nRemovendo %d", p->dados);
        ant->prox = NULL;
        free(p);
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
                if(recebe != 0){
                    dados = (noptr*)malloc(sizeof(noptr));
                    if(dados == NULL){
                        printf("\nErro de alocacao");
                        return 1;
                    }
                    insereLista(dados, recebe);
                }
                break;
            }

            case 2:{
                noptr *p;
                if(inicio == NULL){
                    printf("\nLista vazia");
                    return;
                }
                p = inicio; 
                while(p != NULL){
                    printf("\n%d", p->dados);
                    p = p->prox;
                }
                printf("\n");
                break;
            }

            case 3:{
                removeLista();
                break;
            }

            case 4:{
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
    }while(op != 5);
    
}


