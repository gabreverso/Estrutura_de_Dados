//lista encadeada
#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int dados;
    struct no *prox;
}noptr;

void menu(){
    printf("\n1 - Inserir Lista 1");
    printf("\n2 - Inserir Lista 2");
    printf("\n3 - Comparar tamanho");
    printf("\n4 - Sair\n");
}

void insereLista(noptr **inicio, noptr *novo, int valor){
    noptr *p;
    novo->dados = valor;
    novo->prox = NULL;
    if(inicio == NULL){
        inicio = novo;
    }
    else{
        p = inicio;
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
    }
}

void compara(noptr *inicio1, noptr *inicio2) {
    noptr *p1, *p2;
    p1 = inicio1;
    p2 = inicio2;
    int cont1 = 0, cont2 = 0;

    while (p1 != NULL) {
        cont1++;
        p1 = p1->prox;
    }

    while (p2 != NULL) {
        cont2++;
        p2 = p2->prox;
    }

    if (cont1 > cont2) {
        printf("\nLista 1 eh maior com %d elementos", cont1);
    } else if (cont2 > cont1) {
        printf("\nLista 2 eh maior com %d elementos", cont2);
    } else {
        printf("\nListas tem o mesmo tamanho com %d elementos cada", cont1);
    }
}



int main(){
    int recebe = -1;   
    noptr *inicio1 = NULL;
    noptr *inicio2 = NULL;
    noptr *dados1, *dados2;
    int op;

    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:{
                printf("\nLista 1: ");
                scanf("%d", &recebe);
                if(recebe != 0){
                    dados1 = (noptr*)malloc(sizeof(noptr));
                    if(dados1 == NULL){
                        printf("\nErro de alocacao");
                        return 1;
                    }
                    insereLista(inicio1, dados1, recebe);
                }
                break;
            }

            case 2:{
                printf("\nLista 2: ");
                scanf("%d", &recebe);
                if(recebe != 0){
                    dados2 = (noptr*)malloc(sizeof(noptr));
                    if(dados2 == NULL){
                        printf("\nErro de alocacao");
                        return 1;
                    }
                    insereLista(inicio2, dados2, recebe);
                }
                break;
            }

            case 3:{
                compara(inicio1, inicio2);

            }

            case 4:{
                printf("\nSaindo...");
                break;
            }

            default:{
                printf("\nOpcao invalida");
                break;
            }
        }   
    }while(op != 4);

}
