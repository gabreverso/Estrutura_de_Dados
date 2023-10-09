#include<stdio.h>

int main(){
    int j=0, k=0, vet[8], vetP[8], vetN[8];

    for(int i = 0; i<8; i++){
        printf("[%d] ", i);
        scanf("%d", &vet[i]);

        if(vet[i]>0){
            vetP[j]=vet[i];
            j++;
        }
        else if(vet[i]<0){
            vetN[k]=vet[i];
            k++;
        } 

    }
    
    printf("\n");

    for(int i=0; i<j; i++){
        printf("%d ", vetP[i]);
    }
    printf("\n");
    
    for(int i = 0; i<k; i++){
        printf("%d ", vetN[i]);
    }
}