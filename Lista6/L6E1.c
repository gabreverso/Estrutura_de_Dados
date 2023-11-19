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

int denqueue(fila *f, int *x) {
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
    fila fila1, fila2, fila3;
    int retorno, valor;

    inicia(&fila1);
    inicia(&fila2);
    inicia(&fila3);

    for(int i=0; i<max; i++){
        printf("\nDigite o valor a ser inserido na fila: ");
        scanf("%d", &valor);
        retorno = enqueue(&fila1, valor);
   
        if(retorno == 0)
            printf("\nfila cheia");
    }

    for(int i=0; i<max; i++){
        retorno = denqueue(&fila1, &valor);

        if(retorno == 1){
            if(valor <100)
                enqueue(&fila2, valor);
            else
                enqueue(&fila3, valor);
        }

        else
            printf("\nFila vazia");
    }

    printf("\nValores menores que 100: [ ");
    for (int i = fila2.inicio; i < fila2.fim; i++) {
        printf("%d ", fila2.item[i]);
   }
   printf("]\n");

    printf("Valores maiores que 100: [ ");
    for (int i = fila3.inicio; i < fila3.fim; i++) {
        printf("%d ", fila3.item[i]);
   }
    printf("]\n");
}