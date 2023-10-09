#include<stdio.h>

int ordem(int *x, int *y, int *z){
    int aux;

    if(*x < *y && *x < *z){
        if(*y < *z){
            //já ta em ordem
        }

        else{//xzy
            aux = *y;
            *y = *z;
            *z = aux;
        }
    }

    else if(*y < *x && *y < *z){//yxz
        if(*x < *z){
            aux = *x;
            *x = *y;
            *y = aux;
        }
        else{// yzx
            aux = *x;
            *x = *y;
            *y = *z;
            *z = aux;
        }
    }

    else if(*z < *x && *z < *y){
        if(*x < *y){//zxy
            aux = *y;
            *y = *x;
            *x = *z;
            *z = aux;
        }
        else{//zyx
            aux = *x;
            *x = *z;
            *z = aux;
        }
    }

}

int main(){

    int a, b, c;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);
    printf("Digite o segundo valor: ");
    scanf("%d", &b);
    printf("Digite o terceiro valor: ");
    scanf("%d", &c);

    ordem(&a, &b, &c);

    printf("Ordem Crescente: %d %d %d\n", a, b, c);
}