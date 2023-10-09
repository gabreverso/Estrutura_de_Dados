#include<stdio.h>
#define lin 3
#define col 3

int main(){
    int matriz[lin][col];
    int cont=0;

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > 30){
                cont++;
                matriz[i][j] = 0;
            }
        }
    }

    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

}