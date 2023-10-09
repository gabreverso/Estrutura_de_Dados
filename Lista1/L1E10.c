#include<stdio.h>

int main(){

    int cod[5], veic[5], acid[5];
    int maior=0, menor=0, totalV=0, totalAcid=0, contAcid=0;
    float mediaV, mediaA;

    for(int i=0; i<5; i++){
        printf("Codigo da cidade %d: ", i+1);
        scanf("%d", &cod[i]);

        printf("\nNumero de Veiculos: ");
        scanf("%d", &veic[i]);

        printf("\nNumero de Acidentes: ");
        scanf("%d", &acid[i]);

        maior = 0;
        menor = acid[0];
        totalV = totalV+veic[i];

        if(acid[i] > maior)
            maior = acid[i];

        if(acid[i] < menor)
            menor = acid[i];

        if(veic[i] <2000){
            totalAcid = totalAcid+acid[i];
            contAcid++;
        }
    }

    mediaV = totalV/5;
    mediaA = totalAcid/contAcid;

    printf("\n\nMaior indice de Acidentes:\n%d acidentes de transito.", maior);
    printf("\nMenor indice de Acidentes:\n%d acidentes de transito.", menor);
    printf("\nMedia de Veiculos: %.2f", mediaV);
    printf("\nMedia de Acidentes: %.2f", mediaA);
}