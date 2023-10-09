#include<stdio.h>

typedef struct{
    int topo;
    char dados[100];

}stack;

void menu(){
    printf("\n1 - Inserir\n");
    printf("2 - Remover\n");
    printf("3 - Veridicar Topo da pilha\n");
    printf("4 - Mostrar todos os elementos da pilha\n");
    printf("5 - Sair\n");
}

void push(int x, stack *pilha){
    if(pilha->topo == 99){
        printf("Pilha cheia\n");
    }
    else{
        pilha->dados[(++pilha->topo)] = x;
    }
}

char pop(stack *pilha){
    if(pilha->topo == -1){
        printf("Pilha vazia\n");
        return '\0';
    }
    else{
        return (pilha->dados[pilha->topo--]);

    }
}   

int main(){
    stack pilha;
    pilha.topo = -1;
    int aux, op;

    do{
        menu();
        printf("Digite uma opcao: ");
        scanf("%d", &op);

        switch(op){
            case 1:{
                printf("Digite um valor: ");
                scanf("%d", &aux);
                push(aux, &pilha);
                break;
            }
            case 2:{
                printf("\n%d\n", pop(&pilha));
                break;
            }
            
            case 3:{
                printf("\n%d\n", pilha.dados[pilha.topo]);
                break;
            }

            case 4:{
                for(int i=0; i<=pilha.topo; i++){
                    printf("%d ", pilha.dados[i]);
                }
                printf("\n");
                break;
            }

            case 5:{
                printf("Saindo...\n");
                break;
            }
        
            default:{
                printf("Opcao invalida\n");
                break;
            }
        }
    }while(op != 5);

    return 0;
}