#include<stdio.h>

int situacao(float trab, float avaliacao, float exame){
    float nota;

    nota = ((trab*2) + (avaliacao*3) + (exame*5))/10;

    return nota;

}

int main(){

    float nota, trab, avaliacao, exame;

    printf("Nota do Trabalho: ");
    scanf("%f", &trab);

    printf("Nota da Avaliacao ");
    scanf("%f", &avaliacao);

    printf("Nota do Exame: ");
    scanf("%f", &exame);

    nota = situacao(trab, avaliacao, exame);

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