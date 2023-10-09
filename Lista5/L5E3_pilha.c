#include<stdio.h>


typedef struct{
    int topo;
    char exp[50];
}stack;

void push(char x, stack *pilha){
    if(pilha->topo == 49){
        printf("Pilha cheia\n");
    }
    else{
        pilha->exp[(++pilha->topo)] = x;
    }
}

int pop(stack *pilha){
    if(pilha->topo == -1){
        printf("\nExpressao invalida!!!\n");
    }
    else{
        return pilha->exp[(pilha->topo)--];
    }
}

int main(){
    stack expressao, parentese;
    expressao.topo = -1;
    parentese.topo = -1;

    fflush(stdin);
    gets(expressao.exp);

    for(int i=0; expressao.exp[i] != 0; i++){
        push(expressao.exp[i], &expressao);
    }

    for(int i= 0; i< expressao.exp[i] !=0; i++){
        if(expressao.exp[i] == '('){
            push(expressao.exp[i], &parentese);
        }
        else if(expressao.exp[i] == ')'){
            pop(&parentese);
        }
    }

    if(parentese.topo == -1){
        printf("\nExpressao valida!!!\n");
    }
    else{
        printf("\nExpressao invalida!!!\n");
    }
}