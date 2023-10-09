#include<stdio.h>

int main(){
    int vet[10], soma=0, neg=0;

    for(int i = 0; i<10; i++){
        scanf("%d", &vet[i]);

        if(vet[i]>=0){
            soma = soma+vet[i];
        }
        else   
            neg++;
    }

    printf("\nSoma positivos: %d", soma);
    printf("\nQuantidade negativos: %d", neg);
}