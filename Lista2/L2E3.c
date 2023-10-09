#include<stdio.h>

int soma(int vetor[]){

    int somaVetor=0;

    for(int i=0; i<8; i++){
        somaVetor += vetor[i];
    }

    return somaVetor;
    
}

int main(){

    int vetor[8], sum, i;

    for(i=0; i<8; i++){
        printf("[%d] = ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    sum = soma(vetor);

    printf("\nSoma = %d", sum);
}