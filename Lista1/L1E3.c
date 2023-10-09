#include<stdio.h>

int main(){
    int valor, custo;

    printf("Digite o valor de fabrica do carro: ");
    scanf("%d", &custo);
    valor = (custo*0.28)+(custo*0.45)+custo;
    printf("O valor do carro para o consumidor: R$%d", valor);
}