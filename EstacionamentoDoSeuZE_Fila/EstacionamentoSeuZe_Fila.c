#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char placa[7]; 
    int deslocamento;
    int movimentos;
} Carro;

typedef struct {
    Carro carros[MAX];
    int frente, tras, quantidade;
} Fila;

void inicializa(Fila *fila) {
    fila->frente = 0;
    fila->tras = -1;
    fila->quantidade = 0;
}

void enqueue(Fila *fila, Carro carro) {
    if (fila->quantidade == MAX) {
        printf("Estacionamento cheio! Carro %s aguardando vaga!\n", carro.placa);
    } else {
        fila->tras = (fila->tras + 1) % MAX;
        strcpy(fila->carros[fila->tras].placa, carro.placa);
        fila->carros[fila->tras].deslocamento = 0;
        fila->quantidade++;
        printf("Carro %s estacionado!\n", carro.placa);
    }
}

void denqueue(Fila *fila, const char *placa) {
    if (fila->quantidade == 0) {
        printf("Estacionamento vazio!\n");
        return;
    }

    for (int i = 0; i < fila->quantidade; i++) {
        int index = (fila->frente + i) % MAX;
        if (strcmp(fila->carros[index].placa, placa) == 0) {
            printf("Carro %s removido apos %d movimentos\n", placa, fila->carros[index].deslocamento);
            fila->frente = (fila->frente + 1) % MAX;
            fila->quantidade--;
            return;
        }
    }

    printf("Carro %s nao encontrado no estacionamento!\n", placa);
}

int main() {
    Fila fila;
    Carro carro;
    char op, placa[7];

    inicializa(&fila);

    do {
        printf("C - Chegada\n");
        printf("P - Partida\n");
        printf("S - Sair\n");
        scanf(" %c", &op);

        switch (op) {
            case 'C': {
                printf("Digite a placa do carro: ");
                scanf("%s", placa);
                strcpy(carro.placa, placa);
                enqueue(&fila, carro);
                break;
            }

            case 'P': {
                printf("Digite a placa do carro: ");
                scanf("%s", placa);
                denqueue(&fila, placa);
                break;
            }

            case 'S': {
                printf("Saindo...\n");
                break;
            }

            default:
                printf("Opção invalida!\n");
        }
    } while (op != 'S');

    return 0;
}

