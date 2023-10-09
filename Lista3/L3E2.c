#include<stdio.h>

int higher(int a, int b){
    if(a>b){
        return a;
    }

    else
        return b;
}

int main(){
    int a, b, maior;

    scanf("%d %d", &a, &b);

    maior = higher(a, b);

    printf("Maior: %d", maior);
    
}