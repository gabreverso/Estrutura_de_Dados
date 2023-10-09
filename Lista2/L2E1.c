#include<stdio.h>

int main(){

    int dias, meses, anos, id;

    printf("\ninforme a sua idade em dias meses e anos no formato AAAA MM DD: ");
    scanf("%d %d %d", &anos, &meses, &dias);

    id = idade(dias, meses, anos);

    printf("idade em dias  = %d", id);

}

int idade(int dias, int meses, int anos){

    int id_dias;

    id_dias = (dias) + (meses * 30) + (anos * 360);

    return id_dias;
}