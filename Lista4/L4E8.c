#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencheMat(int mat[][100], int lin, int col, int min, int max){
    for(int i=0; i<lin; i++){
        for(int j=0; j<col; j++){
            mat[i][j] = min + rand() % (max - min + 1);
        }
    }

    for(int i=0; i<lin; i++){
        for(int j=0; i<col; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

/*int MinMax(int vet[], int tam, int *min, int *max){
    int auxMin, auxMax=0;
    auxMin = vet[0];

    for(int i=0; i<tam; i++){
        if(auxMin > vet[i])
            auxMin = vet[i];

        if(auxMax<vet[i])
            auxMax = vet[i];
    }

    *min = auxMin;
    *max = auxMax;
}
*/
int main(){
    int lin, col, min, max;

    printf("Dimensoes da Matriz: ");
    scanf("%d %d", &lin, &col);

    printf("\nValores Minimos e Maximos contidos na matriz: ");
    scanf("%d %d", &min, &max);

    int mat[lin][col];
    
    preencheMat(mat, lin, col, min, max);

    //MinMax(mat, lin, col, &min, &max);

    printf("\nValor minimo da Matriz: %d", min);
    printf("\nValor maximo da Matriz: %d", max);
}