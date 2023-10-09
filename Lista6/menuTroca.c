#include <stdio.h>

typedef struct {
    int item[5];
    int inicio, fim;
} fila;

void menu() {
    printf("\n1 - Insere");
    printf("\n2 - Remove sem troca");
    printf("\n3 - Remove com troca");
    printf("\n4 - Mostrar Todos");
    printf("\n5 - Sair");
}

void inicia(fila *f) {
    f->inicio = f->fim = 0;
}

int enqueue(fila *f, int x) {
    if (f->fim == 5) {
        printf("\nFila cheia!");
        return 0;
    } else {
        f->item[f->fim] = x;
        f->fim++;
        return 1;
    }
}

int dequeueSemTroca(fila *f, int *x) {
    if (f->inicio == f->fim) {
        printf("\nFila vazia!");
        return 0;
    } else {
        *x = f->item[f->inicio];
        f->inicio++;
        return 1;
    }
}

int dequeueComTroca(fila *f, int *x) {
    if (f->inicio == f->fim) {
        printf("\nFila vazia!");
        return 0;
    } else {
        *x = f->item[f->inicio];
        for (int i = 0; i < f->fim - 1; i++) {
            f->item[i] = f->item[i + 1];
        }
        f->fim--;
        return 1;
    }
}

int main() {
    fila fila1;
    int retorno, valor, op;

    inicia(&fila1);

    do {
        menu();
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                printf("\nDigite o valor a ser inserido na fila: ");
                scanf("%d", &valor);
                retorno = enqueue(&fila1, valor);
                if (retorno == 1)
                    printf("\nDado inserido");
                else
                    printf("\nFila cheia");
                break;
            }
            case 2: {
                retorno = dequeueSemTroca(&fila1, &valor);

                if (retorno == 1)
                    printf("\nDado removido: %d", valor);
                else
                    printf("\nFila vazia");
                break;
            }
            case 3: {
                retorno = dequeueComTroca(&fila1, &valor);
                if (retorno == 1)
                    printf("\nDado removido: %d", valor);
                else
                    printf("\nFila vazia!");
                break;
            }
            case 4: {
                printf("\nElementos na fila:\n");
                for (int i = fila1.inicio; i < fila1.fim; i++) {
                    printf("%d ", fila1.item[i]);
                }
                break;
            }
            case 5: {
                printf("\nSaindo...");
                break;
            }
            default:
                printf("\nOpcao invalida!");
                break;
        }
    } while (op != 5);

    return 0;
}
