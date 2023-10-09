#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void dobraPalavras(char frase1[], char frase2[], int *cont){
    
    for(int i = 0; i < strlen(frase1); i++){
        if(frase1[i] != ' '){
            while(frase1[i] != ' '){
                strcmp(frase1, frase2);
            }

            if(strcmp){
                *cont++;
            }
        }
    }

}

int main(){
    char frase[100], palavra[20];
    int cont = 0;

    printf("frase: ");
    fflush(stdin);
    gets(frase);

    printf("\npalavra: ");
    fflush(stdin);
    gets(palavra);

    dobraPalavras(frase, palavra, &cont);

    printf("%d", cont);

}