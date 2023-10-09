#include<stdio.h>

typedef struct{
    int topo;
    int dados[10];
}stack;

void push(int x, stack *pilha){
    if(pilha->topo == 9){
        printf("Pilha cheia\n");
    }
    else{
        pilha->dados[(++pilha->topo)] = x;
    }
}

int pop(stack *pilha){
    if(pilha->topo == -1){
        printf("Pilha vazia\n");
        return '\0';
    }
    else{
        return (pilha->dados[pilha->topo--]);

    }
}

int main(){
    stack pilha1;
    pilha1.topo = -1;
    int aux, soma=0, cont=0;

    for(int i=0; i<10; i++){
        scanf("%d", &aux);
        push(aux, &pilha1);
    }

    while (cont < 4) {
        if (pilha1.topo >= 0){
            if(pilha1.dados[pilha1.topo] % 2 == 0) {
                soma += pop(&pilha1);
                cont++;
            }
            else {
                pop(&pilha1);
            }
        } 
        else {
            break;
        }
    }

    if(cont < 4)
        printf("Nao ha 4 numeros pares na pilha\n");

    else
        printf("Soma dos 4 primeiros numeros pares: %d\n", soma);
    
}