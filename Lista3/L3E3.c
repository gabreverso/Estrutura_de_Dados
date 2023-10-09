#include<stdio.h>

int invest(int tipo, float valor){
    float rend;

    if(tipo == 1){
        rend = (valor * 0.03)+valor;
        return rend;
    }

    else if(tipo == 2){
        rend = (valor * 0.04)+valor;
        return rend;
    }
}

int main(){

    int tipo;
    float valor, rendimento;

    printf("Tipo de investimento: \n1 - Poupanca \n2 - Renda Fixa \n");
    scanf("%d", &tipo);

    printf("Valor investido: ");
    scanf("%f", &valor);

    rendimento = invest(tipo, valor);

    printf("Rendimento = R$%.2f", rendimento);


}