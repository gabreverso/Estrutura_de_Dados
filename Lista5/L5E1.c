/*
Utilizando-se de STRUCT, leia 20 valores e empilhe-os na pilha1. Em seguida, desempilhe os
elementos da pilha1 verificando se o valor a ser desempilhado for menor que 100, empilhe-os em pilha2
senao empilhe em pilha3
*/
#include<stdio.h>
#define max 6

typedef struct{
    int topo;
    int dados[max];

}stack;

void push(int x, stack *pilha){
    if(pilha->topo == max-1){
        printf("Pilha cheia\n");
    }
    else{
        pilha->dados[(++pilha->topo)] = x;
    }
}

int pop(stack *pilha){
    if(pilha->topo == -1){
        printf("Pilha vazia\n");
        return (-1);
    }
    else{
        return (pilha->dados[pilha->topo--]);

    }
}

int main(){
    stack pilha1, pilha2, pilha3;
    pilha1.topo = -1;
    pilha2.topo = -1;
    pilha3.topo = -1;
    int aux;

    for(int i=0; i<max; i++){
        printf("Digite um valor: ");
        scanf("%d", &aux);
        push(aux, &pilha1);
    }

    for(int i=0; i<max; i++){
        aux = pop(&pilha1);
        if(aux < 100){
            push(aux, &pilha2);
        }
        else{
            push(aux, &pilha3);
        }
    }

    printf("\n");
    printf("Valores menores que 100: \n");

    for(int i=0; i<pilha2.topo; i++){
        printf("%d ", pilha2.dados[i]);
    }

    printf("\n");
    printf("Valores a partir de 100: \n");

    for(int i=0; i<pilha3.topo; i++){
        printf("%d ", pilha3.dados[i]);
    }
}