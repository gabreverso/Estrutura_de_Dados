#include<stdio.h>
#define max 5 

typedef struct{
    int item[max];
    int inicio, fim;
}fila;

//funcao que inicia a fila

void inicia(fila *f){
    f->inicio = f->fim = 0;
}

//funcao para inserir dados na fila

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

//funcao para remover dados da fila

int denqueue(fila *f, int *x){
    if(f->inicio == f->fim){
        printf("\nFila vazia!");
        return 0;
    }
    else{
        *x = f->item[f->inicio];
        for(int i=0; i<max-1; i++){
            f->item[i] = f->item[i+1];
        }
        f->fim--;
        return 1;
    }
}

int main(){
    fila f1;
    int i, retorno, valor;
    inicia(&f1);

    for(i=0; i<max; i++){
        printf("\nDigite o valor a ser inserido na fila: ");
        scanf("%d", &valor);
        retorno = enqueue(&f1, valor);
        if(retorno == 1)
            printf("\nDado inserido");
        else
            printf("\nfila cheia");
    }

    for(i=0; i<max; i++){
        retorno = denqueue(&f1, &valor);
        if(retorno == 1)
            printf("\nDado removido: %d", valor);
        else
            printf("\nFila vazia");
    }
    getch();
}