#include<stdio.h>

void primo(int num){

    for(int i = 2; i < num; i++){
        if(num % i == 0){
            printf("Nao eh primo! \n");
            return 0;
        }
        else{
            printf("Primo! \n");
            return 0;
        }
            
    }
}

int main(){
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    primo(num);


}