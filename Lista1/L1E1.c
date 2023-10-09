#include<stdio.h>
#include<stdlib.h>

int main (){

    int dias, meses, anos;

    printf("Digite sua idade em anos, meses e dias: ");
    scanf("%d %d %d", &anos, &meses, &dias);

    printf("Sua idade em dias: %d", (anos * 360) + (meses * 30) + dias);

}