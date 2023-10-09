#include<stdio.h>
#define max 10

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
    int retorno, valor, cont=0, soma=0;
    
    inicia(&fila1);

    for(int i=0; i<max; i++){
        printf("\nInserir: ");
        scanf("%d", &valor);
        
        retorno = enqueue(&fila1, valor);
        if(retorno == 0){
            printf("\nFila cheia!");
        }
    }
    int temp = 0;
    while(cont < 4){
        if(fila1.inicio != fila1.fim){
            if(fila1.item[fila1.inicio] % 2 == 0){
                temp = fila1.item[fila1.inicio];
                soma += temp;
                dequeue(&fila1, &valor);
                cont++;
            }
            else
                dequeue(&fila1, &valor);
        }
        else{
            printf("\nFila vazia!");
            break;
        }
    }

    if(cont < 4)
        printf("\nNao ha 4 numeros pares na fila!");
    else
        printf("\nSoma dos 4 primeiros numeros pares: %d", soma);
}