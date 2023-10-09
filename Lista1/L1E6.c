#include<stdio.h>

int main(){
    float trabalho, prova, exame, nota;

    printf("Nota do trabalho: ");
    scanf("%f", &trabalho);
    
    printf("Nota da prova: ");
    scanf("%f", &prova);

    printf("Nota do exame final: ");
    scanf("%f", &exame);

    nota = ((trabalho*2)+(exame*3)+(prova*5))/10;

    if(nota > 8)
        printf("Nota = %.2f\nConceito A", nota);

    else if(nota > 7)
        printf("Nota = %.2f\nConceito B", nota);

    else if(nota > 6)
        printf("Nota = %.2f\nConceito C", nota);

    else if(nota > 5)
        printf("Nota = %.2f\nConceito D", nota);

    else
        printf("Nota = %.2f\nConceito E", nota);

        
}