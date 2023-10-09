/*
Last in fist out - LIFO

primeira coisa a fazer é verificar se a pilha está cheia para empilhar 
e se a pilha está vazia para desempilhar

topo = implementador
push = empilhar
pop = desempilhar


*/
#include<stdio.h>
#define max 5

struct stack{
    int topo;
    int dados[max];
}pilha;

void push(int x){
    if(pilha.topo == max-1){
        printf("%s", "stack overflow");
    }
    else
        pilha.dados[(++pilha.topo)]=x;
}

int pop(){
    if(pilha.topo == max -1){
        printf("%s", "stack overflow");
        return (-1);
    }
    else    
        return pilha.dados[pilha.topo--];
}
void main(){
    pilha.topo = -1;
    
    push(4);
    push(2);
    push(5);
    printf("%d", pop());
    printf("\n");
    printf("%d", pop());
    printf("\n");
    push(10);
    printf("%d", pop());
    getchar();

}