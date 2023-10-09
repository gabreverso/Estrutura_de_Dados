#include<stdio.h>

int main(){

    float merc;
    char cod;
    float totalL=0, totalA=0, totalH=0, total=0;

    do{
        printf("\nValor da Mercadoria: ");
        scanf("%f", &merc);

        if(merc > 0){
            printf("\nCodigo da Mercadoria: ");
            fflush(stdin);
            scanf("%c", &cod);

            total += merc;

            if(cod == 'L')
                totalL += merc;
            
            else if(cod == 'A')
                totalA += merc;

            else if(cod == 'H')
                totalH += merc;

        }

        
        
    }while (merc != 0);
    
    printf("\nTotal em Limpeza: R$%.2f", totalL);
    printf("\nTotal em Alimentacao: R$%.2f", totalA);
    printf("\nTotal em Higiene: R$%.2f", totalH);
    printf("\ntotal Vendido: R$%.2f", total);
}