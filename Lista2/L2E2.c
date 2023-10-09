#include<stdio.h>
#define dist 0.28
#define imposto 0.45


float valorFinal(float custoFab){

    float preco, imp1, imp2;

    imp1 = custoFab * dist;
    imp2 = custoFab * imposto;
    preco = custoFab+imp1+imp2;

    return preco;
    
}

int main(){

    float custoFab, valorF;

    printf("Valor de fabrica: ");
    scanf("%f", &custoFab);

    
    valorF = valorFinal(custoFab);

    printf("Valor final do carro: R$ %.2f", valorF);
}

