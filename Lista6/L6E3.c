#include<stdio.h>
#define max 5

typedef struct{
    int item[max];
    int inicio, fim;
}fila;

void menu(){
    printf("\n1 - Inserir na fila");
    printf("\n2 - Retirar da fila");
    printf("\n3 - Verifia");
    printf("\n4 - Sair");
    printf("\nDigite a opcao desejada: ");
}

void inicia(fila *f){
    f->inicio = f->fim = 0;
}

int enqueue(fila *f, int x){
    if(f->fim == max){
        printf("\nFila cheia!");
        return 0;
    }
    else{
        f->item[f->fim] = x;
        f->fim++;
        return 1;
    }
}

int dequeue(fila *f, int *x) {
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

int main(){
    fila fila1;
    int retorno, valor, op;

    inicia(&fila1);

    do{
        menu();
        scanf("%d", &op);
        switch(op){
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
            retorno = dequeue(&fila1, &valor);
            if (retorno == 1)
                printf("\nDado removido: %d", valor);
            else
                printf("\nFila vazia!");
            break;
        }

        case 3: {
            printf("\nValor na saida: [ ");
            printf("%d ", fila1.item[fila1.inicio]);
            printf("]\n");
            break;
        }

        case 4: {
            printf("\nSaindo...");
            break;
        }
        
        default:
            break;
        }
    }while(op != 4);

}