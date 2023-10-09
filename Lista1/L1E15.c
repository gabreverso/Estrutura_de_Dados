#include<stdio.h>

int main(){

    int vet[6], neg[6], pos[6];
    int j, k;

    for(int i = 0; i<6 ; i++){
        printf("\n[%d]: ", i+1);
        scanf("%d", &vet[i]);
        if(vet[i] < 0 ){
            neg[j] = vet[i];
            j++;
        }
        
        else{
            pos[k] = vet[i];
            k++;
        }
    }

    printf("\nPositivos: \n");

    for(int i= 0; i<k; i++){
        printf("%d ", pos[i]);
    }
    printf("\nQuantidade: %d", k);

    printf("\nNegativos: \n");
    for(int i= 0; i<j; i++){
        printf("%d ", neg[i]);
    }
    printf("\nQuantidade: %d", j);
}