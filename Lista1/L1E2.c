#include<stdio.h>

int main(){
    int dias, meses, anos;

    printf("informe a sua idade em dias: ");
    scanf("%d", &dias);

    anos = dias / 360;
    meses = (dias % 360) /30;
    int dias_restantes = dias - (anos*360) - (meses* 30);

    printf("idade em anos: %d anos, %d meses e %d dias", anos, meses, dias_restantes);

}