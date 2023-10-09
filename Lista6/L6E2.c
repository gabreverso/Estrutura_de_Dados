#include<stdio.h>
#define max 5

typedef struct{
    int item[max];
    int inicio, fim;
}fila;

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
    int retorno, valor;

    inicia(&fila1);

    for(int i=0; i<max; i++){
        printf("\nDigite o valor a ser inserido na fila: ");
        scanf("%d", &valor);
        

        if(valor < 100){
            retorno = enqueue(&fila1, valor);
        }
        else
            retorno = dequeue(&fila1, &valor);

    }

    printf("Valores na fila: [ ");
    for (int i = fila1.inicio; i < fila1.fim; i++) {
        printf("%d ", fila1.item[i]);
   }
    printf("]\n");


}