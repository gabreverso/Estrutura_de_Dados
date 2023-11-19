#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dados;
    struct no *prox, *ant;
} noptr;

void menu() {
    printf("\n1 - Inserir dado");
    printf("\n2 - Mostrar lista");
    printf("\n3 - Remover dado");
    printf("\n4 - Sair\n");
}

void insertList(noptr **inicio, int valor) {
    noptr *novo = (noptr*)malloc(sizeof(noptr));
    novo->dados = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL || valor < (*inicio)->dados) {
        novo->prox = *inicio;
        if (*inicio != NULL) {
            (*inicio)->ant = novo;
        }
        *inicio = novo;
    } else {
        noptr *p = *inicio;
        while (p->prox != NULL && p->prox->dados < valor) {
            p = p->prox;
        }
        novo->prox = p->prox;
        if (p->prox != NULL) {
            p->prox->ant = novo;
        }
        p->prox = novo;
        novo->ant = p;
    }
}

void showList(noptr *inicio) {
    noptr *p = inicio;
    printf("\n[ ");
    while (p != NULL) {
        printf("%d ", p->dados);
        p = p->prox;
    }
    printf("]\n");
}

int removeList(noptr **inicio, int valor) {
    if (*inicio == NULL) {
        return 0;
    }
    noptr *p = *inicio;
    while (p != NULL && p->dados != valor) {
        p = p->prox;
    }
    if (p == NULL) {
        return 0;
    }
    if (p->ant == NULL) {
        *inicio = p->prox;
    } else {
        p->ant->prox = p->prox;
    }
    if (p->prox != NULL) {
        p->prox->ant = p->ant;
    }
    
    free(p);
    return 1;
}

int main() {
    noptr *inicio = NULL;
    int op, valor;
    do {
        menu();
        scanf("%d", &op);
        switch(op) {
            case 1: {
                printf("\nDigite o valor: ");
                scanf("%d", &valor);
                insertList(&inicio, valor);
                break;
            }
            case 2: {
                showList(inicio);
                break;
            }

            case 3:{
                printf("\nQual numero deseja remover? ");
                scanf("%d", &valor);
                if (removeList(&inicio, valor)) {
                    printf("\n%d removido com sucesso", valor);
                } else {
                    printf("\nNao encontrado");
                }
            }
            case 4: {
                printf("\nSaindo...");
                break;
            }
            default:
                printf("\nOpcao invalida");
        }
    } while(op != 4);

    noptr *p = inicio;
    while (p != NULL) {
        noptr *temp = p;
        p = p->prox;
        free(temp);
    }

    return 0;
}
