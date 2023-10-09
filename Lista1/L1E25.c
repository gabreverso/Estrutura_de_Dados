#include<stdio.h>
#include<string.h>

int main(){
    char nome[5][50], temp[50];
    char endereco[5][150];
    char telefone[5][20];


    for(int i=0; i<5; i++){
        printf("\nNome: ");
        fflush(stdin);
        gets(nome[i]);
        printf("\nEndereco: ");
        fflush(stdin);
        gets(endereco[i]);
        printf("\nTelefone: ");
        fflush(stdin);
        gets(telefone[i]);
    }

    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(strcmp(nome[i], nome[j]) > 0){
                strcpy(temp, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], temp);
            }
        }
    }

    for(int i=0; i<5; i++){
        printf("\nNome: %s", nome[i]);
        printf("\nEndereco: %s", endereco[i]);
        printf("\nTelefone: %s\n", telefone[i]);
    }
}