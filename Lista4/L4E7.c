#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void preencheVetor(int vet[], int tam, int min, int max){
    for(int i=0; i<tam; i++){
        vet[i] = min + rand() % (max - min + 1);
    }

    for(int i=0; i<tam; i++){
        printf("%d ", vet[i]);
    }
}

int MinMax(int vet[], int tam, int *min, int *max){
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

int main(){
    int tam, min, max;

    printf("Tamanho do vetor: ");
    scanf("%d", &tam);

    printf("\nValores Minimos e Maximos contidos no vetor: ");
    scanf("%d %d", &min, &max);

    int vet[tam];
    
    preencheVetor(vet, tam, min, max);

    MinMax(vet, tam, &min, &max);

    printf("\nValor minimo do vetor: %d", min);
    printf("\nValor maximo do vetor: %d", max);
}