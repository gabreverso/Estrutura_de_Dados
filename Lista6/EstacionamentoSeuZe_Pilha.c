#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char placa[7];
    int deslocamento;
} Carro;

typedef struct {
    Carro carros[MAX];
    int topo;
} stack;

void menu() {
    printf("C - Chegada\n");
    printf("P - Partida\n");
    printf("S - Sair\n");
}

void inicializa(stack *pilha) {
    pilha->topo = -1;
}

void empilha(stack *pilha, Carro carro) {
    for (int i = 0; i <= pilha->topo; i++) {
        if (strcmp(pilha->carros[i].placa, carro.placa) == 0) {
            printf("Carro com placa %s ja esta no estacionamento!\n", carro.placa);
            return;
        }
    }

    if (pilha->topo == MAX - 1) {
        printf("Estacionamento cheio! Carro %s aguardando vaga!\n", carro.placa);
    } else {
        strcpy(pilha->carros[pilha->topo + 1].placa, carro.placa);
        pilha->carros[pilha->topo + 1].deslocamento = 0;
        pilha->topo++;
        printf("Carro %s estacionado!\n", carro.placa);
    }
}


void desempilha(stack *pilha, const char *placa) {
    if(pilha->topo == -1) {
        printf("Estacionamento vazio!\n");
        return;
    }
    else{
        for (int i = 0; i <= pilha->topo; i++) {
            if (strcmp(pilha->carros[i].placa, placa) == 0) {
                printf("Carro %s removido apos %d movimentos!\n", placa, pilha->carros[i].deslocamento);
                for (; i < pilha->topo; i++) {
                    strcpy(pilha->carros[i].placa, pilha->carros[i + 1].placa);
                    pilha->carros[i].deslocamento = pilha->carros[i + 1].deslocamento;
                }
                pilha->topo--;
                return;
            }
        }
        printf("Carro %s nao encontrado no estacionamento!\n", placa);
    }
}


int main() {
    stack pilha;
    Carro carro;
    char op, placa[7];

    inicializa(&pilha);

    do {
        menu();
        scanf(" %c", &op);
        switch (op) {
            case 'C': {
                printf("Digite a placa do carro: ");
                scanf("%s", placa);
                strcpy(carro.placa, placa);
                empilha(&pilha, carro);
                break;
            }

            case 'P': {
                printf("Digite a placa do carro: ");
                scanf("%s", placa);
                desempilha(&pilha, placa);
                break;
            }

            case 'S': {
                printf("Saindo...\n");
                break;
            }

            default:
                printf("Opção inválida!\n");
        }
    } while (op != 'S');

    return 0;
}
