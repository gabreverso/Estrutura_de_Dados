#include<stdio.h>
#define max 5

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
    stack pilha1;
    pilha1.topo = -1;
    int aux;

    while(pilha1.topo < max-1 || pilha1.topo == -1){
        printf("Digite um valor: ");
        scanf("%d", &aux);
        
        if(aux < 100)
            push(aux, &pilha1);

        else{
            printf("\ndesempilha %d\n", pop(&pilha1));
        }
    }

}