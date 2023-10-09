#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define lin 15
#define col 5

int main(){
    int matriz[lin][col];
    int vetor[lin*col] = {0};

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            matriz[i][j] = (rand()%199)-99;
        }
        printf("\n");
    }

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            int k = matriz[i][j];
            vetor[k]++;
        }
    }

    //armazena todos os elementos em 1 vetor, depois verifica quem se repete
    
    for (int i = 0; i < (lin*col); i++) {
        if (vetor[i] > 1) {
            printf("O elemento %d se repete %d vezes.\n", i, vetor[i]);
        }
    }

}   