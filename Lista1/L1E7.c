#include<stdio.h>

int main(){

    int i;
    float a, b, c;

    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    printf("1 - Ordem crescente\n2 - Ordem decrescente\n3 - Maior no meio\n");
    scanf("%d", &i);

    switch(i){
        case 1:{
            if(a > b && a > c){
                if(b> c)
                    printf("%.2f %.2f %.2f", a, b, c);
                else   
                    printf("%.2f %.2f %.2f", a, c, b);
            }

            else if(b > a && b > c){
                if(a > c)
                    printf("%.2f %.2f %.2f", b, a, c);
                else
                    printf("%.2f %.2f %.2f", b, c, a);
            }

            else if(c > a && c > b){
                if(a > b)
                    printf("%.2f %.2f %.2f", c, a, b);
                else
                    printf("%.2f %.2f %.2f", c, b, a);
            }
            break;
        }
        case 2:{
            if(a > b && a > c){
                if(b> c)
                    printf("%.2f %.2f %.2f", c, b, a);
                else   
                    printf("%.2f %.2f %.2f", b, c, a);
            }

            else if(b > a && b > c){
                if(a > c)
                    printf("%.2f %.2f %.2f", c, a, b);
                else
                    printf("%.2f %.2f %.2f", a, c, b);
            }

            else if(c > a && c > b){
                if(a > b)
                    printf("%.2f %.2f %.2f", b, a, c);
                else
                    printf("%.2f %.2f %.2f", a, b, c);
            }
            break;
        }
        case 3:{
            if(a>b && a>c){
                printf("%.2f %.2f %.2f", b, a, c);
            }

            else if(b>a && b>c){
                printf("%.2f %.2f %.2f", a, b, c);
            }

            else if(c>a && c>b){
                printf("%.2f %.2f %.2f", a, c, b);
            }
            break;
        }
        default:
            printf("Opcao invalida");
    }
}