#include<stdio.h>
#include<stdbool.h>

int valida(int senha){
    int permissao = 4531;

    if(senha == permissao)
        return true;

    else   
        return false;
}

int main(){
    int senha;

    printf("senha: ");
    scanf("%d", &senha);

    if(valida(senha) == true){
        printf("\nAcesso Permitido! \n");
    }

    else
        printf("\nAcesso Negado! \n");

    

}