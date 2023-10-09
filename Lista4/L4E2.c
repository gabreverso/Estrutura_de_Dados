#include<stdio.h>
#include<math.h>

void menu(){
    printf("1 - Trocar numeros\n");
    printf("2 - Incrementar e decrementar numeros\n");
    printf("3 - Valores de X1 e X2\n");
    printf("0 - Sair\n");
}

void troca(float *x, float *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void incrementa(float *x, float *y){
    *x = *x + 1;
    *y = *y - 1;   
}

void bhaskara(float a, float b, float c, float *x1, float *x2){
    int delta = (b*b) - (4*a*c);
    *x1 = ( (-b) + (sqrt(delta)) ) / (2*a);
    *x2 = ( (-b) - (sqrt(delta)) ) / (2*a);

}

int main(){

    float a, b, c;
    int op;
    float x1, x2;

    do{
        menu();
        scanf("%d", &op);

        switch (op){
            case 1:
                printf("A = ");
                scanf("%f", &a);
                printf("B = ");
                scanf("%f", &b);
                troca(&a, &b);
                printf("\nA = %f\nB = %f\n\n", a, b);
                break;
            case 2:
                printf("A = ");
                scanf("%f", &a);
                printf("B = ");
                scanf("%f", &b);
                incrementa(&a, &b);
                printf("\nA = %f\nB = %f\n\n", a, b);
                break;
            
            case 3:
                printf("A = ");
                scanf("%f", &a);
                printf("B = ");
                scanf("%f", &b);
                printf("C = ");
                scanf("%f", &c);
                bhaskara(a, b, c, &x1, &x2);
                printf("\nX1 = %.2f\nX2 = %.2f\n\n", x1, x2);
                break;  

            case 0:
                printf("\ntchau...\n");
                break;

            default:
                printf("\nOpcao invalida!\n\n");
                break;
        }

    }while(op != 0);
    
}