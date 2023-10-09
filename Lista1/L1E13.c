#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int j, vet[50], positivos[50];

    for(int i = 0; i < 50; i++){
        //scanf("%d", &vet[i]);
        vet[i] = (rand()%199)-99;
        printf("%d ", vet[i]);

        if(vet[i] > 0){
            positivos[j] = vet[i]; 
            j++;
        }

        
    }
    
    printf("\n\n");

    for(int k = 0; k < j; k++){
        printf("%d ", positivos[k]);
    }
}