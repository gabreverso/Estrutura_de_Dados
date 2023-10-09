#include<stdio.h>

int main(){

    int vet1[10], vet2[10], vet3[20], j=0;

    for(int i = 0; i<10; i++){
        vet1[i] = rand()%100;
        printf("%d ", vet1[i] );
    }

    printf("\n");
    for(int i = 0; i<10; i++){
        vet2[i] = rand()%100;
        printf("%d ", vet2[i] );
    }

    printf("\n");
    for(int i=0; i<10; i++){
        
        vet3[j] = vet1[i];
        j++;
        vet3[j] = vet2[i];
        j++;
    }

    printf("\n");

    for(int i = 0; i<20; i++){
        printf("%d ", vet3[i]);
    }
}