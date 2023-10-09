#include<stdio.h>

int converte(int total, int *h, int *m, int *s){
    
    *h = total/360;
    *m = (total % 360)/60;
    *s = total - (*h*360) - (*m*60);
}

int main(){
    int TotalSegundos, horas, minutos, segundos;

    printf("\nQuantidade Total de Segundos: ");
    scanf("%d", &TotalSegundos);

    converte(TotalSegundos, &horas, &minutos, &segundos);

    printf("\nHorario: %d:%2.0d:%2.d \n", horas, minutos, segundos);
}