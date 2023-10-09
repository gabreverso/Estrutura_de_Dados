#include<stdio.h>

int contaPalavras(char frase[100]);

int main(){
    char frase[100];

    printf("\nDigite uma frase: ");
    fflush(stdin);
    gets(frase);

    printf("\nA frase tem %d palavras", contaPalavras(frase));
}

int contaPalavras(char frase[100]){
    int i, palavras=0;

    for(i=0; frase[i]!='\0'; i++){
        if(frase[i] == ' '){
            palavras++;
        }
    }

    return palavras+1;
}