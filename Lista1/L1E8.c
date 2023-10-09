#include<stdio.h>

int main(){
    int cod, pais;
    float peso, preco, produto, imposto;


    do
    {
        printf("Codigo do produto comprado: ");
        scanf("%d", &cod);

        printf("\nPeso do produto em quilos");
        scanf("%f", &peso);

        if(cod >= 1 && cod <=4){
            preco = (peso*1000) *10;

        }
        else if(cod <=7){
            preco = (peso*1000) *25;
        }

        else if(cod<=10){
            preco = (peso*1000) *35;
        }

        printf("\nCodigo do pais de origem: ");
        scanf("%d", &pais);

        switch(pais){
            case 1:
                imposto = 0;
                produto = preco+imposto;

                break;

            case 2:
                imposto = preco*0.25;
                produto = preco + imposto;

                break;

            case 3:
                imposto = preco*0.35;
                produto = preco + imposto;

                break;

        }

        printf("\nPeso em gramas = %f", peso*1000);
        printf("\nPreco total do produto comprado: R$%.2f", produto);
        printf("\nImposto = R$%.2f", imposto);
    } while(cod>0 && cod<=10);

    

}