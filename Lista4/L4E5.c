#include<stdio.h>

int data(int d, int m, int a){
    
    if((d > 31 || d < 1) && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)){
        printf("Dia invalido");
        return 0;
    }

    else if((d > 30 || d < 1) && (m == 4 || m == 6 || m == 9 || m == 11)){
        printf("Dia invalido");
        return 0;
    }

    else if((d > 28) || (d < 1 && m == 2)){
        printf("Dia invalido");
        return 0;
    }

    else if(m > 12 || m < 1){
        printf("Mes invalido");
        return 0;
    }

    else if(a < 1){
        printf("Ano invalido");
        return 0;
    }

    else{
        return 1;
    }

}

void formataData(int d, int m, int a){
    if(m == 1){
        printf("%d de janeiro de %d", d, a);
    }

    else if(m == 2){
        printf("%d de fevereiro de %d", d, a);
    }

    else if(m == 3){
        printf("%d de marco de %d", d, a);
    }

    else if(m == 4){
        printf("%d de abril de %d", d, a);
    }

    else if(m == 5){
        printf("%d de maio de %d", d, a);
    }

    else if(m == 6){
        printf("%d de junho de %d", d, a);
    }

    else if(m == 7){
        printf("%d de julho de %d", d, a);
    }

    else if(m == 8){
        printf("%d de agosto de %d", d, a);
    }

    else if(m == 9){
        printf("%d de setembro de %d", d, a);
    }

    else if(m == 10){
        printf("%d de outubro de %d", d, a);
    }

    else if(m == 11){
        printf("%d de novembro de %d", d, a);
    }

    else if(m==12){
        printf("%d de dezembro de %d", d, a);
    }
}

int main(){

    int dia, mes, ano;

    printf("Dia, mes e ano: DD MM AAAA: ");
    scanf("%d %d %d", &dia, &mes, &ano);
  
    if(data(dia, mes, ano)){
        formataData(dia, mes, ano);
    }
}