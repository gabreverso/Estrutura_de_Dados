#include<stdio.h>

int main(){
    char status;
    int idade, contC=0, contS=0, contV=0, contidade=0, contD=0, contT=0;
    float mediaV, porcD;

    do{
        printf("\nIdade: ");
        scanf("%d", &idade);

        if(idade>=0){
            printf("\nEstado Civil: ");
            fflush(stdin);
            scanf("%s", &status);

            if(status == 'S')
                contS++;

            else if(status == 'C')
                contC++;

            else if(status == 'V'){
                contV++;
                contidade= contidade + idade;
            }

            else if(status == 'D');
                contD++;
            
        }
    } while (idade>=0);

    contT = contC+contS+contD+contV;

    mediaV = contidade/contV;
    porcD = contT*(contV/100);

    printf("\nQuantidade de Casados: %d", contC);
    printf("\nQuantidade de Solteiros: %d", contS);
    printf("\nMedia da idade de Viuvos: %.2f", mediaV);
    printf("\nPorcentagem de Desquitados/Separados: %.2f", porcD);


    
}