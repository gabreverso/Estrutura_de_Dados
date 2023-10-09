#include<stdio.h>

int main(){
    float gasolina, total, litros;

    printf("Digite o valor da gasolina: ");
    scanf("%f", &gasolina);

    printf("Digite o valor total:");
    scanf("%f", &total);
    litros = total / gasolina;
    printf("Quantidade de litros abastecidos: %.2f", litros);
}