#include<stdio.h>
#define max 10

int main(){

    int vet[max];

    for(int i=0; i<max; i++){
        printf("[%d]: ", i+1);
        scanf("%d", &vet[i]);
    }

    for(int i=0; i<max; i++){
        printf("%d ", vet[i]);
        
    }
}