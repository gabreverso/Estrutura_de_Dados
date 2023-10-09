#include<stdio.h>

void verificaExp(char exp[], int *cont){
    for(int i=0; exp[i] != '\0'; i++){
        if(*cont < 0){
            printf("Expressao invalida!!!\n");
            return;
        }
        else if(exp[i] == '('){
            (*cont)++;
        }
        else if(exp[i] == ')'){
            (*cont)--;
        }
    }
    if(*cont != 0){
        printf("Expressao invalida!!!\n");
        return;
    }
    else{
        printf("Expressao aceita :)\n");
        return;
    }
}

int main(){
    char exp[50];
    int cont=0;

    fflush(stdin);
    gets(exp);

    verificaExp(exp, &cont);
    
}