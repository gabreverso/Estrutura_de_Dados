#include<stdio.h>

int soma(int mat[][2]){

    int i, j, somamat=0;

    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            if(mat[i][j] % 2 == 0){
                somamat += mat[i][j];
            }
        }
        
    }

    return somamat;
    
}

int main(){
    int mat[3][2], sum, i, j;

    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
        
    }
    
    sum = soma(mat);

    printf("\nSoma = %d", sum);
}