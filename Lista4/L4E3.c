#include<stdio.h>

void jogo(int *x, int *y, int a, int b){

    if(a > b){
        *x = *x+3;
    }

    else if(b > a){
        *y = *y+3;
    }

    else{
        *x = *x + 1;
        *y += 1; 
    }
    
}

int main(){
    int timeA, timeB;
    int pontosA, pontosB;

    printf("\nTime A - Pontos:");
    scanf("%d", &timeA);

    printf("Time B - Pontos: ");
    scanf("%d", &timeB);

    printf("\nPontuacao no jogo: \n");
    printf("Time A: ");
    scanf("%d", &pontosA);

    printf("\nTime B: ");
    scanf("%d", &pontosB);


    jogo(&timeA, &timeB, pontosA, pontosB);

    printf("\n==Novo Placar==\n");
    printf("Time A = %d\nTime B = %d", timeA, timeB);
}