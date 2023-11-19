#include<stdio.h>
#define MAX 5 

typedef struct{
    int item[MAX];
    int inicio, fim;
}fila;

void menu(){
    printf("\n1 - Inserir na fila");
    printf("\n2 - Retirar da fila");
    printf("\n3 - Verifia");
    printf("\n4 - Sair");
    printf("\nDigite a opcao desejada: ");
}

//funcao que inicia a fila
void inicia(fila *f){
    f->inicio = f->fim = 0;
}

//funcao para inserir dados na fila

int enqueue(fila *f, int x){
    if(f->fim == f->inicio-1 || (f->fim == MAX && f->inicio == 0)){
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
        f->inicio++;
        if(f->inicio == MAX)
            f->inicio = 0;

        return 1;
    }
}

int main(void){
    fila fila1;
    int retorno, valor, op;
    inicia(&fila1);

    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:{
                scanf("%d", &valor);
                retorno = enqueue(&fila1, valor);
                if(retorno == 1)
                    printf("\nDado inserido");
                else
                    printf("\nfila cheia");
                break;
            }

            case 2:{
                retorno = denqueue(&fila1, &valor);
                if(retorno == 1)
                    printf("\nDado removido: %d", valor);
                else
                    printf("\nFila vazia");
                break;
            }

            case 3:{
                if(fila1.inicio == fila1.fim)
                    printf("\nFila vazia");
                else{
                    printf("\nElementos na fila: [ ");
                    for(int i=fila1.inicio; i<fila1.fim; i++){
                        printf("%d ", fila1.item[i]);
                    }
                    printf(" ]");
                }
                break;
            }
            case 4:{
                printf("\nSaindo...");
                break;
            }

            default:{
                printf("\nOpcao invalida!");
                break;
            }
        }
    }while(op!=4);
}