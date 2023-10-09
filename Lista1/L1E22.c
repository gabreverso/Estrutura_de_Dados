#include<stdio.h>
#define lin 3
#define col 3

int main(){
    int matriz[lin][col];
    int matrizRes[lin][col];
    int vetor[lin] = {0};

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &matriz[i][j]);
            vetor[i] += matriz[i][j];
        }
    }


    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            matrizRes[i][j] = matriz[i][j] * vetor[i];
        }
    }

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrizRes[i][j]);
        }
        printf("\n");
    }
}