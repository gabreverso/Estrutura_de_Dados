#include<stdio.h>

int main(){
    float total;
    int galinhas;
    
    printf("Total das galinhas:");
    scanf("%d", &galinhas);

    total = galinhas * (4 +(2*3.5));

    printf("Gasto Total: R$%.2f", total);
}